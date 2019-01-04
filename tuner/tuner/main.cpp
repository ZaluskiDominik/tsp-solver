#include "tunerdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TunerDialog w;
    w.show();

    return a.exec();
}
