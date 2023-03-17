#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
    private:
        int elements[9]={0,0,0,0,0,0,0,0,0};
    public : 
        void actualisationElements(int pos, char nomElement);
};

#endif