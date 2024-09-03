#include "game.h"
#include "log_manager.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    LogManager::activateLogging();

    Game game;

    return QApplication::exec();
}

//TODO implement custom speed vectors
//TODO lock cursor inside window
//TODO add angle-based bounces
//TODO adjust to full-screen
//TODO add score
//TODO add additional graphic effects when breaking brick
