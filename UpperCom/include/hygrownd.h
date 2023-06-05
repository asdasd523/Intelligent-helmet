#ifndef HYGROWND_H
#define HYGROWND_H


#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include <QTimer>
#include <QMutex>
#include "hardwareclient.h"

class HygroWnd : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal value WRITE Update_value)     //动画相关属性声明

public:
    explicit HygroWnd(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* e);



public slots:
    void startAnimation();
    void Update_value(qreal value);

private:
    qreal m_value;
    int m_width;
    QRectF m_rect;
    qreal maxValue, minValue;
    qreal m_radius;

    QMutex m_mutex;
    QPropertyAnimation *m_valueAnimation;
    void updateRect();
};




#endif // HYGROWND_H
