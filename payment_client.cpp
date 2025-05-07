#include "payment_client.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>

// 服务器地址和端口配置
QString SERVER_URL = "http://8.138.134.50:5000/payment";

// 网络访问管理器（全局变量）
QNetworkAccessManager* networkManager = nullptr;

bool sendPaymentRequest(int paymentCode) {
    if (!networkManager) {
        qCritical() << "网络管理器未初始化";
        return false;
    }

    // 创建网络请求
    QNetworkRequest request;
    request.setUrl(QUrl(SERVER_URL));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 准备请求体数据
    QJsonObject jsonObj;
    jsonObj["code"] = paymentCode;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();

    // 发送POST请求
    QNetworkReply* reply = networkManager->post(request, jsonData);

    // 使用事件循环等待响应完成（同步请求）
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 处理响应
    bool success = handleNetworkReply(reply);

    // 清理资源
    reply->deleteLater();

    // 在新设计中，我们根据发送的paymentCode直接返回结果
    // 实际项目中，应该解析服务器返回的响应来判断支付结果
    return success && (reply->error() == QNetworkReply::NoError);
}

bool handleNetworkReply(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qCritical() << "网络请求错误: " << reply->errorString();
        return false;
    }

    // 获取HTTP状态码
    int httpCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    // 读取响应数据
    QByteArray responseData = reply->readAll();
    QString responseStr = QString::fromUtf8(responseData);

    // 输出响应数据
    qDebug() << "HTTP状态码: " << httpCode;
    qDebug() << "服务器响应: " << responseStr;

    return httpCode == 200;
}

bool initialize() {
    // 初始化网络访问管理器
    if (!networkManager) {
        networkManager = new QNetworkAccessManager();
    }

    if (!networkManager) {
        qCritical() << "无法初始化网络管理器";
        return false;
    }

    qDebug() << "支付测试客户端已启动";
    qDebug() << "连接到服务器: " << SERVER_URL;
    return true;
}

void cleanup() {
    // 清理网络访问管理器
    if (networkManager) {
        delete networkManager;
        networkManager = nullptr;
    }

    qDebug() << "资源已清理";
}
