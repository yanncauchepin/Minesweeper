#ifndef SHELL_MINESWEEPER_HPP_INCLUDED
#define SHELL_MINESWEEPER_HPP_INCLUDED

#include "abstractMinesweeper.hpp"
#include <string>

enum Mode{Flag, Mine} ;

class shellMinesweeper : public Minesweeper {

  public :

    shellMinesweeper (int height, int width, int totalMines) ; //constructor
    virtual ~shellMinesweeper () ; //destructor

    void initializeBoxes() ;

    std::string getMode() const ;
    void changeMode() ; //switch the mode selection of clickBoxe

    void play() ; //run the minesweeper game
    void getUserChoice(int *choice, int* indexHeight, int* indexWidth) ; //transfer the input choice of the player to run. Either mode selection or minesweeper coordinates.
    void clickBoxe(int indexHeight, int indexWidth) ; //select boxes with coordinates and check mode selection in the private attribute
    void draw(bool hidden=false) const ;
    void fail () ; //if selected boxe is mine, end the minesweeper game
    void checkWin () ; //check the condition minesweeper game of win

  private :
    Mode m_mode ; //type of click between flag or mines

};

#endif //SHELL_MINESWEEPER_HPP_INCLUDED
