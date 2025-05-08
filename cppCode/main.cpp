#include "payment_client.h"
#include <iostream>

int main() {
    // 初始化程序
    if (!initialize()) {
        std::cerr << "初始化失败，程序退出" << std::endl;
        return 1;
    }
    
    // 显示主菜单并处理用户输入
    showMenu();
    
    // 清理资源
    cleanup();
    
    return 0;
}