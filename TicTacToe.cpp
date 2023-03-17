#include <iostream>
#include "board.hpp"
#include "figures.hpp"
#include "game.hpp"

using namespace std;


int main()
{
    Board B;
    Game G;

    int positionX;
    int positionY;
    int position;
    int positionRY;
    int tour =0;

    sf::RenderWindow window(sf::VideoMode(W,H), "TicTacToe");

    while (window.isOpen() && G.partieFinie()==0)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //window.clear(sf::Color::Black);
        if(tour%2==0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            positionX = sf::Mouse::getPosition(window).x;
            positionY = sf::Mouse::getPosition(window).y;
            position = convertMousePosition(positionX,positionY);
            if(position!=-1) 
            {   
                if(G.isValidePostition(position)==1)
                {
                    G.actualisationElements(position,1);
                    tour=tour+1;
                }
            }
        }
        if(tour%2!=0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            positionX = sf::Mouse::getPosition(window).x;
            positionY = sf::Mouse::getPosition(window).y;
            position = convertMousePosition(positionX,positionY);
            if(position!=-1) 
            {   
                if(G.isValidePostition(position)==1)
                {
                    G.actualisationElements(position,2);
                    tour=tour+1;
                }
            }
        }
        
        B.display(window) ;
        G.display(window);

        window.display();
        
    }
    return 0;
}