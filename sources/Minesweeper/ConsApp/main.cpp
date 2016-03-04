#include <QCoreApplication>
#include "application.h"
#include <iostream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QCoreApplication a(argc, argv);

    Application app;

    app.viewMainMenu();
    const int FIELD_SETTING_X = 10;             // Переменная для задания пропорциональности между выбранной сложостью и размером поля по вертикали
    const int FIELD_SETTING_Y = 10;             // Переменная для задания пропорциональности между выбранной сложостью и размером поля по горизонтали


    int **field = new int *[FIELD_SETTING_X * app.difficulty];    // !!!!!!!!!!!!!!! Все начиная отсюда !!!!!!!!!!!!!!!!
    for (int i = 0; i < FIELD_SETTING_X * app.difficulty; i++)    //
    {
      field[i] = new int [FIELD_SETTING_Y * app.difficulty];      //      Так как проект с ядром пока редактировать не хочу
    }

    for (int i = 0; i < FIELD_SETTING_X * app.difficulty; i++)    // Что мы тут делаем:
    {                                                             //  1) Создаем двумерный инт массив(в ядре так будет представлено поле)
        for (int j = 0; j < FIELD_SETTING_Y * app.difficulty; j++)//  2) Заполняем его нулями, чтобы проверить как это дело рисуется
        {
            field[i][j] = 0;                                      //###################################################################################################
        }                                                         //    !!! Для справки что значат цифры в массиве !!!
    }                                                             //           0 - ячейка не открыта
    for (int i = 0; i < FIELD_SETTING_X * app.difficulty; i++)    //           1 - ячейка открыта
    {                                                             //           2 - на ячейке установлен флаг
        for (int j = 0; j < FIELD_SETTING_Y * app.difficulty; j++)//           3 - на ячейке установлен вопрос
        {                                                         //           4 - ячейка заминирована
            std::cout << field[i][j];                             //###################################################################################################
        }
        std::cout << std::endl;                                   // !!!!!!!!!!!!!!!!!!! И до сюда - это кусок ядра для проверки работоспособности отрисовки поля !!!!!!!!!!!!
    }
    app.paintField(FIELD_SETTING_X * app.difficulty, FIELD_SETTING_Y * app.difficulty,field);


    return a.exec();
}

