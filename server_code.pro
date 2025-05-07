QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaymentClient
TEMPLATE = app

# 不需要额外添加库，使用Qt网络模块

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    payment_client.cpp

HEADERS += \
    mainwindow.h \
    payment_client.h

FORMS += \
    mainwindow.ui

# 添加资源文件
RESOURCES = resource.qrc

# 默认规则为发布构建
CONFIG += c++11
CONFIG(release, debug|release): DEFINES += QT_NO_DEBUG_OUTPUT

# 应用图标（可选）
# RC_ICONS = app_icon.ico  # Windows系统
# ICON = app_icon.icns     # macOS系统
