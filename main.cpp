#include "window.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(life);

    QApplication app(argc, argv);
    Window window;
    window.show();

    return app.exec();
}
