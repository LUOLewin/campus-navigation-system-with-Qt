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
    const size_t get_place_id();
    void set_place_id(const size_t id);
    void draw_line(place *A,place *B);
    static int clicks;
    static int red;
    //static int chosen_times;
protected:
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
private slots:

private:
    size_t place_id;//地点的序号

    static void set_stylesheet();
};
#endif // PLACE_H
