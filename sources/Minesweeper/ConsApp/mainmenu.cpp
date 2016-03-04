#include "application.h"
#include <iostream>

Application::viewMainMenu()
{
    std::cout << "Good day! It's a MINESWEEPER game." << std::endl;
    std::cout << "Choice your level: (1 - newbie, 2 - gamer, 3 - professional)" << std::endl;
    getDifficulty();
    std::cout << "Process building a field..." << std::endl;
    return 0;
}
