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

void Cross::display(sf::RenderWindow& window,int i)
{
    int x=(W*(1+(i%3)*2))/6;
    int y=(H*(1+(i/3)*2))/6;

    draw(x,y);
    window.draw(hlines);
    window.draw(blines);
}

Dot::Dot(int radius)
{
    this->cercle = sf::CircleShape (radius);
}

void Dot::draw(int x, int y)
{
    cercle.setPosition(x,y);
}

void Dot::display(sf::RenderWindow& window,int i)
{   
    int x=(W*(1+(i%3)*2))/6;
    int y=(H*(1+(i/3)*2))/6;
    
    draw(x-0.9*RADIUS,y-RADIUS);
    window.draw(cercle);
}