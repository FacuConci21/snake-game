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

#define N_SCREENWIDTH 100
#define N_SCREENHEIGHT 80

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

    inline void DrawSnake()
    {
        for (SSnakeSegment snk : lstSnake)
        {
            __utils::GoToXY(
                N_SCREENCENTER_X + snk.ptSegmentPosition.x,
                N_SCREENCENTER_Y + snk.ptSegmentPosition.y);
            (bDead) ? _putch('x') : _putch(snk.bSegmentCharacter);
        }
    }

    inline void DrawStat()
    {
        __utils::GoToXY(0, 0);
        cout << sScore.nValue << endl;
        cout << "---------------------";
    }

public:
    Game() : bInGame(true){};
    ~Game(){};

    void Welcome();
    int GameLoop();
};

#endif