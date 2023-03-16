#include "board.hpp"
#include "figures.hpp"

int main()
{
    Board B;
    Cross C;
    Dot D(RADIUS);

    sf::RenderWindow window(sf::VideoMode(700, 600), "TicTacToe");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        B.display(window) ;

        C.display(window,W/2,H/2);

        D.display(window,5*W/6,H/2);

        window.display();
    }
    return 0;
}