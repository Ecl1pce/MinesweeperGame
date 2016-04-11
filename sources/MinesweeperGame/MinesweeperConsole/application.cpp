#include "application.h"
#include <iostream>
Application::Application()
{

}
Application::enterDifficulty()
{
    std::cin  >> Application::difficulty;
    return difficulty;
}
int Application::paintField(Field field)
{
    cout << "   +0                  +10                 +20                 +30" << endl;
    cout << "   ";
    for (int i = 0; i < 32; i++)
        cout << i % 10 << " ";

    cout << endl;
    for (int i = 0; i < field.getSizeX(); i++)
    {
        if (i < 10)
            cout << i << "  ";
        else cout << i << " ";
        for (int j = 0; j < field.getSizeY(); j++)
        {
            if (field.consField[i][j]->isOpen() == 1)
                std::cout << field.consField[i][j]->getValue() << " ";
            else
                std::cout << "_ ";
        }
        std::cout << std::endl;
    }
    return 0;
}
Application::viewMainMenu()
{
    std::cout << "Good day! It's a MINESWEEPER game." << std::endl;
    std::cout << "Choice your level: (1 - newbie, 2 - gamer, 3 - professional)" << std::endl;
    enterDifficulty();
    std::cout << "HaHa! Level of difficulty, which you have entered, has no effect! The program itself will decide on which field you play!!" << std::endl;
    std::cout << "Lets play a game))00))" << std::endl;
    std::cout << endl;
    std::cout << endl;

    //std::cout << "Process building a field..." << std::endl;

    return 0;
}
void Application::startGame(int difficulty)
{
    string command;

    while (true)
    {
        paintField(appField);
        cout << "Enter command" << endl;
        cin >> command;
        if (command == "exit")
        {
            cout << "Game over, BITCHES" << endl;
            system("pause");
            break;
            system("exit");
        }
        if (command == "open")
        {
            cout << "Enter coordinates of cell, which must be opened" << endl;
            cin >> x >> y;
            appField.consField[x][y]->openCell();
        }
    }

}
