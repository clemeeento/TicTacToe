#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
    private:
        int element[9];
    public : 
        Game();
        void actualisationElements(int pos, int elt);
        int isValidePostition(int pos);
        int partieFinie();
        void display(sf::RenderWindow& window);
        void reset();
        int rejouer();
};

#endif