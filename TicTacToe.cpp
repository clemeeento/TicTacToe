#include "board.hpp"
#include "figures.hpp"

int main()
{
    Board D;
    D.display();

    Cross C;
    C.display(W/2,H/2);

    return 0;
}