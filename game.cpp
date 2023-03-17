#include <iostream>
#include "board.hpp"
#include "figures.hpp"
#include "game.hpp"

using namespace std;


void Game::actualisationElements(int pos, char nomElement)
{
    if(nomElement=="Cross") element[pos]=1;
    if(nomElement=="Dot") element[pos]=2;
}

