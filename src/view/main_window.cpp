#include "view/main_window.h"

MainWindow::MainWindow(Model* model) : model_(model)
{

}

void MainWindow::closeEvent(QCloseEvent*)
{
    exit(0);
}
