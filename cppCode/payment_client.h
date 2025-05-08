#ifndef PAYMENT_CLIENT_H
#define PAYMENT_CLIENT_H

#include <string>

/**
 * 回调函数，用于接收HTTP响应数据
 * @param contents 接收到的数据
 * @param size 数据块大小
 * @param nmemb 数据块数量
 * @param s 存储响应的字符串指针
 * @return 处理的字节数
 */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);

/**
 * 发送支付请求
 * @param paymentCode 支付代码(1=成功，0=失败)
 * @return 请求是否成功发送
 */
bool sendPaymentRequest(int paymentCode);

/**
 * 显示主菜单并处理用户输入
 */
void showMenu();

/**
 * 初始化程序
 * @return 初始化是否成功
 */
bool initialize();

/**
 * 清理资源
 */
void cleanup();

#endif // PAYMENT_CLIENT_H