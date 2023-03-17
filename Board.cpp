#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "board.hpp"

using namespace std;

Board::Board()
{
    this->hlines = sf::VertexArray (sf::Lines, 4);
    this->vlines = sf::VertexArray (sf::Lines, 4);
}   

void Board::draw (int w , int h)
{
    this->hlines[0].position = sf::Vector2f(0,h/3);
    this->hlines[1].position = sf::Vector2f(w,h/3);
    this->hlines[2].position = sf::Vector2f(0, (2*h)/3);
    this->hlines[3].position = sf::Vector2f(w, (2*h)/3);

    this->vlines[0].position = sf::Vector2f(w/3, 0);
    this->vlines[1].position = sf::Vector2f(w/3, h);
    this->vlines[2].position = sf::Vector2f((2*w)/3, 0);
    this->vlines[3].position = sf::Vector2f((2*w)/3, h);
};

void Board::display(sf::RenderWindow& window)
{
    draw(W,H);
    window.draw(hlines);
    window.draw(vlines);
}

int *convertMousePosition(int x, int y)
{
    static int position[2];
    //Ligne 1 Colonne 1
    if(x<W/3 && y<H/3)
    {
        position[0]=W/6;
        position[1]=H/6;
    }
    //Ligne 1 Colonne 2
    if(x>W/3 && x<2*W/3 && y<H/3)
    {
        position[0]=W/2;
        position[1]=H/6;
    }
    //Ligne 1 Colonne 3
    if(x>2*W/3 && y<H/3)
    {
        position[0]=5*W/6;
        position[1]=H/6;
    }

    //Ligne 2 Colonne 1
    if(x<W/3 && y>H/3 && y<2*H/3)
    {
        position[0]=W/6;
        position[1]=H/2;
    }
    //Ligne 2 Colonne 2
    if(x>W/3 && x<2*W/3 && y>H/3 && y<2*H/3)
    {
        position[0]=W/2;
        position[1]=H/2;
    }
    //Ligne 2 Colonne 3
    if(x>2*W/3 && y>H/3 && y<2*H/3)
    {
        position[0]=5*W/6;
        position[1]=H/2;
    }

    //Ligne 3 Colonne 1
    if(x<W/3 && y>2*H/3)
    {
        position[0]=W/6;
        position[1]=5*H/6;
    }
    //Ligne 3 Colonne 2
    if(x>W/3 && x<2*W/3 && y>2*H/3)
    {
        position[0]=W/2;
        position[1]=5*H/6;
    }
    //Ligne 3 Colonne 3
    if(x>2*W/3 && y>2*H/3)
    {
        position[0]=5*W/6;
        position[1]=5*H/6;
    }
    return position;
}
