#ifndef MAPPLACE_H
#define MAPPLACE_H

#include <QAbstractButton>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class mapplace : public QAbstractButton
{
    Q_OBJECT
public:
    mapplace(QWidget *parent = nullptr);
    virtual ~mapplace();
protected:
    void paintEvent(QPaintEvent *e);
private slots:
    void click();
};

#endif // MAPPLACE_H
