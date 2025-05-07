#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序样式
    app.setStyle("Fusion");

    // 创建并显示主窗口
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
