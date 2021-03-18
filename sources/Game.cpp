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
    int nSnakeDirection = 3;

    ptSnakeHead = {N_SCREENCENTER_X, N_SCREENCENTER_Y};
    SSnakeSegment sSnakeHead = {'@', N_SCREENCENTER_X, N_SCREENCENTER_Y};
    nSnakeLength = 3;
    sScore = {"score: ", 0};

    for (int i = 1; i <= nSnakeLength; i++)
    {
        lsSnake.push_back({ptSnakeHead.x + i, ptSnakeHead.y});
    }

    srand((unsigned)time(NULL));

    system("cls");

    Welcome();
    sFood.x = (rand() % N_SCREENWIDTH);
    sFood.y = (rand() % (N_SCREENHEIGHT - 3)) + 3;
    while (bInGame)
    {

        lsSnake.push_front({ptSnakeHead.x, ptSnakeHead.y});

        // Timing & input
        if (_kbhit())
        {
            switch (_getch())
            {
            case KEY_W:
            {
                if (nSnakeDirection == 1 || nSnakeDirection == 3)
                    nSnakeDirection = 0;
            }
            break;
            case KEY_S:
            {
                if (nSnakeDirection == 1 || nSnakeDirection == 3)
                    nSnakeDirection = 2;
            }
            break;
            case KEY_A:
            {
                if (nSnakeDirection == 0 || nSnakeDirection == 2)
                    nSnakeDirection = 3;
            }
            break;
            case KEY_D:
            {
                if (nSnakeDirection == 0 || nSnakeDirection == 2)
                    nSnakeDirection = 1;
            }
            break;
            case KEY_ESCAPE:
            {
                bInGame = false;
            }
            break;
            default:
                break;
            }
        }

        // Game Logic
        switch (nSnakeDirection)
        {
        case 0: // UP
            UpdateHeadCoords(0, (-1));
            break;
        case 1: // RIGHT
            UpdateHeadCoords(1, 0);
            break;
        case 2: // DOWN
            UpdateHeadCoords(0, (1));
            break;
        case 3: // LEFT
            UpdateHeadCoords((-1), 0);
            break;
        }

        /*      DISPLAY     */
        system("cls");

        DrawStat();

        DrawFood();

        // { // Draw Snake Head.
        //     __utils::GoToXY(lsSnake.front().x, lsSnake.front().y);
        //     (bDead) ? _putch('X') : _putch('x');
        // }

        DrawSnake();

        Sleep(100);
        // if (_getch() == KEY_ESCAPE)
        //     break;
    }

    return 0;
}