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
    list<SSnakeSegment> lstSnake;
    __utils::SStat sScore;
    __utils::SPoint sFood;

    inline void DrawSnake()
    {
        for (SSnakeSegment snk : lstSnake)
        {
            __utils::GoToXY(snk.ptSegmentPosition.x, snk.ptSegmentPosition.y);
            (bDead) ? _putch('x') : _putch(snk.bSegmentCharacter);
        }
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

public:
    Game() : bInGame(true){};
    ~Game(){};

    void Welcome();
    int GameLoop();
};

#endif