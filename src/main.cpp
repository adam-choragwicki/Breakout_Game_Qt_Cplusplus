#include "game.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    Game game;

    return QApplication::exec();
}

//TODO allow moving paddle before src start
//TODO add angle-based bounces
//TODO add tests
//TODO lock cursor inside window
//TODO cleanup in Config.h and adjust to full-screen
//TODO add score
//TODO add additional graphic effects when breaking brick
