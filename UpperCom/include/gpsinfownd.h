#ifndef GPSINFOWND_H
#define GPSINFOWND_H

#include <QWidget>
#include "hardwareclient.h"
#include <QTimer>
#include <QToolTip>

class GPSInfoWnd : public QWidget
{
    Q_OBJECT
public:
    explicit GPSInfoWnd(QWidget *parent = nullptr);
    QSize sizeHint() const;

signals:

protected:
    void paintEvent(QPaintEvent *);
    void DrawScreen();

    void getScreenCenter();
    QPoint ATONToPoint(qreal dCenterX,qreal dCenterY,
                       double lat,double lon);
    void mouseMoveEvent(QMouseEvent* event) override;

public slots:
    void Update_value(hardwareInfo::GPS_Data);
    void Enable_locating_alert();


private:
    qreal CenterX,CenterY;
    hardwareInfo::GPS_Data gpsinfo;
    bool firstpaint = true;
    QImage imgHat;
    bool isVisiable = true;
    QPoint pt;
    qreal imgScale;

    bool isInTargetArea(const QPoint pos);

//    QTimer timer;
//    int Timerinterval = 100;
};


#endif // GPSINFOWND_H
