#include "abstractBoxe.hpp"
#include "abstractMinesweeper.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int Minesweeper::maxHeight = 20 ;
int Minesweeper::maxWidth = 20 ;

int& Minesweeper::getMaxHeight() {
  return Minesweeper::maxHeight ;
};
void Minesweeper::setMaxHeight(int maxHeight) {
  Minesweeper::maxHeight = maxHeight ;
}
int& Minesweeper::getMaxWidth() {
  return Minesweeper::maxWidth ;
};
void Minesweeper::setMaxWidth(int maxWidth) {
  Minesweeper::maxWidth = maxWidth ;
}
int Minesweeper::getMaxTotalMines(int height, int width) {
  return (height * width) / 3 ;
};

Minesweeper::Minesweeper(int height, int width, int totalMines) : m_height(height), m_width(width), m_totalMines(totalMines), m_nbFlag(0), m_running(false), m_nbEmptyExhibit(0) {
};


Minesweeper::~Minesweeper () {
  for (int h(0) ; h < m_height ; h ++) {
    for (int w(0) ; w < m_width ; w++) {
      delete m_Boxes[h][w] ;
    }
  }
};


void Minesweeper::initializeMines() {
  srand(time(0)) ;
  int current_mine(0) ;
  int h(0), w(0), random(0), size_minesweeper(0) ;
  size_minesweeper = m_height * m_width ;
  while (current_mine < m_totalMines) {
    random = rand()%size_minesweeper ;
    w = random%m_width ;
    h = (random-w)/m_height ;
    Boxe *boxe = Minesweeper::getBoxe(h, w) ;
    if (boxe != 0) {
      if (not boxe->containMine()) {
        boxe->setMine(true) ;
        current_mine++ ;
      }
    }
  }
};

void Minesweeper::initializeIndicatorBoxes() {
  for(int h(0) ; h < m_height ; h ++) {
    for (int w(0) ; w < m_width ; w++) {
      Boxe *boxe = Minesweeper::getBoxe(h, w) ;
      if (boxe != 0) {
        if (!boxe->containMine()) {
          m_Boxes[h][w]->setIndicator(Minesweeper::getProximityMines(h, w)) ;
        }
      }
    }
  }
};

int Minesweeper::getProximityMines(int indexHeight, int indexWidth) {
  int *count = new int(0) ;
  Minesweeper::countProximityMineBoxe(indexHeight-1, indexWidth-1, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight-1, indexWidth, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight-1, indexWidth+1, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight, indexWidth-1, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight, indexWidth+1, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight+1, indexWidth-1, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight+1, indexWidth, count) ;
  Minesweeper::countProximityMineBoxe(indexHeight+1, indexWidth+1, count) ;
  return *count ;
};

void Minesweeper::countProximityMineBoxe(int indexHeight, int indexWidth, int *count) {
  Boxe *boxe = Minesweeper::getBoxe(indexHeight, indexWidth) ;
  if (boxe != 0) {
    if (boxe->containMine()) {
      *count = *count + 1 ;
    }
  }
};

Boxe* Minesweeper::getBoxe(int indexHeight, int indexWidth) const {
  if (indexHeight >= 0 && indexHeight < m_height && indexWidth >= 0 && indexWidth < m_width) {
    return m_Boxes[indexHeight][indexWidth] ;
  } else {
    return 0 ;
  }
};

int Minesweeper::getHeight() const {
  return m_height ;
};

int Minesweeper::getWidth() const {
  return m_width ;
};

int Minesweeper::getTotalMines() const {
  return m_totalMines ;
};

void Minesweeper::increaseNbFlag() {
    m_nbFlag++ ;
};

void Minesweeper::decreaseNbFlag() {
    m_nbFlag-- ;
};

int Minesweeper::getNbFlag() const {
  return m_nbFlag ;
};

void Minesweeper::increaseNbEmptyExhibit() {
    m_nbEmptyExhibit++ ;
};

int Minesweeper::getNbEmptyExhibit() const {
  return m_nbEmptyExhibit ;
};

void Minesweeper::spreadEmptyBoxeInArea(int indexHeight, int indexWidth) {
  Boxe *boxe(0) ;
  boxe = Minesweeper::getBoxe(indexHeight-1, indexWidth-1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight-1, indexWidth) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight-1, indexWidth+1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight, indexWidth-1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight, indexWidth+1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight+1, indexWidth-1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight+1, indexWidth) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
  boxe = Minesweeper::getBoxe(indexHeight+1, indexWidth+1) ;
  if (boxe != 0 && boxe->isHidden()) {
    Minesweeper::exhibitBoxeInSpreading(boxe) ;
  }
};

void Minesweeper::exhibitBoxeInSpreading(Boxe *boxe) {
  if (!boxe->containMine()) {
    boxe->exhibit() ;
    m_nbEmptyExhibit++ ;
    if (boxe->getIndicator()==0) {
      Minesweeper::spreadEmptyBoxeInArea(boxe->getIndexHeight(), boxe->getIndexWidth()) ;
    }
  }
};

void Minesweeper::exhibitAll () {
  for (int h(0) ; h < m_height ; h ++) {
    for (int w(0) ; w < m_width ; w++) {
      Boxe *boxe = Minesweeper::getBoxe(h, w) ;
      if (boxe != 0) {
        boxe->exhibit() ;
      }
    }
  }
};

bool Minesweeper::isRunning() const {
  return m_running ;
};

void Minesweeper::run() {
  m_running = true ;
};

void Minesweeper::fail () {
  m_running = false ;
};

bool Minesweeper::isWin () {
  if (m_nbEmptyExhibit == ((m_height*m_width)-m_totalMines)) {
    m_running = false ;
    return true ;
  } else {
    return false ;
  }
  std::cout << "Check isWin\n" ;
};
