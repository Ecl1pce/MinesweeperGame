#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
public:
    Application();
    int viewMainMenu();
    int difficulty;
    void startGame(int difficulty);
    int enterDifficulty();
    int paintField(int x, int y, int** field);



};

#endif // APPLICATION_H
