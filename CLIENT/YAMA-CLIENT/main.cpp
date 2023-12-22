#include "yama.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YAMA w;
    w.show();
    return a.exec();
}
