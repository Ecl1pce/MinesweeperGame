#include <QCoreApplication>
#include "application.h"
#include <iostream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);
    Application app;
   app.viewMainMenu();
    app.startGame(app.difficulty);
    Field field;




    return a.exec();
}

