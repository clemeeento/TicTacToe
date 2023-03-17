#include <iostream>
#include "board.hpp"
#include "figures.hpp"
#include "game.hpp"

using namespace std;


int main()
{
    Board B;
    Game G;

    int positionLX;
    int positionLY;
    int positionRX;
    int positionRY;

    sf::RenderWindow window(sf::VideoMode(W,H), "TicTacToe");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //window.clear(sf::Color::Black);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            positionLX = sf::Mouse::getPosition(window).x;
            positionLY = sf::Mouse::getPosition(window).y;
            int positionL = convertMousePosition(positionLX,positionLY);
            if(positionL!=-1) 
            {   
                if(G.isValidePostition(positionL)==1)
                {
                    G.actualisationElements(positionL,1);
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            positionRX = sf::Mouse::getPosition(window).x;
            positionRY = sf::Mouse::getPosition(window).y;
            int positionR = convertMousePosition(positionRX,positionRY);
            if(positionR!=-1) 
            {   
                if(G.isValidePostition(positionR)==1)
                {
                    G.actualisationElements(positionR,2);
                }
            }
        }
        
        B.display(window) ;
        G.display(window);

        window.display();
        
    }
    return 0;
}