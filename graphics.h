#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QPaintEvent>
#include <QWidget>


class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    void paintchar(QPainter &painter);
    void tanVo (QPainter &painter ,int po);
    int random(int rnd);

    int x,po,timerId ,id,mode=0;
    QString text  ;
    qreal opacity_char,opacity_broken;
signals:

public slots:
};

#endif // GRAPHICS_H
