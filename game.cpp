#include <iostream>
#include "game.hpp"

using namespace std;

Game::Game()
{
    int element[9]={0,0,0,0,0,0,0,0,0};
}

void Game::actualisationElements(int pos, int elt)
{   
    if(elt==1) element[pos]=1; //Cross
    if(elt==2) element[pos]=2; //Dot
}

int Game::isValidePostition(int pos)
{
    if(element[pos]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int Game::partieFinie() 
{
    // Check rows
    for (int i = 0; i < 9; i += 3) 
    {
        if (element[i] != 0 && element[i] == element[i+1] && element[i] == element[i+2]) 
        {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (element[i] != 0 && element[i] == element[i+3] && element[i] == element[i+6]) 
        {
            return 1;
        }
    }
    // Check diagonals
    if (element[0] != 0 && element[0] == element[4] && element[0] == element[8]) 
    {
        return 1;
    }
    if (element[2] != 0 && element[2] == element[4] && element[2] == element[6]) {
        return 1;
    }

    // Check if there are any empty spaces left
    for (int i = 0; i < 9; i++) 
    {
        if (element[i] == 0) 
        {
            return 0;
        }
    }
    // If all spaces are filled and no winner, the game is a tie
    return 1;
}