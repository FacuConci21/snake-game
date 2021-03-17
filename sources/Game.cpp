#include "Game.hpp"

void Game::Welcome()
{
    __utils::GoToXY(10, 10);
    cout << "========================================" << endl;
    __utils::GoToXY(15, 11);
    cout << "WELCOME TO THE SNAKE GAME:" << endl;
    __utils::GoToXY(20, 12);
    cout << "by Facundo Conci" << endl;
    __utils::GoToXY(10, 13);
    cout << "========================================" << endl;

    __utils::GoToXY(0, 20);
    cout << "press any key" << endl;
    _getch();
}

int Game::GameLoop()
{
    SSnakeSegment sSnakeHead = {'@', N_SCREENCENTER_X, N_SCREENCENTER_Y};

    sScore = {"score: ", 0};
    lstSnake = {
        sSnakeHead,
        {'#', {sSnakeHead.ptSegmentPosition.x + 1, sSnakeHead.ptSegmentPosition.y + 0}},
        {'#', {sSnakeHead.ptSegmentPosition.x + 2, sSnakeHead.ptSegmentPosition.y + 0}},
        {'#', {sSnakeHead.ptSegmentPosition.x + 3, sSnakeHead.ptSegmentPosition.y + 0}},
        {'#', {sSnakeHead.ptSegmentPosition.x + 4, sSnakeHead.ptSegmentPosition.y + 0}},
    };

    srand((unsigned)time(NULL));

    system("cls");

    Welcome();

    while (bInGame)
    {
        sFood.x = (rand() % N_SCREENWIDTH);
        sFood.y = (rand() % (N_SCREENHEIGHT - 3)) + 3;
        // Timing & input

        // Game Logic

        // Display
        system("cls");
        DrawStat();
        DrawFood();
        DrawSnake();

        if (_getch() == KEY_ESCAPE)
            break;
    }

    return 0;
}