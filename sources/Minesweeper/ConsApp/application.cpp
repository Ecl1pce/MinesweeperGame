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
Application::paintField(int x, int y, int** field)
{
    for (int i = 0; i < x; i++)
    {

        for (int j = 0; j < y; j++)
        {
            if (field[i][j] == 0)
            std::cout << "_ ";
            if (field[i][j] == 1)
            std::cout << field[i][j];
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
    std::cout << "Process building a field..." << std::endl;
    return 0;
}
