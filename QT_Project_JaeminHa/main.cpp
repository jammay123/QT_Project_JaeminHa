#include "secondwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    secondwindow w;
    w.show();

    return a.exec();
}
