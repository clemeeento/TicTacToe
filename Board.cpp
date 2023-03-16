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
    this->hlines[1].position= sf::Vector2f(w,h/3);
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
