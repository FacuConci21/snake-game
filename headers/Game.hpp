#pragma once

#include <iostream>
#include <conio.h>
#include <list>
#include <cstdlib>
#include <ctime>

#include "__utils.hpp"

using namespace std;

#ifndef GAME_H
#define GAME_H

#define N_SCREENWIDTH 63
#define N_SCREENHEIGHT 23

#define N_SCREENCENTER_X 15
#define N_SCREENCENTER_Y 15

struct SSnakeSegment
{
    char bSegmentCharacter;
    __utils::SPoint ptSegmentPosition;
};

class Game
{
    bool bDead = false;
    bool bInGame;
    int nSnakeLength;

    __utils::SPoint ptSnakeHead;
    list<__utils::SPoint> lsSnake;
    list<SSnakeSegment> lstSnake;
    __utils::SStat sScore;
    __utils::SPoint ptFood;

    inline void SnakeCollision()
    {
        for (auto snk : lsSnake)
        {
            if (ptSnakeHead.x == snk.x && ptSnakeHead.y == snk.y)
            {
                bDead = true;
                break;
            }
        }
    }

    inline void FoodCollision()
    {
        if (ptSnakeHead.x == ptFood.x && ptSnakeHead.y == ptFood.y)
        {
            int foodX = rand() % N_SCREENWIDTH, foodY = (rand() % (N_SCREENHEIGHT - 3)) + 3;

            sScore.nValue += nSnakeLength;

            lsSnake.push_back({lsSnake.back().x, lsSnake.back().y});

            nSnakeLength = lsSnake.size();

            ptFood.x = foodX;
            ptFood.y = foodY;
        }
    }

    inline void DrawSnake()
    {
        for (auto snk : lsSnake)
        {
            __utils::GoToXY(snk.x, snk.y);
            (bDead) ? _putch('x') : _putch('o');
        }
        lsSnake.pop_back();
    }

    inline void DrawStat()
    {
        __utils::GoToXY(0, 0);
        cout << " == " << sScore.sPrintingText << sScore.nValue << " == " << endl;
        // cout << "==============================================";
    }

    inline void DrawFood()
    {
        __utils::GoToXY(ptFood.x, ptFood.y);
        _putch('a');
    }

    inline void UpdateHeadCoords(int _x, int _y)
    {
        ptSnakeHead.x += _x;
        ptSnakeHead.y += _y;

        if (ptSnakeHead.x <= 0)
        {
            ptSnakeHead.x = N_SCREENWIDTH;
        }
        else if (ptSnakeHead.x >= N_SCREENWIDTH)
        {
            ptSnakeHead.x = 0;
        }
        else if (ptSnakeHead.y < 1)
        {
            ptSnakeHead.y = N_SCREENHEIGHT;
        }
        else if (ptSnakeHead.y > N_SCREENHEIGHT)
        {
            ptSnakeHead.y = 1;
        }
    }

public:
    Game(){};
    ~Game(){};

    static void Welcome(int, int);
    int GameLoop();
};

#endif