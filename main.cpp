#include "xh_mips.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XH_mips w;
    w.show();
    return a.exec();
}
