#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        int *element;
    public : 
        Game();
        int getElement(int i) {return element[i];};
        void actualisationElements(int pos, int elt);
        int isValidePostition(int pos);
        int partieFinie();
};

#endif