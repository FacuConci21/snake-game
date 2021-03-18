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
    srand((unsigned)time(NULL));

    int nSnakeDirection = 3;
    ptSnakeHead = {N_SCREENCENTER_X, N_SCREENCENTER_Y};
    SSnakeSegment sSnakeHead = {'@', N_SCREENCENTER_X, N_SCREENCENTER_Y};
    nSnakeLength = 10;
    sScore = {"score: ", 0};
    ptFood.x = (rand() % N_SCREENWIDTH);
    ptFood.y = (rand() % (N_SCREENHEIGHT - 3)) + 3;

    for (int i = 1; i <= nSnakeLength; i++)
    {
        lsSnake.push_back({ptSnakeHead.x + i, ptSnakeHead.y});
    }

    system("cls");

    Welcome();

    /*      GAME LOOP       */
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
                return 0;
            default:
                break;
            }
        }

        /* Game Logic   */

        // Collision
        FoodCollision();

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

        SnakeCollision();

        if (bDead)
        {
            bInGame = false;
        }

        /*      DISPLAY     */
        system("cls");

        DrawStat();

        DrawFood();

        DrawSnake();

        Sleep((nSnakeDirection % 2 == 0) ? 170 : 100);
    }

    return 0;
}