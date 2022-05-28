#ifndef PLACE_H
#define PLACE_H
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>
#include <QLine>
class place : public QLabel
{
    Q_OBJECT

public:
    place(QWidget *parent = nullptr);
    virtual ~place();

    static int clicks;
    static int red;
protected:
    void mousePressEvent(QMouseEvent *e);
private slots:

private:

    static void set_stylesheet();
};
#endif // PLACE_H
