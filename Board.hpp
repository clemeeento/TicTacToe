#ifndef BOARD_H
#define BOARD_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define W 700
#define H 600

class Board{
    private:
        sf::VertexArray hlines; 
        sf::VertexArray vlines;
    public:
        Board(); 
        void draw(int w, int h); 
        void display(sf::RenderWindow& window);
};

int *convertMousePosition(int x, int y);

#endif