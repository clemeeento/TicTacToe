#include "board.hpp"
#include "figures.hpp"

int main()
{
     // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(700, 600), "TicTacToe");

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        //on dessine
        Board D;
        D.display(window) ;

        Cross C;
        C.display(window,W/2,H/2);

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }
    
    

    return 0;
}