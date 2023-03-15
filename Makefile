all :  TicTacToe board.o

board.o : board.hpp board.cpp
	g++ -c board.cpp -lsfml-graphics -lsfml-window -lsfml-system

TicTacToe : TicTacToe.cpp board.cpp board.hpp
	g++ -o TicTacToe TicTacToe.cpp board.cpp -lsfml-graphics -lsfml-window -lsfml-system