#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
public:
    Application();
    const  int viewMainMenu();
    const void startGame(int difficulty);
    const  int enterDifficulty();
    const int paintField(int x, int y, int** field);
    int difficulty;



};

#endif // APPLICATION_H
