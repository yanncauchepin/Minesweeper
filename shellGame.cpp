#include "shellMinesweeper.hpp"
#include <iostream>

using namespace std ;

void initializeShellMinesweeper(int *height, int *width, int *totalMines) {
  *height = 0 ;
  *width = 0 ;
  *totalMines = 0 ;
  std::cout << "Indiquez une taille valide du démineur (height x width) :\n" ;
  do {
    std::cout << "Height : " ;
    std::cin >> *height ;
  } while (*height <= 0 && *height >= Minesweeper::getMaxHeight()) ;
  do {
    std::cout << "Width : " ;
    std::cin >> *width ;
  } while (*width <= 0 && *width >= Minesweeper::getMaxWidth()) ;
  do {
    std::cout << "Indiquez le nombre totale de mines : " ;
    std::cin >> *totalMines ;
  } while (*totalMines <= 0 && *totalMines >= Minesweeper::getMaxTotalMines()) ;
};

void PlayShellMinesweeper() {
  int *height = new int(0);
  int *width = new int(0) ;
  int *totalMines = new int(0) ;
  initializeShellMinesweeper(height, width, totalMines) ;
  shellMinesweeper* shellminesweeper = new shellMinesweeper(*height,*width,*totalMines) ;
  shellminesweeper->play() ;
};

int main () {
  PlayShellMinesweeper() ;
  return 0 ;
};
