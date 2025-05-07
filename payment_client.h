#ifndef PAYMENT_CLIENT_H
#define PAYMENT_CLIENT_H

#include <QString>
#include <QNetworkReply>

// 声明服务器URL为外部变量，以便在其他文件中访问
extern QString SERVER_URL;

/**
 * 发送支付请求
 * @param paymentCode 支付代码(1=成功，0=失败)
 * @return 请求是否成功发送
 */
bool sendPaymentRequest(int paymentCode);

/**
 * 初始化程序
 * @return 初始化是否成功
 */
bool initialize();

/**
 * 清理资源
 */
void cleanup();

/**
 * 处理网络请求完成后的响应
 * @param reply 网络响应
 * @return 请求是否成功处理
 */
bool handleNetworkReply(QNetworkReply *reply);

#endif // PAYMENT_CLIENT_H
