all :  TicTacToe board.o figures.o game.o

board.o : board.hpp board.cpp
	g++ -c board.cpp -lsfml-graphics -lsfml-window -lsfml-system

figures.o : figures.hpp figures.cpp
	g++ -c figures.cpp -lsfml-graphics -lsfml-window -lsfml-system

game.o : game.hpp game.cpp
	g++ -c game.cpp

TicTacToe : TicTacToe.cpp board.cpp figures.cpp game.cpp board.hpp figures.hpp game.hpp
	g++ -o TicTacToe TicTacToe.cpp board.cpp figures.cpp game.cpp -lsfml-graphics -lsfml-window -lsfml-system