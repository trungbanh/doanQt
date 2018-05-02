#include "graphics.h"
#include <QPainter>
#include <QRadialGradient>
#include <QTimerEvent>

graphics::graphics(QWidget *parent) : QWidget(parent)
{
    x = 0;
    po =0;
    opacity_char = 1.0;
    opacity_broken = 1.0;
    timerId = startTimer(100);
}
void graphics::timerEvent(QTimerEvent *event){
    Q_UNUSED(event);
    x++;
    repaint();
}
void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int h = height();
    int w = width();

    QRadialGradient grad1(w/2, h/2, 100);

    grad1.setColorAt(0, QColor("#ff0000"));
    grad1.setColorAt(0.35, Qt::white);
    grad1.setColorAt(1, QColor("#020202"));
    painter.fillRect(0, 0, w, h, grad1);

    if (mode==1){
        paintchar(painter);
    }
    if (mode==2){
        id = startTimer(100);
        tanVo(painter,po);
    }

}
void graphics::paintchar(QPainter &painter) {
    painter.setOpacity(opacity_char);
    double px = width()/5;
    double py = height()/2;
    for (int i = 1; i <= 10; i++) {
        painter.setPen("#5800fc"); //phần bóng
        QPointF position(px,py);
        QFont font("Time", x);
        QPainterPath path;
        path.addText(position,font,text);
        painter.setBrush(QColor("#3ded7e"));// mặt trước
        painter.drawPath(path);
        px += 1;
        py += 1;
    }
    if (x >70) {
        killTimer(timerId);
        id = startTimer(100);
        painter.setOpacity(opacity_char);
        opacity_char -= 0.05;
        po +=5;
        tanVo(painter,po);
    }
}
void graphics::tanVo(QPainter &painter,int po){
    painter.setOpacity(opacity_broken);
    painter.setBrush(QColor("#02d135"));
    painter.setPen(QColor("#02d135"));
    int py = po;
    for (int i= 0 ; i<1000 ; i++){
        py += random(30);
        int px = random(700);
        painter.drawEllipse(width()/4+px , height()/3+ py,5,5);
    }
    if (opacity_char ==0 ){
        opacity_broken =0;
    }
}
int graphics::random(int rnd) {
    return rand() % rnd;
}
