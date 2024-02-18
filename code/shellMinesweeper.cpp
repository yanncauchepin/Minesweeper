#include "shellBoxe.hpp"
#include "shellMinesweeper.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

shellMinesweeper::shellMinesweeper(int height, int width, int totalMines) : Minesweeper(height, width, totalMines), m_mode(Mine) {
  shellMinesweeper::initializeBoxes() ;
  Minesweeper::initializeMines() ;
  Minesweeper::initializeIndicatorBoxes() ;
};

shellMinesweeper::~shellMinesweeper() {
};

void shellMinesweeper::initializeBoxes() {
  for(int h(0) ; h < m_height ; h ++) {
    m_Boxes.push_back(std::vector<Boxe*>(m_width)) ;
  }
  for (int h(0) ; h < m_height ; h ++) {
    for (int w(0) ; w < m_width ; w++) {
      m_Boxes[h][w] = new shellBoxe(h, w) ;
    }
  }
};

void shellMinesweeper::draw(bool hidden) const {
  std::cout << "\n\n- - - - - - MINESWEEPER - - - - - -\n\n" ;
  for(int h(0) ; h < m_height ; h ++) {
    std::cout << "\033[1;34m" << h << "\033[0m " ;
    for (int w(0) ; w < m_width ; w++) {
      shellBoxe *boxe = (shellBoxe*) Minesweeper::getBoxe(h, w) ;
      if (boxe != 0) {
        boxe->draw(hidden) ;
      }
    }
    std::cout << "\n\n" ;
  }
  std::cout << "  " ;
  for (int w(0) ; w < m_width ; w++) {
    std::cout << " \033[1;34m" << w << "\033[0m " ;
  };
  std::cout << "\n\n" ;
};

std::string shellMinesweeper::getMode() const {
  if (m_mode == Mine) {
    return "Mine" ;
  } else {
    return "Flag" ;
  }
};

void shellMinesweeper::play() {
  int *choice = new int(0) ;
  int *height = new int(0) ;
  int *width = new int(0) ;
  Minesweeper::run() ;
  shellMinesweeper::draw(true) ;
  while (m_running) {
    shellMinesweeper::getUserChoice(choice, height, width) ;
    if (*choice == 2) {
      shellMinesweeper::clickBoxe(*height, *width) ;
      shellMinesweeper::checkWin() ;
      shellMinesweeper::draw(true) ;
    }
  }
  draw() ;
  std::cout << " ============== END  ============== \n" ;
};

void shellMinesweeper::getUserChoice(int *choice, int* indexHeight, int* indexWidth) {
  *choice = 0 ;
  do {
    std::cout << "\nChoisissez votre sélection : \n 1 - Le mode de sélection (Flag or Mine)\n 2 - Les coordonnées valides de la case (Deux entiers)\n 3 - Exit Game\n\n" ;
    std::cin >> *choice ;
  } while (*choice <= 0 && *choice > 3) ;
  switch (*choice) {
    case(1) :
      char confirm ;
      std::cout << "Votre mode de sélection actuel est " << shellMinesweeper::getMode() << ". Souhaitez-vous changer ? (Y/n)\n" ;
      std::cin >> confirm ;
      if (confirm =='Y' || confirm =='y') {
        shellMinesweeper::changeMode() ;
        std::cout << "Vous avez changer de mode de sélection pour être en " << shellMinesweeper::getMode() << ".\n " ;
      } else if (confirm != 'n' || confirm =='N') {
        std::cout << "Choix non reconnue.\n" ;
      }
      break ;
    case(2) :
      std::cout << "Sélectionner les coordonnées valides d'une case.\n" ;
      *indexHeight = -1 ;
      *indexWidth = -1 ;
      do {
        std::cout << "Height : " ;
        std::cin >> *indexHeight ;
      } while (*indexHeight < 0 || *indexHeight >= m_height) ;
      do {
        std::cout << "Width : " ;
        std::cin >> *indexWidth ;
      } while (*indexWidth < 0 || *indexWidth >= m_width) ;
      break ;
    case(3) :
      m_running = false ;
      std::cout << "\n\n+ + + + + + + You gave up + + + + + + +\n\n" ;
      break ;
  }
};

void shellMinesweeper::changeMode() {
  if (m_mode == Mine) {
    m_mode = Flag ;
  } else {
    m_mode = Mine ;
  }
};

void shellMinesweeper::clickBoxe(int indexHeight, int indexWidth) {
  shellBoxe *boxe = (shellBoxe*) Minesweeper::getBoxe(indexHeight, indexWidth) ;
  if (boxe != 0) {
    if (m_mode == Mine) {
      if (!boxe->isFlag()){
        if (boxe->containMine()) {
          boxe->exhibit() ;
          shellMinesweeper::fail() ;
        } else {
          if (boxe->getIndicator()==0) {
            Minesweeper::spreadEmptyBoxeInArea(indexHeight, indexWidth) ;
          } else {
            boxe->exhibit() ;
            m_nbEmptyExhibit++ ;
          }
        }
      }
    } else {
      if (boxe->isHidden()) {
        if (boxe->isFlag()) {
          boxe->removeFlag() ;
          Minesweeper::decreaseNbFlag() ;
        } else {
          boxe->setFlag() ;
          Minesweeper::increaseNbFlag() ;
        }
      }
    }
  }
};

void shellMinesweeper::fail () {
  std::cout << "\n\n# # # # # # # You fail # # # # # # #\n\n" ;
  m_running = false ;
};

void shellMinesweeper::checkWin () {
  if (Minesweeper::isWin()) {
    std::cout << "\n\n* * * * * * * You win * * * * * * *\n\n" ;
  }
  std::cout << "Check checkWin\n" ;
};
