#EXECUTIVE PROGRAMS

all : wxGame shellGame

wxGame : wxMinesweeperApp.o wxMinesweeperFrame.o wxMinesweeper.o wxBoxe.o abstractMinesweeper.o abstractBoxe.o
		g++ wxMinesweeperApp.o wxMinesweeperFrame.o wxMinesweeper.o wxBoxe.o abstractMinesweeper.o abstractBoxe.o -o ../wxGame `wx-config --cxxflags` `wx-config --libs`

shellGame : shellGame.o shellMinesweeper.o abstractMinesweeper.o abstractBoxe.o shellBoxe.o
		g++ shellGame.o shellMinesweeper.o abstractMinesweeper.o abstractBoxe.o shellBoxe.o -o ../shellGame

#ABSTRACT CLASS

abstractBoxe.o : abstractBoxe.cpp abstractBoxe.hpp
		g++ -c abstractBoxe.cpp -o abstractBoxe.o

abstractMinesweeper.o : abstractMinesweeper.cpp abstractMinesweeper.hpp
		g++ -c abstractMinesweeper.cpp -o abstractMinesweeper.o

#SHELL FILES

shellGame.o : shellGame.cpp
		g++ -c shellGame.cpp -o shellGame.o `wx-config --cxxflags` `wx-config --libs`

shellMinesweeper.o : shellMinesweeper.cpp shellMinesweeper.hpp
		g++ -c shellMinesweeper.cpp -o shellMinesweeper.o

shellBoxe.o : shellBoxe.cpp shellBoxe.hpp
		g++ -c shellBoxe.cpp -o shellBoxe.o

#WXWIDGETS FILES

wxMinesweeperApp.o : wxMinesweeperApp.cpp wxMinesweeperApp.hpp
		g++ -c wxMinesweeperApp.cpp -o wxMinesweeperApp.o `wx-config --cxxflags` `wx-config --libs`


wxMinesweeperFrame.o : wxMinesweeperFrame.cpp wxMinesweeperFrame.hpp
		g++ -c wxMinesweeperFrame.cpp -o wxMinesweeperFrame.o `wx-config --cxxflags` `wx-config --libs`


wxMinesweeper.o : wxMinesweeper.cpp wxMinesweeper.hpp
		g++ -c wxMinesweeper.cpp -o wxMinesweeper.o `wx-config --cxxflags` `wx-config --libs`

wxBoxe.o : wxBoxe.cpp wxBoxe.hpp
		g++ -c wxBoxe.cpp -o wxBoxe.o `wx-config --cxxflags` `wx-config --libs`

#CLEAN

clean :
		rm *.o ../shellGame ../wxGame
