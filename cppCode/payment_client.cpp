#include "payment_client.h"
#include <iostream>
#include <curl/curl.h>
#include <string>

// 服务器地址和端口配置，可以根据实际情况修改
const std::string SERVER_URL = "http://8.138.134.50:5000/payment"; // 使用Docker容器的实际IP地址

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
        return newLength;
    } catch(std::bad_alloc& e) {
        // 处理内存分配失败
        std::cerr << "内存分配失败: " << e.what() << std::endl;
        return 0;
    }
}

bool sendPaymentRequest(int paymentCode) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    
    // 初始化libcurl会话
    curl = curl_easy_init();
    if(!curl) {
        std::cerr << "无法初始化CURL" << std::endl;
        return false;
    }
    
    // 设置请求URL - 使用配置的SERVER_URL
    curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL.c_str());
    
    // 设置为POST请求
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    
    // 准备请求体数据
    std::string jsonData = "{\"code\": " + std::to_string(paymentCode) + "}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
    
    // 设置请求头
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
    // 设置写回调函数
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    
    // 设置超时时间（单位：秒）
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
    
    // 执行请求
    res = curl_easy_perform(curl);
    
    // 检查请求是否成功
    if(res != CURLE_OK) {
        std::cerr << "curl_easy_perform() 失败: " << curl_easy_strerror(res) << std::endl;
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        return false;
    }
    
    // 获取HTTP状态码
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    
    // 输出响应数据
    std::cout << "HTTP状态码: " << http_code << std::endl;
    std::cout << "服务器响应: " << readBuffer << std::endl;
    
    // 清理资源
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return true;
}

void showMenu() {
    int choice;
    bool running = true;
    
    while(running) {
        std::cout << "\n=============== 支付测试客户端 ===============" << std::endl;
        std::cout << "当前连接服务器: " << SERVER_URL << std::endl;
        std::cout << "1. 测试支付成功" << std::endl;
        std::cout << "2. 测试支付失败" << std::endl;
        std::cout << "3. 修改服务器地址" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "请输入选择 (1-4): ";
        std::cin >> choice;
        
        // 处理错误输入
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "无效输入，请输入数字。" << std::endl;
            continue;
        }
        
        switch(choice) {
            case 1:
                std::cout << "发送支付成功请求 (代码 1)..." << std::endl;
                sendPaymentRequest(1);
                break;
            case 2:
                std::cout << "发送支付失败请求 (代码 0)..." << std::endl;
                sendPaymentRequest(0);
                break;
            case 3: {
                std::string newUrl;
                std::cout << "请输入新的服务器地址 (例如 http://172.19.0.2:5000/payment): ";
                std::cin.ignore(); // 清除之前的输入缓冲
                std::getline(std::cin, newUrl);
                
                if (!newUrl.empty()) {
                    const_cast<std::string&>(SERVER_URL) = newUrl; // 修改SERVER_URL
                    std::cout << "服务器地址已更新为: " << SERVER_URL << std::endl;
                } else {
                    std::cout << "地址未变更" << std::endl;
                }
                break;
            }
            case 4:
                running = false;
                std::cout << "程序退出" << std::endl;
                break;
            default:
                std::cout << "无效选择，请重试" << std::endl;
        }
    }
}

bool initialize() {
    // 初始化libcurl
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if(res != CURLE_OK) {
        std::cerr << "无法初始化curl: " << curl_easy_strerror(res) << std::endl;
        return false;
    }
    
    std::cout << "支付测试客户端已启动" << std::endl;
    std::cout << "连接到服务器: " << SERVER_URL << std::endl;
    return true;
}

void cleanup() {
    // 清理全局libcurl资源
    curl_global_cleanup();
}