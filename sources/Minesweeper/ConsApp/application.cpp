#include "application.h"
#include <iostream>
Application::Application()
{

}
Application::getDifficulty()
{
   std::cin  >> difficulty;
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
            if (field[i][j] != 0)
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}
