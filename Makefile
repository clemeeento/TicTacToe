all :  TicTacToe

board: Board.hpp Board.cpp
	g++ -c Board.cpp -lsfml-graphics -lsfml-window -lsfml-system