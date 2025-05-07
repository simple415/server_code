/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxQRCode;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelQRCode;
    QLabel *labelOrderInfo;
    QGroupBox *groupBoxPayment;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnConfirmPayment;
    QPushButton *btnReconfirm;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxQRCode = new QGroupBox(centralWidget);
        groupBoxQRCode->setObjectName("groupBoxQRCode");
        groupBoxQRCode->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBoxQRCode);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelQRCode = new QLabel(groupBoxQRCode);
        labelQRCode->setObjectName("labelQRCode");
        labelQRCode->setMinimumSize(QSize(250, 250));
        labelQRCode->setMaximumSize(QSize(250, 250));
        labelQRCode->setFrameShape(QFrame::Box);
        labelQRCode->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelQRCode);

        labelOrderInfo = new QLabel(groupBoxQRCode);
        labelOrderInfo->setObjectName("labelOrderInfo");
        labelOrderInfo->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelOrderInfo);


        verticalLayout->addWidget(groupBoxQRCode);

        groupBoxPayment = new QGroupBox(centralWidget);
        groupBoxPayment->setObjectName("groupBoxPayment");
        horizontalLayout_2 = new QHBoxLayout(groupBoxPayment);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnConfirmPayment = new QPushButton(groupBoxPayment);
        btnConfirmPayment->setObjectName("btnConfirmPayment");
        btnConfirmPayment->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        btnConfirmPayment->setFont(font);
        btnConfirmPayment->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 204, 113);"));

        horizontalLayout_2->addWidget(btnConfirmPayment);

        btnReconfirm = new QPushButton(groupBoxPayment);
        btnReconfirm->setObjectName("btnReconfirm");
        btnReconfirm->setMinimumSize(QSize(0, 40));
        btnReconfirm->setFont(font);
        btnReconfirm->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 196, 15);"));

        horizontalLayout_2->addWidget(btnReconfirm);


        verticalLayout->addWidget(groupBoxPayment);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\224\257\344\273\230", nullptr));
        groupBoxQRCode->setTitle(QCoreApplication::translate("MainWindow", "\346\224\257\344\273\230\344\272\214\347\273\264\347\240\201", nullptr));
        labelQRCode->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\273\264\347\240\201\345\233\276\345\203\217\345\214\272\345\237\237", nullptr));
        labelOrderInfo->setText(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\351\207\221\351\242\235: \302\24588.88", nullptr));
        groupBoxPayment->setTitle(QCoreApplication::translate("MainWindow", "\346\224\257\344\273\230\346\223\215\344\275\234", nullptr));
        btnConfirmPayment->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\346\224\257\344\273\230", nullptr));
        btnReconfirm->setText(QCoreApplication::translate("MainWindow", "\345\206\215\346\254\241\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
