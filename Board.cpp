#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "board.hpp"

using namespace std;

#define W 800
#define H 600

Board::Board()
{
    this->hlines = sf::VertexArray (sf::Lines, 4);
    this->vlines = sf::VertexArray (sf::Lines, 4);
}

void Board::draw (int w , int h){

//horizontales
this->hlines[0].position = sf::Vector2f(0,w/3);
this->hlines[1].position= sf::Vector2f(w,w/3);
this->hlines[2].position = sf::Vector2f(0, 2*w/3);
this->hlines[3].position = sf::Vector2f(h, 2*w/3);

        // Ligne verticale de gauche
this->vlines[0].position = sf::Vector2f(h/3, 0);
this->vlines[1].position = sf::Vector2f(h/3, h);
this->vlines[2].position = sf::Vector2f((2*h)/3, 0);
this->vlines[3].position = sf::Vector2f((2*h)/3, h);
};

void Board::display(){
    
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(W, H), "TicTacToe");

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
        draw(W,H);
        window.draw(hlines);
        window.draw(vlines);

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }
}
