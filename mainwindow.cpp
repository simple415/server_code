#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "payment_client.h"  // 确保包含此头文件来获取全局函数的声明
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化客户端
    if (!initializeClient()) {
        QMessageBox::critical(this, "错误", "初始化失败，程序将退出");
        QApplication::quit();
    }

    // 服务器URL设为常量或从配置文件读取
    serverUrl = "http://payment-server/api";  // 默认值，可以从配置文件读取
    SERVER_URL = serverUrl;

    // 默认二维码图片路径（从资源文件加载）
    qrCodePath = ":/qrcode.png";

    // 加载二维码图片
    loadQRCodeImage(qrCodePath);

    // 设置窗口标题
    setWindowTitle("支付");
}

MainWindow::~MainWindow()
{
    // 清理资源
    cleanupClient();
    delete ui;
}

bool MainWindow::initializeClient()
{
    // 调用全局的初始化函数，而不是尝试调用MainWindow::initialize()
    bool success = ::initialize();  // 使用全局作用域运算符明确指出这是全局函数
    return success;
}

void MainWindow::cleanupClient()
{
    // 调用全局的清理函数，而不是尝试调用MainWindow::cleanup()
    ::cleanup();  // 使用全局作用域运算符明确指出这是全局函数
}

void MainWindow::loadQRCodeImage(const QString &imagePath)
{
    QPixmap qrCode;

    // 尝试加载二维码图片
    if (qrCode.load(imagePath)) {
        // 设置二维码图像到标签
        ui->labelQRCode->setPixmap(qrCode.scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->labelQRCode->setAlignment(Qt::AlignCenter);
        ui->labelQRCode->setText(""); // 清空文本
    } else {
        // 如果加载失败，显示错误信息
        ui->labelQRCode->setText("二维码图片未找到\n请确保 " + imagePath + " 文件存在");
        qDebug() << "无法加载二维码图片: " << imagePath;

        // 可选: 让用户选择一个二维码图片
        // 如果您想在启动时提示用户选择二维码图片，取消下面注释
        /*
        QString newPath = QFileDialog::getOpenFileName(this,
                                                     "选择二维码图片",
                                                     "",
                                                     "图片文件 (*.png *.jpg *.jpeg *.bmp)");
        if (!newPath.isEmpty()) {
            qrCodePath = newPath;
            loadQRCodeImage(qrCodePath);
        }
        */
    }
}

void MainWindow::on_btnConfirmPayment_clicked()
{
    // 设置当前服务器URL
    SERVER_URL = serverUrl;

    // 发送请求 - 调用全局函数
    bool success = ::sendPaymentRequest(1);  // 使用全局作用域运算符
    if (!success) {
        handlePaymentResponse(false, "请求发送失败", 0);
    }

    // 显示支付成功对话框
    showPaymentResultDialog(true);
}

void MainWindow::on_btnReconfirm_clicked()
{
    // 设置当前服务器URL
    SERVER_URL = serverUrl;

    // 发送请求 - 调用全局函数
    bool success = ::sendPaymentRequest(0);  // 使用全局作用域运算符
    if (!success) {
        handlePaymentResponse(false, "请求发送失败", 0);
    }

    // 显示支付失败对话框
    showPaymentResultDialog(false);
}

void MainWindow::handlePaymentResponse(bool success, const QString &message, int httpCode)
{
    // 此函数保留，但不再更新状态栏和标签
    Q_UNUSED(success);
    Q_UNUSED(message);
    Q_UNUSED(httpCode);
}

void MainWindow::showPaymentResultDialog(bool success)
{
    QMessageBox msgBox;

    if (success) {
        msgBox.setWindowTitle("支付成功");
        msgBox.setText("您的支付已成功处理！");
        msgBox.setIcon(QMessageBox::Information);
    } else {
        msgBox.setWindowTitle("支付失败");
        msgBox.setText("支付失败，请稍后重试。");
        msgBox.setIcon(QMessageBox::Warning);
    }

    msgBox.exec();
}
