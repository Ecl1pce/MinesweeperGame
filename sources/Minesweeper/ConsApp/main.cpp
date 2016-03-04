#include <QCoreApplication>
#include "application.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);

    Application app;
    app.viewMainMenu();
    int x,y = 10;

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
    app.paintField(x,y,field);


    return a.exec();
}

