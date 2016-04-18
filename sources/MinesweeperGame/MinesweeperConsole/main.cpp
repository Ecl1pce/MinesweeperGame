#include <QCoreApplication>
#include "application.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    while (true)
    {
    Application app;
    app.viewMainMenu();
    app.startGame();
    }
    return 0;
}

