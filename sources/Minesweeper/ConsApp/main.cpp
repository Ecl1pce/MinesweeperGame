#include <QCoreApplication>
#include "application.h"
#include <iostream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);

    Application app;
    app.viewMainMenu();
    int x = 10;
    int y = 10;

    int **field = new int *[x];

    for (int i = 0; i < x; i++)
    {
      field[i] = new int [y];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            field[i][j] = 0;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
    app.paintField(x,y,field);


    return a.exec();
}

