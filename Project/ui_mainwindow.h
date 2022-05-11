/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <place.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QLabel *label2;
    QTextBrowser *textBrowser;
    QPushButton *available_path_button;
    QTextBrowser *textBrowser2;
    QPushButton *shortest_path_button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *MousePosLabel;
    QLabel *label_2;
    QLabel *map;
    place *Nan_Qu;
    place *Xin_Shi_Ji;
    place *Nan_Chen_Lu;
    place *SHU_Metro;
    place *A;
    place *B;
    place *C;
    place *D;
    place *Mei_Shu;
    place *Lib;
    place *Q_Lib;
    place *Tennis;
    place *Hou_Qin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 666);
        MainWindow->setMinimumSize(QSize(1200, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setMouseTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(800, 0, 191, 591));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(lineEdit);

        lineEdit2 = new QLineEdit(layoutWidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        verticalLayout->addWidget(lineEdit2);

        label2 = new QLabel(layoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));

        verticalLayout->addWidget(label2);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        available_path_button = new QPushButton(layoutWidget);
        available_path_button->setObjectName(QString::fromUtf8("available_path_button"));

        verticalLayout->addWidget(available_path_button);

        textBrowser2 = new QTextBrowser(layoutWidget);
        textBrowser2->setObjectName(QString::fromUtf8("textBrowser2"));

        verticalLayout->addWidget(textBrowser2);

        shortest_path_button = new QPushButton(layoutWidget);
        shortest_path_button->setObjectName(QString::fromUtf8("shortest_path_button"));

        verticalLayout->addWidget(shortest_path_button);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(800, 590, 191, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MousePosLabel = new QLabel(layoutWidget1);
        MousePosLabel->setObjectName(QString::fromUtf8("MousePosLabel"));

        horizontalLayout->addWidget(MousePosLabel);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        map = new QLabel(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 0, 800, 600));
        map->setMouseTracking(true);
        map->setPixmap(QPixmap(QString::fromUtf8(":/images/image/university_map.JPG")));
        map->setScaledContents(true);
        Nan_Qu = new place(centralwidget);
        Nan_Qu->setObjectName(QString::fromUtf8("Nan_Qu"));
        Nan_Qu->setGeometry(QRect(140, 450, 71, 121));
        QFont font;
        font.setPointSize(18);
        Nan_Qu->setFont(font);
        Nan_Qu->setMouseTracking(true);
        Xin_Shi_Ji = new place(centralwidget);
        Xin_Shi_Ji->setObjectName(QString::fromUtf8("Xin_Shi_Ji"));
        Xin_Shi_Ji->setGeometry(QRect(10, 290, 111, 121));
        Xin_Shi_Ji->setFont(font);
        Xin_Shi_Ji->setMouseTracking(true);
        Nan_Chen_Lu = new place(centralwidget);
        Nan_Chen_Lu->setObjectName(QString::fromUtf8("Nan_Chen_Lu"));
        Nan_Chen_Lu->setGeometry(QRect(580, 10, 81, 31));
        QFont font1;
        font1.setPointSize(8);
        Nan_Chen_Lu->setFont(font1);
        Nan_Chen_Lu->setMouseTracking(true);
        SHU_Metro = new place(centralwidget);
        SHU_Metro->setObjectName(QString::fromUtf8("SHU_Metro"));
        SHU_Metro->setGeometry(QRect(150, 10, 101, 31));
        SHU_Metro->setFont(font1);
        SHU_Metro->setMouseTracking(true);
        A = new place(centralwidget);
        A->setObjectName(QString::fromUtf8("A"));
        A->setGeometry(QRect(480, 350, 41, 21));
        A->setFont(font1);
        A->setMouseTracking(true);
        B = new place(centralwidget);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(460, 330, 41, 21));
        B->setFont(font1);
        B->setMouseTracking(true);
        C = new place(centralwidget);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(440, 310, 41, 21));
        C->setFont(font1);
        C->setMouseTracking(true);
        D = new place(centralwidget);
        D->setObjectName(QString::fromUtf8("D"));
        D->setGeometry(QRect(420, 290, 41, 21));
        D->setFont(font1);
        D->setMouseTracking(true);
        Mei_Shu = new place(centralwidget);
        Mei_Shu->setObjectName(QString::fromUtf8("Mei_Shu"));
        Mei_Shu->setGeometry(QRect(340, 380, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        Mei_Shu->setFont(font2);
        Mei_Shu->setMouseTracking(true);
        Lib = new place(centralwidget);
        Lib->setObjectName(QString::fromUtf8("Lib"));
        Lib->setGeometry(QRect(290, 221, 111, 20));
        Lib->setFont(font2);
        Lib->setMouseTracking(true);
        Q_Lib = new place(centralwidget);
        Q_Lib->setObjectName(QString::fromUtf8("Q_Lib"));
        Q_Lib->setGeometry(QRect(630, 340, 71, 20));
        QFont font3;
        font3.setPointSize(7);
        Q_Lib->setFont(font3);
        Q_Lib->setMouseTracking(true);
        Tennis = new place(centralwidget);
        Tennis->setObjectName(QString::fromUtf8("Tennis"));
        Tennis->setGeometry(QRect(130, 110, 51, 21));
        Tennis->setFont(font1);
        Tennis->setMouseTracking(true);
        Hou_Qin = new place(centralwidget);
        Hou_Qin->setObjectName(QString::fromUtf8("Hou_Qin"));
        Hou_Qin->setGeometry(QRect(150, 390, 81, 31));
        Hou_Qin->setFont(font1);
        Hou_Qin->setMouseTracking(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Guide", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271", nullptr));
        available_path_button->setText(QCoreApplication::translate("MainWindow", "\345\217\257\351\200\211\350\267\257\345\276\204", nullptr));
        shortest_path_button->setText(QCoreApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        MousePosLabel->setText(QCoreApplication::translate("MainWindow", "(0,0)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\357\274\232", nullptr));
        map->setText(QString());
        Nan_Qu->setText(QCoreApplication::translate("MainWindow", "\345\215\227\345\214\2721", nullptr));
        Xin_Shi_Ji->setText(QCoreApplication::translate("MainWindow", "\346\226\260\344\270\226\347\272\2522", nullptr));
        Nan_Chen_Lu->setText(QCoreApplication::translate("MainWindow", "\345\215\227\351\231\210\350\267\257\345\234\260\351\223\201\347\253\231", nullptr));
        SHU_Metro->setText(QCoreApplication::translate("MainWindow", "\344\270\212\346\265\267\345\244\247\345\255\246\345\234\260\351\223\201\347\253\231", nullptr));
        A->setText(QCoreApplication::translate("MainWindow", "A\346\245\274", nullptr));
        B->setText(QCoreApplication::translate("MainWindow", "B\346\245\274", nullptr));
        C->setText(QCoreApplication::translate("MainWindow", "C\346\245\274", nullptr));
        D->setText(QCoreApplication::translate("MainWindow", "D\346\245\274", nullptr));
        Mei_Shu->setText(QCoreApplication::translate("MainWindow", "\347\276\216\346\234\257\345\255\246\351\231\242", nullptr));
        Lib->setText(QCoreApplication::translate("MainWindow", "\346\234\254\351\203\250\345\233\276\344\271\246\351\246\206", nullptr));
        Q_Lib->setText(QCoreApplication::translate("MainWindow", "\351\222\261\344\274\237\351\225\277\345\233\276\344\271\246\351\246\206", nullptr));
        Tennis->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\220\203\351\246\206", nullptr));
        Hou_Qin->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\213\244\345\237\272\345\273\2723", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
