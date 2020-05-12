#include "snakemainwindow.h"
#include "snakehead.h"
#include "snakebody.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(snake);
    QApplication application(argc, argv);

    SnakeMainWindow snake_main_window;
    snake_main_window.setWindowTitle("Snake game");
    snake_main_window.show();
    return application.exec();
}
