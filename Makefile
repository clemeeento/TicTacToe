all :  TicTacToe board.o figures.o

board.o : board.hpp board.cpp
	g++ -c board.cpp -lsfml-graphics -lsfml-window -lsfml-system

figures.o : figures.hpp figures.cpp
	g++ -c figures.cpp -lsfml-graphics -lsfml-window -lsfml-system

TicTacToe : TicTacToe.cpp board.cpp figures.cpp board.hpp figures.hpp
	g++ -o TicTacToe TicTacToe.cpp board.cpp figures.cpp -lsfml-graphics -lsfml-window -lsfml-system