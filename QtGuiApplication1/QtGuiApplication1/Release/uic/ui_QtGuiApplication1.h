/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION1_H
#define UI_QTGUIAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication1Class
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *send;
    QTableWidget *tableWidget;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QWidget *recv;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication1Class)
    {
        if (QtGuiApplication1Class->objectName().isEmpty())
            QtGuiApplication1Class->setObjectName(QString::fromUtf8("QtGuiApplication1Class"));
        QtGuiApplication1Class->resize(600, 400);
        centralWidget = new QWidget(QtGuiApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 601, 351));
        send = new QWidget();
        send->setObjectName(QString::fromUtf8("send"));
        tableWidget = new QTableWidget(send);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 441, 311));
        pushButton_3 = new QPushButton(send);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 300, 131, 23));
        pushButton_3->setFlat(false);
        lineEdit = new QLineEdit(send);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(460, 160, 133, 20));
        label = new QLabel(send);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 142, 72, 16));
        layoutWidget = new QWidget(send);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(460, 10, 131, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 0, 1, 2);

        tabWidget->addTab(send, QString());
        recv = new QWidget();
        recv->setObjectName(QString::fromUtf8("recv"));
        tableWidget_2 = new QTableWidget(recv);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 10, 441, 291));
        pushButton_2 = new QPushButton(recv);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 280, 131, 23));
        pushButton = new QPushButton(recv);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 250, 131, 23));
        layoutWidget_2 = new QWidget(recv);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(460, 10, 131, 51));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 1, 0, 1, 2);

        tabWidget->addTab(recv, QString());
        QtGuiApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QtGuiApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplication1Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication1Class);

        tabWidget->setCurrentIndex(1);
        pushButton_3->setDefault(false);


        QMetaObject::connectSlotsByName(QtGuiApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication1Class)
    {
        QtGuiApplication1Class->setWindowTitle(QCoreApplication::translate("QtGuiApplication1Class", "\347\256\200\345\215\225\346\226\207\344\273\266\344\274\240\350\276\223\347\250\213\345\272\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QtGuiApplication1Class", "\344\274\240\350\276\223\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\223\215\344\275\234", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QtGuiApplication1Class", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("QtGuiApplication1Class", "\347\233\256\346\240\207IP\344\270\216\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("QtGuiApplication1Class", "\345\217\221\351\200\201\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_4->setText(QCoreApplication::translate("QtGuiApplication1Class", "\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(send), QCoreApplication::translate("QtGuiApplication1Class", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QtGuiApplication1Class", "\344\274\240\350\276\223\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\223\215\344\275\234", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtGuiApplication1Class", "\345\201\234\346\255\242\346\216\245\346\224\266", nullptr));
        pushButton->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        label_3->setText(QCoreApplication::translate("QtGuiApplication1Class", "\346\216\245\346\224\266\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_5->setText(QCoreApplication::translate("QtGuiApplication1Class", "\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recv), QCoreApplication::translate("QtGuiApplication1Class", "\346\216\245\346\224\266\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication1Class: public Ui_QtGuiApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION1_H
