#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "figures.hpp"


using namespace std;

Game::Game()
{
    for(int i=0;i<9;i=i+1)
    {
        element[i]=0;
    }
}

void Game::actualisationElements(int pos, int elt)
{   
    if(elt==1) element[pos]=1; //Cross
    if(elt==2) element[pos]=2; //Dot
}

int Game::isValidePostition(int pos)
{
    if(element[pos]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int Game::partieFinie() 
{
    // Check rows
    for (int i = 0; i < 9; i += 3) 
    {
        if (element[i] != 0 && element[i] == element[i+1] && element[i] == element[i+2]) 
        {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (element[i] != 0 && element[i] == element[i+3] && element[i] == element[i+6]) 
        {
            return 1;
        }
    }
    // Check diagonals
    if (element[0] != 0 && element[0] == element[4] && element[0] == element[8]) 
    {
        return 1;
    }
    if (element[2] != 0 && element[2] == element[4] && element[2] == element[6]) {
        return 1;
    }

    // Check if there are any empty spaces left
    for (int i = 0; i < 9; i++) 
    {
        if (element[i] == 0) 
        {
            return 0;
        }
    }
    // If all spaces are filled and no winner, the game is a tie
    return 1;
}

void Game::display(sf::RenderWindow& window)
{
    Cross C;
    Dot D(RADIUS);
    for(int i=0; i<9;i=i+1)
    {
        if(element[i]==1)
        {
            C.display(window,i);
        }
        if(element[i]==2)
        {
            D.display(window,i);
        }
    }
}

void Game::reset()
{
    for(int i=0;i<9;i=i+1)
    {
        element[i]=0;
    }
}

int Game::rejouer()
{
    int rejouer =0;
    
    sf::RenderWindow window(sf::VideoMode(400, 200), "Rejouer ?");

    sf::Font font;
    if (!font.loadFromFile("Lucia.ttf")) {
        std::cerr << "Erreur lors du chargement de la police d'ecriture" << std::endl;
        return rejouer;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(50, 50);

    /*if (player_won) {
        text.setString("Vous avez gagné !");
    } else {
        text.setString("Vous avez perdu !");
    }*/

    sf::RectangleShape quit_button(sf::Vector2f(100, 50));
    quit_button.setPosition(50, 100);
    quit_button.setFillColor(sf::Color::Red);

    sf::Text quit_text;
    quit_text.setFont(font);
    quit_text.setCharacterSize(18);
    quit_text.setFillColor(sf::Color::White);
    quit_text.setString("Quitter");
    quit_text.setPosition(60, 110);

    sf::RectangleShape replay_button(sf::Vector2f(100, 50));
    replay_button.setPosition(250, 100);
    replay_button.setFillColor(sf::Color::Green);

    sf::Text replay_text;
    replay_text.setFont(font);
    replay_text.setCharacterSize(18);
    replay_text.setFillColor(sf::Color::White);
    replay_text.setString("Rejouer");
    replay_text.setPosition(260, 110);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (quit_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                    }
                    if (replay_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        return 1;
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.draw(quit_button);
        window.draw(quit_text);
        window.draw(replay_button);
        window.draw(replay_text);
        window.display();
    }
    return rejouer;
}