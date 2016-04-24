#include "application.h"
#include <iostream>
Application::Application()
{
isWin = 0;
}
int Application::enterDifficulty()
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
            if (field.getPieceOfField(i, j).isFlag())
                std::cout << "F" << " ";
            else if (field.getPieceOfField(i, j).isOpen())
            {
                if (field.getPieceOfField(i, j).isMine())
                    std::cout << "M" << " ";
                else
                    std::cout << field.getPieceOfField(i, j).getValue() << " ";
            }
            else
                std::cout << "_ ";
        }
        std::cout << std::endl;
    }
    std::cout << "Mines left: " << minesLeft << endl;
    std::cout << "Flags left: " << flagsLeft << endl;
    //std::cout << endl;


    return 0;
}
int Application::viewMainMenu() const
{
    std::cout << "Good day! It's a MINESWEEPER game." << std::endl << std::endl;
//    std::cout << "Choice your level: (1 - newbie, 2 - gamer, 3 - professional)" << std::endl;
//    enterDifficulty();
//    std::cout << "HaHa! Level of difficulty, which you have entered, has no effect!" << std::endl;
    std::cout << "The program itself will decide on which field you play!!" << std::endl;
    std::cout << "Lets play a game))00))" << std::endl << std::endl;
    system("pause");
    std::cout << endl;
    std::cout << endl;
    return 0;
}
void Application::startGame()
{
    sizeX = 16;
    sizeY = 32;
    mines = 50;
    isWin = 0;
    appField = new Field(sizeX, sizeY, mines);
    facticalMinesNumber = calculateMinesLeft();
    flagsLeft = facticalMinesNumber;
    while (appField->isGameActive())
    {
        paintField(*appField);
        enterCommands();
    }
    std::cout << "Would you like try again? Y/N" << std::endl;
    cin >> command;
    if (command != "y" && command != "Y")
        exit(0);
}
void Application::open(int x, int y)
{
    appField->openCellsAround(x,y);
    checkLose();
    calculateMinesLeft();
}
int Application::calculateMinesLeft()
{
    minesLeft = 0;
    for (int i = 0; i < appField->getSizeX(); i++)
        for (int j = 0; j < appField->getSizeY(); j++)
            if (appField->getPieceOfField(i, j).isMine() && appField->getPieceOfField(i, j).isFlag() == 0)
                minesLeft++;
    return minesLeft;

}
int Application::calculateFlagsLeft()
{
    flagsLeft = facticalMinesNumber;
    return flagsLeft;

}
void Application::setFlag(int x, int y)
{
    if (flagsLeft > 0)
    {
    appField->setFlag(x, y);
    if (appField->getPieceOfField(x, y).isFlag())
        flagsLeft--;
    else flagsLeft++;
    }
    else noManyFlags();
    calculateMinesLeft();
    checkWin();
}
void Application::help()
{
    std::cout << "   Command list: " << std::endl;
    std::cout << "1. open - for open cell with coordinates X and Y. Press /enter/ between entering first and second coordinates" << std::endl;
    std::cout << "2. flag - for set flag in cell with coordinates X and Y. Press /enter/ between entering first and second coordinates" << std::endl;
    std::cout << "3. exit - for close app" << std::endl;
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
        appField->openAllCells();
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
}
void Application::checkLose()
{
    std::string command;
    if (appField->isLose())
    {
        appField->openAllCells();
        paintField(*appField);
        cout << endl;
        cout << "!!!You lose!!!" << endl;
        appField->gameActive = 0;

    }
}
void Application::checkWin()
{
    if (minesLeft < 1)
        isWin = 1;
    if (isWin)
    {
        std::cout << "GRATULATIONS!!! YOU WIN" << std::endl;
        appField->gameActive = 0;
    }
}
