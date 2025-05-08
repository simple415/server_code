#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// 前置声明
namespace Ui {
class MainWindow;
}

// 外部变量声明
extern QString SERVER_URL;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConfirmPayment_clicked();
    void on_btnReconfirm_clicked();

private:
    Ui::MainWindow *ui;
    QString serverUrl;
    QString qrCodePath;

    bool initializeClient();    // 调用全局 initialize() 函数
    void cleanupClient();       // 调用全局 cleanup() 函数
    void loadQRCodeImage(const QString &imagePath);
    void handlePaymentResponse(bool success, const QString &message, int httpCode);
    void showPaymentResultDialog(bool success);

    // 注释掉或删除这些声明，因为它们是全局函数，不是类成员
    // bool initialize();
    // void cleanup();
    // bool sendPaymentRequest(int code);
};

#endif // MAINWINDOW_H
