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
#define N_SCREENHEIGHT 43

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
    __utils::SPoint sFood;

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
        __utils::GoToXY(sFood.x, sFood.y);
        _putch('a');
    }

    inline void UpdateHeadCoords(int _x, int _y)
    {
        ptSnakeHead.x += _x;
        ptSnakeHead.y += _y;

        if (ptSnakeHead.x <= 0)
        {
            ptSnakeHead.x = 0;
        }
        else if (ptSnakeHead.x >= N_SCREENWIDTH)
        {
            ptSnakeHead.x = N_SCREENWIDTH;
        }
        else if (ptSnakeHead.y <= 0)
        {
            ptSnakeHead.y = 0;
        }
        else if (ptSnakeHead.y >= N_SCREENWIDTH)
        {
            ptSnakeHead.y = N_SCREENWIDTH;
        }
    }

public:
    Game() : bInGame(true){};
    ~Game(){};

    void Welcome();
    int GameLoop();
};

#endif