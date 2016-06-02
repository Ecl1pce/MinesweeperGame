#ifndef APPLICATION_H
#define APPLICATION_H

#include "field.h"
class Application
{
public:
    Application();

    /**
     * @brief viewMainMenu Отоьпажает главное меню
     * @return 0 в случае отработки
     */
    int viewMainMenu() const;

    /**
     * @brief startGame Запускает игру
     */
    void startGame();

    int enterDifficulty();

    /**
     * @brief paintField Рисует в консоли поле
     * @param field Поле, которое надо отрисовать
     * @return 0 в случае успеха
     */
    int paintField(Field field);

    /**
     * @brief open Открывает ячейку  все соседние пустые в радиусе 1
     * @param x 1 координата
     * @param у 2 координата
     */
    void open(int x, int y);

    /**
     * @brief setFlag Устанавливает флаг по заданным координатам
     * @param x 1 координата
     * @param y 2 координата
     */
    void setFlag(int x, int y);

    /**
     * @brief checkLose Проверка на конец игры (поражение)
     */
    void checkLose();

    /**
     * @brief checkWin Проверка на конец игры (победа)
     */
    void checkWin();

protected:
    /**
     * @brief calculateFlagsLeft Высчитывает количетво оставшихся флагов
     * @return Количество флагов
     */
    int calculateFlagsLeft();

    /**
     * @brief calculateMinesLeft Высчитывает количетво оставшихся мин
     * @return Количество мин
     */
    int calculateMinesLeft();

    /**
     * @brief help Выводит доступные команды и справку по игре
     */
    void help();

    /**
     * @brief enterCommands Ввод команд
     */
    void enterCommands();
    void noManyFlags();

    int difficulty;
    Field* appField;
    int x;
    int y;
    int minesLeft;  
    int facticalMinesNumber;
    int flagsLeft;
    string command;
    bool isWin;
    bool gameActiv;
    int sizeX;
    int sizeY;
    int mines;
};

#endif // APPLICATION_H
