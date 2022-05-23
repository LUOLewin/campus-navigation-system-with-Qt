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
    QHBoxLayout *horizontalLayout;
    QLabel *MousePosLabel;
    QLabel *map;
    place *Node_0;
    place *Node_1;
    place *Node_2;
    place *Node_3;
    place *Node_4;
    place *Node_5;
    place *Node_6;
    place *Node_7;
    place *Node_8;
    place *Node_9;
    place *Node_10;
    place *Node_11;
    place *Node_12;
    place *Node_13;
    place *Node_14;
    place *Node_15;
    place *Node_16;
    place *Node_17;
    place *Node_18;
    place *Node_19;
    place *Node_20;
    place *Node_21;
    place *Node_22;
    place *Node_23;
    place *Node_24;
    place *Node_25;
    place *Node_26;
    place *Node_27;
    place *Node_28;
    place *Node_29;
    place *Node_30;
    place *Node_31;
    place *Node_32;
    place *Node_33;
    place *Node_34;
    place *Node_35;
    place *Node_36;
    place *Node_37;
    place *Node_38;
    place *Node_39;
    place *Node_40;
    place *Node_41;
    place *Node_42;
    place *Node_43;
    place *Node_44;
    place *Node_45;
    place *Node_46;
    place *Node_47;
    place *Node_48;
    place *Node_49;
    place *Node_50;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1282, 852);
        MainWindow->setMinimumSize(QSize(1200, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setMouseTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1090, 0, 191, 591));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MousePosLabel = new QLabel(layoutWidget);
        MousePosLabel->setObjectName(QString::fromUtf8("MousePosLabel"));

        horizontalLayout->addWidget(MousePosLabel);


        verticalLayout->addLayout(horizontalLayout);

        map = new QLabel(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 0, 1091, 681));
        map->setMouseTracking(true);
        map->setScaledContents(true);
        Node_0 = new place(centralwidget);
        Node_0->setObjectName(QString::fromUtf8("Node_0"));
        Node_0->setGeometry(QRect(130, 640, 16, 20));
        QFont font;
        font.setPointSize(8);
        Node_0->setFont(font);
        Node_0->setMouseTracking(true);
        Node_0->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_1 = new place(centralwidget);
        Node_1->setObjectName(QString::fromUtf8("Node_1"));
        Node_1->setGeometry(QRect(150, 650, 16, 20));
        Node_1->setFont(font);
        Node_1->setMouseTracking(true);
        Node_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_2 = new place(centralwidget);
        Node_2->setObjectName(QString::fromUtf8("Node_2"));
        Node_2->setGeometry(QRect(150, 610, 16, 20));
        Node_2->setFont(font);
        Node_2->setMouseTracking(true);
        Node_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_3 = new place(centralwidget);
        Node_3->setObjectName(QString::fromUtf8("Node_3"));
        Node_3->setGeometry(QRect(115, 595, 16, 20));
        Node_3->setFont(font);
        Node_3->setMouseTracking(true);
        Node_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_4 = new place(centralwidget);
        Node_4->setObjectName(QString::fromUtf8("Node_4"));
        Node_4->setGeometry(QRect(130, 560, 16, 20));
        Node_4->setFont(font);
        Node_4->setMouseTracking(true);
        Node_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_5 = new place(centralwidget);
        Node_5->setObjectName(QString::fromUtf8("Node_5"));
        Node_5->setGeometry(QRect(120, 520, 16, 20));
        Node_5->setFont(font);
        Node_5->setMouseTracking(true);
        Node_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_6 = new place(centralwidget);
        Node_6->setObjectName(QString::fromUtf8("Node_6"));
        Node_6->setGeometry(QRect(130, 510, 16, 20));
        Node_6->setFont(font);
        Node_6->setMouseTracking(true);
        Node_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_7 = new place(centralwidget);
        Node_7->setObjectName(QString::fromUtf8("Node_7"));
        Node_7->setGeometry(QRect(116, 481, 16, 20));
        Node_7->setFont(font);
        Node_7->setMouseTracking(true);
        Node_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_8 = new place(centralwidget);
        Node_8->setObjectName(QString::fromUtf8("Node_8"));
        Node_8->setGeometry(QRect(170, 610, 16, 20));
        Node_8->setFont(font);
        Node_8->setMouseTracking(true);
        Node_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_9 = new place(centralwidget);
        Node_9->setObjectName(QString::fromUtf8("Node_9"));
        Node_9->setGeometry(QRect(230, 530, 20, 20));
        Node_9->setFont(font);
        Node_9->setMouseTracking(true);
        Node_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_10 = new place(centralwidget);
        Node_10->setObjectName(QString::fromUtf8("Node_10"));
        Node_10->setGeometry(QRect(230, 450, 20, 20));
        Node_10->setFont(font);
        Node_10->setMouseTracking(true);
        Node_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_11 = new place(centralwidget);
        Node_11->setObjectName(QString::fromUtf8("Node_11"));
        Node_11->setGeometry(QRect(140, 390, 20, 20));
        Node_11->setFont(font);
        Node_11->setMouseTracking(true);
        Node_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_12 = new place(centralwidget);
        Node_12->setObjectName(QString::fromUtf8("Node_12"));
        Node_12->setGeometry(QRect(80, 390, 20, 20));
        Node_12->setFont(font);
        Node_12->setMouseTracking(true);
        Node_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_13 = new place(centralwidget);
        Node_13->setObjectName(QString::fromUtf8("Node_13"));
        Node_13->setGeometry(QRect(70, 340, 20, 20));
        Node_13->setFont(font);
        Node_13->setMouseTracking(true);
        Node_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_14 = new place(centralwidget);
        Node_14->setObjectName(QString::fromUtf8("Node_14"));
        Node_14->setGeometry(QRect(30, 320, 20, 20));
        Node_14->setFont(font);
        Node_14->setMouseTracking(true);
        Node_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_15 = new place(centralwidget);
        Node_15->setObjectName(QString::fromUtf8("Node_15"));
        Node_15->setGeometry(QRect(80, 320, 20, 20));
        Node_15->setFont(font);
        Node_15->setMouseTracking(true);
        Node_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_16 = new place(centralwidget);
        Node_16->setObjectName(QString::fromUtf8("Node_16"));
        Node_16->setGeometry(QRect(150, 330, 20, 20));
        Node_16->setFont(font);
        Node_16->setMouseTracking(true);
        Node_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_17 = new place(centralwidget);
        Node_17->setObjectName(QString::fromUtf8("Node_17"));
        Node_17->setGeometry(QRect(280, 230, 20, 20));
        Node_17->setFont(font);
        Node_17->setMouseTracking(true);
        Node_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_18 = new place(centralwidget);
        Node_18->setObjectName(QString::fromUtf8("Node_18"));
        Node_18->setGeometry(QRect(120, 230, 20, 20));
        Node_18->setFont(font);
        Node_18->setMouseTracking(true);
        Node_18->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_19 = new place(centralwidget);
        Node_19->setObjectName(QString::fromUtf8("Node_19"));
        Node_19->setGeometry(QRect(80, 160, 20, 20));
        Node_19->setFont(font);
        Node_19->setMouseTracking(true);
        Node_19->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_20 = new place(centralwidget);
        Node_20->setObjectName(QString::fromUtf8("Node_20"));
        Node_20->setGeometry(QRect(20, 350, 20, 20));
        Node_20->setFont(font);
        Node_20->setMouseTracking(true);
        Node_20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_21 = new place(centralwidget);
        Node_21->setObjectName(QString::fromUtf8("Node_21"));
        Node_21->setGeometry(QRect(140, 60, 20, 20));
        Node_21->setFont(font);
        Node_21->setMouseTracking(true);
        Node_21->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_22 = new place(centralwidget);
        Node_22->setObjectName(QString::fromUtf8("Node_22"));
        Node_22->setGeometry(QRect(100, 70, 20, 20));
        Node_22->setFont(font);
        Node_22->setMouseTracking(true);
        Node_22->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_23 = new place(centralwidget);
        Node_23->setObjectName(QString::fromUtf8("Node_23"));
        Node_23->setGeometry(QRect(300, 130, 20, 20));
        Node_23->setFont(font);
        Node_23->setMouseTracking(true);
        Node_23->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_24 = new place(centralwidget);
        Node_24->setObjectName(QString::fromUtf8("Node_24"));
        Node_24->setGeometry(QRect(360, 110, 20, 20));
        Node_24->setFont(font);
        Node_24->setMouseTracking(true);
        Node_24->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_25 = new place(centralwidget);
        Node_25->setObjectName(QString::fromUtf8("Node_25"));
        Node_25->setGeometry(QRect(500, 130, 20, 20));
        Node_25->setFont(font);
        Node_25->setMouseTracking(true);
        Node_25->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_26 = new place(centralwidget);
        Node_26->setObjectName(QString::fromUtf8("Node_26"));
        Node_26->setGeometry(QRect(570, 130, 20, 20));
        Node_26->setFont(font);
        Node_26->setMouseTracking(true);
        Node_26->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_27 = new place(centralwidget);
        Node_27->setObjectName(QString::fromUtf8("Node_27"));
        Node_27->setGeometry(QRect(630, 130, 20, 20));
        Node_27->setFont(font);
        Node_27->setMouseTracking(true);
        Node_27->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_28 = new place(centralwidget);
        Node_28->setObjectName(QString::fromUtf8("Node_28"));
        Node_28->setGeometry(QRect(680, 120, 20, 20));
        Node_28->setFont(font);
        Node_28->setMouseTracking(true);
        Node_28->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_29 = new place(centralwidget);
        Node_29->setObjectName(QString::fromUtf8("Node_29"));
        Node_29->setGeometry(QRect(510, 180, 20, 20));
        Node_29->setFont(font);
        Node_29->setMouseTracking(true);
        Node_29->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_30 = new place(centralwidget);
        Node_30->setObjectName(QString::fromUtf8("Node_30"));
        Node_30->setGeometry(QRect(600, 210, 20, 20));
        Node_30->setFont(font);
        Node_30->setMouseTracking(true);
        Node_30->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_31 = new place(centralwidget);
        Node_31->setObjectName(QString::fromUtf8("Node_31"));
        Node_31->setGeometry(QRect(380, 310, 20, 20));
        Node_31->setFont(font);
        Node_31->setMouseTracking(true);
        Node_31->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_32 = new place(centralwidget);
        Node_32->setObjectName(QString::fromUtf8("Node_32"));
        Node_32->setGeometry(QRect(550, 290, 20, 20));
        Node_32->setFont(font);
        Node_32->setMouseTracking(true);
        Node_32->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_33 = new place(centralwidget);
        Node_33->setObjectName(QString::fromUtf8("Node_33"));
        Node_33->setGeometry(QRect(510, 370, 20, 20));
        Node_33->setFont(font);
        Node_33->setMouseTracking(true);
        Node_33->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_34 = new place(centralwidget);
        Node_34->setObjectName(QString::fromUtf8("Node_34"));
        Node_34->setGeometry(QRect(680, 440, 20, 20));
        Node_34->setFont(font);
        Node_34->setMouseTracking(true);
        Node_34->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_35 = new place(centralwidget);
        Node_35->setObjectName(QString::fromUtf8("Node_35"));
        Node_35->setGeometry(QRect(430, 360, 20, 20));
        Node_35->setFont(font);
        Node_35->setMouseTracking(true);
        Node_35->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_36 = new place(centralwidget);
        Node_36->setObjectName(QString::fromUtf8("Node_36"));
        Node_36->setGeometry(QRect(480, 570, 20, 20));
        Node_36->setFont(font);
        Node_36->setMouseTracking(true);
        Node_36->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_37 = new place(centralwidget);
        Node_37->setObjectName(QString::fromUtf8("Node_37"));
        Node_37->setGeometry(QRect(710, 500, 20, 20));
        Node_37->setFont(font);
        Node_37->setMouseTracking(true);
        Node_37->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_38 = new place(centralwidget);
        Node_38->setObjectName(QString::fromUtf8("Node_38"));
        Node_38->setGeometry(QRect(680, 560, 20, 20));
        Node_38->setFont(font);
        Node_38->setMouseTracking(true);
        Node_38->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_39 = new place(centralwidget);
        Node_39->setObjectName(QString::fromUtf8("Node_39"));
        Node_39->setGeometry(QRect(740, 540, 20, 20));
        Node_39->setFont(font);
        Node_39->setMouseTracking(true);
        Node_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_40 = new place(centralwidget);
        Node_40->setObjectName(QString::fromUtf8("Node_40"));
        Node_40->setGeometry(QRect(810, 430, 20, 20));
        Node_40->setFont(font);
        Node_40->setMouseTracking(true);
        Node_40->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_41 = new place(centralwidget);
        Node_41->setObjectName(QString::fromUtf8("Node_41"));
        Node_41->setGeometry(QRect(680, 340, 20, 20));
        Node_41->setFont(font);
        Node_41->setMouseTracking(true);
        Node_41->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_42 = new place(centralwidget);
        Node_42->setObjectName(QString::fromUtf8("Node_42"));
        Node_42->setGeometry(QRect(650, 310, 20, 20));
        Node_42->setFont(font);
        Node_42->setMouseTracking(true);
        Node_42->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_43 = new place(centralwidget);
        Node_43->setObjectName(QString::fromUtf8("Node_43"));
        Node_43->setGeometry(QRect(760, 180, 20, 20));
        Node_43->setFont(font);
        Node_43->setMouseTracking(true);
        Node_43->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_44 = new place(centralwidget);
        Node_44->setObjectName(QString::fromUtf8("Node_44"));
        Node_44->setGeometry(QRect(900, 390, 20, 20));
        Node_44->setFont(font);
        Node_44->setMouseTracking(true);
        Node_44->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_45 = new place(centralwidget);
        Node_45->setObjectName(QString::fromUtf8("Node_45"));
        Node_45->setGeometry(QRect(920, 430, 20, 20));
        Node_45->setFont(font);
        Node_45->setMouseTracking(true);
        Node_45->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_46 = new place(centralwidget);
        Node_46->setObjectName(QString::fromUtf8("Node_46"));
        Node_46->setGeometry(QRect(920, 260, 20, 20));
        Node_46->setFont(font);
        Node_46->setMouseTracking(true);
        Node_46->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_47 = new place(centralwidget);
        Node_47->setObjectName(QString::fromUtf8("Node_47"));
        Node_47->setGeometry(QRect(1010, 10, 20, 20));
        Node_47->setFont(font);
        Node_47->setMouseTracking(true);
        Node_47->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_48 = new place(centralwidget);
        Node_48->setObjectName(QString::fromUtf8("Node_48"));
        Node_48->setGeometry(QRect(900, 20, 20, 20));
        Node_48->setFont(font);
        Node_48->setMouseTracking(true);
        Node_48->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_49 = new place(centralwidget);
        Node_49->setObjectName(QString::fromUtf8("Node_49"));
        Node_49->setGeometry(QRect(550, 20, 20, 20));
        Node_49->setFont(font);
        Node_49->setMouseTracking(true);
        Node_49->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Node_50 = new place(centralwidget);
        Node_50->setObjectName(QString::fromUtf8("Node_50"));
        Node_50->setGeometry(QRect(230, 60, 20, 20));
        Node_50->setFont(font);
        Node_50->setMouseTracking(true);
        Node_50->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 700, 471, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1282, 25));
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
        available_path_button->setText(QCoreApplication::translate("MainWindow", "\346\255\245\350\241\214\346\250\241\345\274\217", nullptr));
        shortest_path_button->setText(QCoreApplication::translate("MainWindow", "\351\252\221\350\241\214\346\250\241\345\274\217", nullptr));
        MousePosLabel->setText(QCoreApplication::translate("MainWindow", "(0,0)", nullptr));
        map->setText(QString());
        Node_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Node_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Node_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        Node_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Node_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Node_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Node_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Node_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Node_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Node_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        Node_10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        Node_11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        Node_12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        Node_13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        Node_14->setText(QCoreApplication::translate("MainWindow", "14", nullptr));
        Node_15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        Node_16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        Node_17->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        Node_18->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        Node_19->setText(QCoreApplication::translate("MainWindow", "19", nullptr));
        Node_20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        Node_21->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        Node_22->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        Node_23->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        Node_24->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        Node_25->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        Node_26->setText(QCoreApplication::translate("MainWindow", "26", nullptr));
        Node_27->setText(QCoreApplication::translate("MainWindow", "27", nullptr));
        Node_28->setText(QCoreApplication::translate("MainWindow", "28", nullptr));
        Node_29->setText(QCoreApplication::translate("MainWindow", "29", nullptr));
        Node_30->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        Node_31->setText(QCoreApplication::translate("MainWindow", "31", nullptr));
        Node_32->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        Node_33->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        Node_34->setText(QCoreApplication::translate("MainWindow", "34", nullptr));
        Node_35->setText(QCoreApplication::translate("MainWindow", "35", nullptr));
        Node_36->setText(QCoreApplication::translate("MainWindow", "36", nullptr));
        Node_37->setText(QCoreApplication::translate("MainWindow", "37", nullptr));
        Node_38->setText(QCoreApplication::translate("MainWindow", "38", nullptr));
        Node_39->setText(QCoreApplication::translate("MainWindow", "39", nullptr));
        Node_40->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        Node_41->setText(QCoreApplication::translate("MainWindow", "41", nullptr));
        Node_42->setText(QCoreApplication::translate("MainWindow", "42", nullptr));
        Node_43->setText(QCoreApplication::translate("MainWindow", "43", nullptr));
        Node_44->setText(QCoreApplication::translate("MainWindow", "44", nullptr));
        Node_45->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        Node_46->setText(QCoreApplication::translate("MainWindow", "46", nullptr));
        Node_47->setText(QCoreApplication::translate("MainWindow", "47", nullptr));
        Node_48->setText(QCoreApplication::translate("MainWindow", "48", nullptr));
        Node_49->setText(QCoreApplication::translate("MainWindow", "49", nullptr));
        Node_50->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
