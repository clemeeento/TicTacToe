#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "figures.hpp"

using namespace std;

Cross::Cross()
{
    this->hlines = sf::VertexArray (sf::Lines, 2);
    this->blines = sf::VertexArray (sf::Lines, 2);
}

void Cross::draw(int x,int y)
{
    this->hlines[0].position = sf::Vector2f(x-0.3*(W/3),y+0.3*(H/3));
    this->hlines[1].position = sf::Vector2f(x+0.3*(W/3),y-0.3*(H/3));

    this->blines[0].position = sf::Vector2f(x-0.3*(W/3),y-0.3*(H/3));
    this->blines[1].position = sf::Vector2f(x+0.3*(W/3),y+0.3*(H/3));
}

void Cross::display(int x,int y)
{
    sf::RenderWindow window(sf::VideoMode(W, H), "TicTacToe");
    draw(x,y);
    window.draw(hlines);
    window.draw(blines);

    window.display();
}