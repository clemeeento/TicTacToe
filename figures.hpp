#ifndef FORMES_H
#define FORMES_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

#define RADIUS 60

class Cross
{
    private:
        sf::VertexArray hlines; 
        sf::VertexArray blines;
    public:
        Cross();
        void display(sf::RenderWindow& window,int i);
        void draw(int x, int y); 
};

class Dot
{
    private:
        sf::CircleShape cercle;
    public:
        Dot(int radius);
        void draw(int x, int y);
        void display(sf::RenderWindow& window, int i);
};

#endif