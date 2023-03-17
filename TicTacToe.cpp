#include "board.hpp"
#include "figures.hpp"

int main()
{
    Board B;
    Cross C;
    Dot D(RADIUS);

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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            int positionLX = sf::Mouse::getPosition(window).x;
            int positionLY = sf::Mouse::getPosition(window).y;
            int *positionL = convertMousePosition(positionLX,positionLY);
            if(positionL[2]!=-1) C.display(window,positionL[0],positionL[1]);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            int positionRX = sf::Mouse::getPosition(window).x;
            int positionRY = sf::Mouse::getPosition(window).y;
            int *positionR = convertMousePosition(positionRX,positionRY);
            if(positionR[2]!=-1) D.display(window,positionR[0],positionR[1]);
        }

        //window.clear(sf::Color::Black);

        B.display(window) ;

        window.display();
    }
    return 0;
}