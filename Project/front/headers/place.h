#ifndef PLACE_H
#define PLACE_H
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>
class place : public QLabel
{
    Q_OBJECT

public:
    place(QWidget *parent = nullptr);
    virtual ~place();
    const size_t get_place_id();
    void set_place_id(const size_t id);
protected:
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
private slots:

private:
    size_t place_id;//地点的序号

};
#endif // PLACE_H
