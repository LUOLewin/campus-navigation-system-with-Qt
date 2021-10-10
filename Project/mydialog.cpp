/*****************************************
File name:      mydialog.cpp
Author:         luolewin
Version:        v1.0
Description:    实现校园导航子窗口的主要功能
Date:           2020.12.17
*****************************************/

#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}
