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

    bool initializeClient();
    void cleanupClient();
    void loadQRCodeImage(const QString &imagePath);
    void handlePaymentResponse(bool success, const QString &message, int httpCode);
    void showPaymentResultDialog(bool success);

    // 声明外部函数
    bool initialize();
    void cleanup();
    bool sendPaymentRequest(int code);
};

#endif // MAINWINDOW_H
