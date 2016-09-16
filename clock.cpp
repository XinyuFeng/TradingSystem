#include "clock.h"

CLOCK::CLOCK(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    timer->start(1000);//一秒钟
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    QFont font;
    font.setPointSize(10);//字体大小设置为10
    setFont(font);
}

CLOCK::~CLOCK()
{

}

void CLOCK::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int side = qMin(width(), height());

    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(0, 0, 200, 200);/*设置(0，0)为新的坐标原点*/

    draw(&painter);
}

void CLOCK::draw(QPainter *painter)
{
    QPen thickPen(palette().foreground(), 1.5);//设置刻度线为粗黑
    QPen thinPen(palette().foreground(), 0.5);//设置刻度线为灰

    QTime time = QTime::currentTime();
    painter->translate(100,100);//重新设定坐标原点

    painter->setRenderHint(QPainter::Antialiasing);//消锯齿
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->save();//保存坐标系，防止坐标系跑偏了
    painter->rotate(6.0*time.second());//注意是6.0，不是6
    painter->drawConvexPolygon(sed,4);
    painter->restore();//复位之前的坐标系

    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->save();
    painter->rotate(6.0*(time.minute()+time.second()/60.0));
    painter->drawConvexPolygon(min,4);
    painter->restore();

    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->save();
    painter->rotate(30.0*(time.hour()+time.minute()/60.0));
    painter->drawConvexPolygon(hour,4);
    painter->restore();

// //painter->drawLine(0,-98,0,-88);
// for(int i=0;i<12;i++)
// {
// painter->rotate(30);//坐标轴旋转30度
// painter->drawLine(0,-98,0,-88);
// }
    /*画刻度还有数字*/
    for (int i = 1; i <=60; ++i) {
        painter->save();
        painter->rotate(6*i);//坐标轴旋转6度
        if (i % 5 == 0) {
            painter->setPen(thickPen);
            painter->drawLine(0, -98, 0, -82);
            painter->drawText(-20, -82, 40, 40,
                              Qt::AlignHCenter | Qt::AlignTop,
                              QString::number(i/5));
        } else {
            painter->setPen(thinPen);
            painter->drawLine(0, -98, 0, -88);
        }
        //painter->rotate(-DegreesPerMinute);
        painter->restore();
    }
}
