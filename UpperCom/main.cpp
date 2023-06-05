#include "MainWindow.h"
#include <QApplication>
#include <QMetaType>
#include <include/protocol.h>
#include "include/sendthread.h"

int main(int argc, char *argv[])
{
    QApplication::setSetuidAllowed(true);   //add root permittion

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
