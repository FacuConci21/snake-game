#include <iostream>

#include "Game.hpp"
#include "Menu.hpp"

using namespace std;

bool bRestart = true;

void StartGame()
{
    // cout << "comienza el juego" << endl;
    Game game;
    game.GameLoop();
}

void QuitGame()
{
    bRestart = false;
    // cout << " adios" << endl;
}

int main()
{

    {
        SItem<void> sStartGame = {"start game", StartGame};
        SItem<void> sQuitGame = {"quit game", QuitGame};

        Menu clsMainMenu({&sStartGame, &sQuitGame}, {(N_SCREENWIDTH / 3), (N_SCREENHEIGHT / 2)});

        system("cls");

        Game::Welcome((N_SCREENWIDTH / 4), (N_SCREENHEIGHT / 4));

        auto ipItem = *clsMainMenu.Loop();

        (ipItem->toDo)();
    }

    if (bRestart)
    {
        main();
    }

    return 0;
}