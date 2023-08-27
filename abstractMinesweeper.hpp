#ifndef ABSTRACT_MINESWEEPER_HPP_INCLUDED
#define ABSTRACT_MINESWEEPER_HPP_INCLUDED

#include "abstractBoxe.hpp"
#include <vector>
#include <string>

class Minesweeper {

  public :

    static int& getMaxHeight() ;
    static void setMaxHeight(int maxHeight) ;
    static int& getMaxWidth() ;
    static void setMaxWidth(int maxWidth) ;
    static int getMaxTotalMines(int height=Minesweeper::maxHeight, int width=Minesweeper::maxWidth) ;

    Minesweeper (int height, int width, int totalMines) ; //constructor
    virtual ~Minesweeper () = 0 ; //destructor

    //Methods get attributes
    int getHeight() const ;
    int getWidth() const ;
    int getTotalMines() const ;
    void increaseNbFlag() ;
    void decreaseNbFlag() ;
    int getNbFlag() const ;
    void increaseNbEmptyExhibit() ;
    int getNbEmptyExhibit() const ;
    Boxe* getBoxe(int indexHeight, int indexWidth) const ; //return m_Boxes[h][w] adress or 0 if error.
    bool isRunning() const ;

  protected :

    static int maxHeight;
    static int maxWidth ;

    int m_height ; //number of boxes on the window's height
    int m_width ; //number of boxes on the window's width
    int m_totalMines ; //inferior to total number of boxes
    std::vector<std::vector<Boxe*> > m_Boxes ;
    int m_nbFlag ; //number of flag selected
    int m_nbEmptyExhibit ; // number of boxe exhibit
    bool m_running ; //true while the game is running; become false when winning or failing.


    //initialize minesweeper game
    virtual void initializeBoxes() = 0 ;
    void initializeMines() ;
    void initializeIndicatorBoxes() ;

    //to initialize IndicatorBoxes()
    int getProximityMines(int indexHeight, int indexWidth) ;
    void countProximityMineBoxe(int indexHeight, int indexWidth, int *count) ;

    void spreadEmptyBoxeInArea(int indexHeight, int indexWidth) ; //if selected boxe is empty, show all the empty boxes in the area
    void exhibitBoxeInSpreading(Boxe *boxe) ;
    void exhibitAll () ;

    //check condition loop game
    void run() ; //run the minesweeper game
    void fail () ; //if selected boxe is mine, end the minesweeper game
    bool isWin () ; //check the condition minesweeper game of win

};


#endif //ABSTRACT_MINESWEEPER_HPP_INCLUDED
