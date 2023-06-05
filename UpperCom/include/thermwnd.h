#ifndef THERMWND_H
#define THERMWND_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMutex>
#include <QPropertyAnimation>
#include "hardwareclient.h"


class ThermWnd : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal value WRITE Update_value)


public:
    explicit ThermWnd(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e);      //jicheng


public slots:
    void startAnimation();
    void Update_value(qreal);

private:
    qreal m_value;
    int m_width;
    int maxValue, minValue;
    qreal m_radius;

    QRectF m_rect;
    QPropertyAnimation *m_valueAnimation;
    QMutex m_mutex;

    void updateRect();
};

#endif // THERMWND_H
