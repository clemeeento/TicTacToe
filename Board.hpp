#ifndef BOARD_H
#define BOARD_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Board{
    private:
        sf::VertexArray hlines; 
        sf::VertexArray vlines;
    public:
        Board(); // constructor 
        void draw(int w, int h); 
        void display();
};

#endif