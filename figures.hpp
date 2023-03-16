#ifndef FORMES_H
#define FORMES_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Cross{
    private:
        sf::VertexArray hlines; 
        sf::VertexArray blines;
    public:
        Cross();
        void display(int x, int y);
        void draw(int x, int y); 
};

#endif