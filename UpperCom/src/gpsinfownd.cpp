#include "include/gpsinfownd.h"
#include <QtCore>
#include <QtGui>




GPSInfoWnd::GPSInfoWnd(QWidget *parent) : QWidget(parent)
{    
    if( imgHat.load("../Resources/hat.png") == false) {
        qDebug() << "Could not load image";
    }

    setMouseTracking(true);   //mouse track open
}

void GPSInfoWnd::paintEvent(QPaintEvent* ){
    DrawScreen();
}

QSize GPSInfoWnd::sizeHint() const {
    return QSize(200,200);
}

void GPSInfoWnd::Update_value(hardwareInfo::GPS_Data _gpsinfo){

    this->gpsinfo = _gpsinfo;

    repaint();
}

void GPSInfoWnd::Enable_locating_alert(){
    isVisiable = !isVisiable;
}

void GPSInfoWnd::DrawScreen() {

    if(firstpaint == true){
        static qreal x = 0,y = 0;
        static int count = 0;

        x += (qreal)this->gpsinfo.deg_lat;
        y += (qreal)this->gpsinfo.deg_lon;

        count++;

        if(count < 10) return;            //first ten times paint
        else{
            CenterX = x / qreal(count);
            CenterY = y / qreal(count);
            firstpaint = false;
        }
    }

    QPainter painter(this);
    QPalette pal;
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    QPointF basePoint = QPointF(width()/2,height()/2);
    //
    // Create the draw rect area and center it
    //
    qreal dSmallSide = (qreal)qMin(width(), height()) - 1;
    QRectF rcDraw(dSmallSide, dSmallSide, dSmallSide, dSmallSide);
    if(width() > height()) {
        // center horizontally
        rcDraw.moveTo(width()/2 - dSmallSide/2, 0);
    } else {
        rcDraw.moveTo(0,height()/2 - dSmallSide/2);
    }

    //
    // Erase background
    //
    painter.setPen(QPalette::WindowText);
    painter.setBrush(pal.color(QPalette::Base));
    painter.drawEllipse(rcDraw);

    QRectF rc45 = rcDraw;
    rc45.adjust(dSmallSide/4, dSmallSide/4, -dSmallSide/4, -dSmallSide/4);
    painter.drawEllipse(rc45);

    painter.drawLine(rcDraw.left() + dSmallSide / 2, rcDraw.top(),
                     rcDraw.left() + dSmallSide / 2, rcDraw.bottom());

    painter.drawText(basePoint+QPointF(-220, -15), QString("Longitude: ")+QString("%1").arg(CenterX)+QString(" deg"));

    painter.drawLine(rcDraw.left(), rcDraw.top() + dSmallSide / 2,
                     rcDraw.right(), rcDraw.top() + dSmallSide / 2);

    painter.drawText(basePoint+QPointF(15, 220), QString("Latitude: ")+QString("%1").arg(CenterY)+QString(" deg"));
    //
    // paint points
    //
    //area center
    qreal dCenterX = rcDraw.left() + dSmallSide / 2.0;
    qreal dCenterY = rcDraw.left() + dSmallSide / 2.0;

    int nSize = (int)( dSmallSide * 0.045 );
    QFont Font("Helvetica [Cronyx]", nSize);
    painter.setFont(Font);
    QFontMetrics fontMetrics(Font);

    pt = ATONToPoint(dCenterX,dCenterY,gpsinfo.deg_lat,
                gpsinfo.deg_lon);

    imgScale = dSmallSide * 0.04f;

    QRectF rcImage(pt.x(), pt.y(), imgScale, imgScale);

    if(isVisiable)
        painter.drawImage(rcImage, imgHat);

    rcImage.adjust(0, 0, 0, fontMetrics.height());
    QString str = QString("%1").arg(gpsinfo.elv);
    painter.drawText(rcImage, str, Qt::AlignBottom | Qt::AlignHCenter);
}

QPoint GPSInfoWnd::ATONToPoint(qreal dCenterX, qreal dCenterY,
                               double lat, double lon) {

    qreal x,y;
    qreal diffx,diffy;

    diffx = (qreal)lat - (qreal)CenterX;
    diffy = (qreal)lon - (qreal)CenterY;

    x = dCenterX + diffx;
    y = dCenterY + diffy;

    return QPoint(x,y);
}

void GPSInfoWnd::mouseMoveEvent(QMouseEvent* event){

    QPoint globalPos = event->globalPos();

    QPoint widgetPos = mapFromGlobal(globalPos);

    if(isInTargetArea(widgetPos)){
        QString str_text =
                "Latitude:  \n"
                "Longitude: \n"
                "Altitude:  \n"
                "Speed:     \n"
                ;

        str_text.sprintf("%f\n"
                    "%f\n"
                    "%.02f M\n"
                    "%.02f KT\n",
                    gpsinfo.deg_lat,
                    gpsinfo.deg_lon,
                    gpsinfo.elv,
                    gpsinfo.speed
                    );
        QToolTip::showText(globalPos,str_text);
    }
    else{
        QToolTip::hideText();
    }
}

bool GPSInfoWnd::isInTargetArea(const QPoint pos){
    int diff = 30;

//    qDebug() << "posx:" << pos.x() << "ptx:" << pt.x()+imgScale/2 <<
//                "posy:" << pos.y() << "pty:" << pt.y()+imgScale/2 << "\n";

    QRectF rcImage(pt.x()+imgScale/2, pt.y()+imgScale/2, imgScale+diff, imgScale+diff);

    return rcImage.contains(pos);


    return false;
}
