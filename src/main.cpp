#include "breakout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Breakout breakout;

    return QApplication::exec();
}
