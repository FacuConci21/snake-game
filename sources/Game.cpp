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
    sScore = {"score: ", 0};
    lstSnake = {
        {'@', {0, 0}},
        {'#', {1, 0}},
        {'#', {2, 0}},
        {'#', {3, 0}},
        {'#', {4, 0}},
    };

    srand(time(0));

    system("cls");

    Welcome();

    while (bInGame)
    {
        system("cls");

        // Timing & input

        // Game Logic

        // Display

        DrawStat();
        DrawSnake();

        _getch();
    }

    return 0;
}