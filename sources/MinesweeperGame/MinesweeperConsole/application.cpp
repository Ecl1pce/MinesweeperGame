#include "application.h"
#include <iostream>
Application::Application()
{
isWin = 0;
}
Application::enterDifficulty()
{
    std::cin  >> Application::difficulty;
    return difficulty;
}
int Application::paintField(Field field)
{
    cout << "    +0                  +10                 +20                 +30" << endl;
    cout << "    ";
    for (int i = 0; i < 32; i++)
        cout << i % 10 << " ";

    cout << endl;
    cout << endl;

    for (int i = 0; i < field.getSizeX(); i++)
    {
        if (i < 10)
            cout << i << "   ";
        else cout << i << "  ";
        for (int j = 0; j < field.getSizeY(); j++)
        {
            if (field.consField[i][j]->isFlag())
                std::cout << "F" << " ";
            else if (field.consField[i][j]->isOpen())
            {
                if (field.consField[i][j]->isMine())
                    std::cout << "M" << " ";
                else
                    std::cout << field.consField[i][j]->getValue() << " ";
            }
            else
                std::cout << "_ ";
        }
        std::cout << std::endl;
    }
    std::cout << "Mines left: " << minesLeft << endl;
    std::cout << "Flags left: " << flagsLeft << endl;


    return 0;
}
Application::viewMainMenu()
{
    std::cout << "Good day! It's a MINESWEEPER game." << std::endl;
    std::cout << "Choice your level: (1 - newbie, 2 - gamer, 3 - professional)" << std::endl;
    enterDifficulty();
    std::cout << "HaHa! Level of difficulty, which you have entered, has no effect! The program itself will decide on which field you play!!" << std::endl;
    std::cout << "Lets play a game))00))" << std::endl;
    system("pause");
    std::cout << endl;
    std::cout << endl;
    return 0;
}
void Application::startGame()
{
    facticalMinesNumber = calculateMinesLeft(appField);
    calculateFlagsLeft();
    while (appField.isGameActive())
    {
        if (isWin)
        {
            std::cout << "GRATULATIONS!!! YOU WIN" << std::endl;
            break;
        }
        calculateMinesLeft(appField);
        paintField(appField);
        enterCommands();
    }

}
void Application::open(int x, int y)
{
    appField.openCellsAround(x,y);
    if (appField.lose())
    {
        cout << "You lose" << endl;
        appField.openAllCells();
        paintField(appField);
        appField.gameActive = 0;
    }
}
int Application::calculateMinesLeft(Field field)
{
    minesLeft = 0;
    for (int i = 0; i < field.getSizeX(); i++)
        for (int j = 0; j < field.getSizeY(); j++)
            if (field.consField[i][j]->isMine() && field.consField[i][j]->isFlag() == 0)
                minesLeft++;
    return minesLeft;

}
int Application::calculateFlagsLeft()
{
    flagsLeft = facticalMinesNumber;
//    for (int i = 0; i < field.getSizeX(); i++)
//        for (int j = 0; j < field.getSizeY(); j++)
//            if (field.consField[i][j]->isFlag())
//                flagsLeft--;
    return flagsLeft;

}
void Application::setFlag(int x, int y)
{
    if (flagsLeft > 0)
    {
    appField.consField[x][y]->swapFlag();
    if (appField.consField[x][y]->isFlag())
        flagsLeft--;
    else flagsLeft++;
    }
    else noManyFlags();
}
void Application::help()
{
    std::cout << "   Command list: " << std::endl;
    std::cout << "open - for open cell with coordinates X and Y. Press /enter/ between entering first and second coordinates" << std::endl;
    std::cout << "flag - for set flag in cell with coordinates X and Y. Press /enter/ between entering first and second coordinates" << std::endl;
    std::cout << "exit - for close app" << std::endl;
    system("pause");
//    std::cout << "" << std::endl;
//    std::cout <<  << std::endl;
//    std::cout <<  << std::endl;

}
void Application::noManyFlags()
{
    std::cout << "You haven't flags more" << std::endl;
}
void Application::enterCommands()
{
    cout << "Enter command" << endl;
    cin >> command;
    SWITCH (command)
    {
    CASE ("exit"):
        cout << "Game over" << endl;
        exit(0);
        break;
    CASE ("open"):
        cout << "Enter coordinates of cell, which must be opened" << endl;
        cin >> y >> x;
        open(x, y);
        break;
    CASE ("openall"):
        appField.openAllCells();
        break;
    CASE ("flag"):
        cout << "Enter coordinates of cell, where you want set flag" << endl;
        cin >> y >> x;
        setFlag(x, y);
        break;
    CASE ("help"):
         help();
        break;
    DEFAULT:
        help();
    }
//    if (command == "exit")
//    {
//        cout << "Game over" << endl;
//        exit(0);
//    }
//    if (command == "open")
//    {
//        cout << "Enter coordinates of cell, which must be opened" << endl;
//        cin >> y >> x;
//        open(x, y);
//    }
//    if (command == "openall")
//    {
//        appField.openAllCells();
//    }
//    if (command == "flag")
//    {
//        cout << "Enter coordinates of cell, where you want set flag" << endl;
//        cin >> y >> x;
//        setFlag(x, y);
//    }
//    if (command == "help")
//        help();
}
