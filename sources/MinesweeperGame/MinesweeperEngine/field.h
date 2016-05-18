#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include "str_switch.h"

using namespace std;

/**
 * @brief The Field class Класс целого игрового поля, по сути это интерфейс ядра
 */
class Field
{
public:
    Field();
    /**
     * @brief Field Конструктор поля
     * @param sizeX Заданный размер X поля
     * @param sizeY Заданный размер Y поля
     * @param minesNumber Желаемое количество мин
     */
    Field(int sizeX, int sizeY, int minesNumber);

    /**
     * @brief openAllCells Открывает все ячейки поля
     */
    void openAllCells();

    /**
     * @brief checkValidCoord Проверяет верность координат
     * @param coord1 Первая координата
     * @param coord2 Вторая координата
     * @return 1 - если координаты валидные, 0 - если нет
     */
    bool checkValidCoord(int coord1, int coord2) const;

    /**
     * @brief random Генерирует случайное число до максимального
     * @param maxValue Максимальное число
     * @return Сгенерированное число
     */
    int random(int maxValue);

    /**
     * @brief getSizeX Возврачает размер Х поля
     * @return Длину поля
     */
    int getSizeX() const;

    /**
     * @brief getSizeY Возвращает размер Y поля
     * @return Ширину поля
     */
    int getSizeY() const;

    /**
     * @brief getMinesNumber Возвращает количество мин на поле
     * @return Количество мин всего на поле
     */
    int getMinesNumber() const;

    /**
     * @brief getPieceOfField Интерфейс для доступа к конкретной ячейе поля по заданным координатам
     * @param x Первая координата
     * @param y Вторая координата
     * @return Объект Cell - конкретную ячейку поля
     */
    Cell getPieceOfField(int x, int y);

    /**
     * @brief openCellsAround Открывает ячейку и все пустые ячейки в радиусе 1 клетка
     * @param x Первая координата
     * @param y Вторая координата
     */
    void open(int x, int y);

    /**
     * @brief isLose Проверяет, проиграна ли игра
     * @return 1 - если проиграна, 0 - если нет
     */
    bool isLose();

    /**
     * @brief isGameActive Проверяет, продолжается ли игра
     * @return 1 - если продолжается, 0 - если нет
     */
    bool isGameActive();

    /**
     * @brief setFlag Устанавливает флаг по заданным координатам
     * @param x Первая координата
     * @param y Вторая координата
     */
    void setFlag(int x, int y);
    bool gameActive;

    Cell* getCell(int x, int y);

    int minesLeft;
    int cellsLeft;
    int flagsLeft;

protected:
    /**
     * @brief setValuesInCells Устанавливает значение в клетке по заданным координатам равное количеству мин вокруг в радиусе 1 клетка
     * @param x Первая координата
     * @param y Вторая координата
     */
    void setValuesInCells(int x, int y);

    /**
     * @brief spawnMines Рандомно спавнит мины на поле
     * @return Количество заспавненных мин
     */
    int spawnMines();

    /**
     * @brief consField Собственно, само игровое поле, вектор из объектов типа "ячейка"
     */
    vector<vector<Cell> > consField;

    /**
     * @brief fieldSizeX размер Х поля
     */
    int fieldSizeX;

    /**
     * @brief fieldSizeY Размер Y поля
     */
    int fieldSizeY;

    /**
     * @brief minesNumber Количество мин на поле
     */
    int minesNumber;

    /**
     * @brief loseFlag Флаг, отвечающий за поражение в игре
     */
    bool loseFlag;


    void calculateMinesLeft();
    void calculateCellsLeft();
    void calculateFlagsLeft();


};

#endif // FIELD_H
