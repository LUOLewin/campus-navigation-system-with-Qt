/*****************************************
File name:      mydialog.h
Author:         luolewin
Version:        v1.0
Description:    校园导航子窗口cpp的头文件
Date:           2020.12.17
*****************************************/

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = nullptr);
    ~myDialog();

private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
