#include "abstractBoxe.hpp"
#include <iostream>

Boxe::Boxe(int indexHeight, int indexWidth) : m_indexHeight(indexHeight), m_indexWidth(indexWidth), m_mineBoxe(false), m_flag(false), m_indicator(0), m_hidden(true) {
};

Boxe::~Boxe() {
};

bool Boxe::containMine() const {
  return m_mineBoxe ;
};

bool Boxe::isFlag() const {
  return m_flag ;
};

int Boxe::getIndicator() const {
  return m_indicator ;
};

int Boxe::getIndexHeight() const {
  return m_indexHeight ;
};

int Boxe::getIndexWidth() const {
  return m_indexWidth ;
};

bool Boxe::isHidden() const {
  return m_hidden ;
}

void Boxe::setIndicator(int indicator) {
  m_indicator = indicator ;
};

void Boxe::setMine(bool isMine) {
  m_mineBoxe = isMine ;
};

void Boxe::setFlag() {
  m_flag = true ;
};

void Boxe::removeFlag() {
  m_flag = false ;
};

void Boxe::hidden() {
  m_hidden = true ;
};

void Boxe::exhibit() {
  m_hidden = false ;
};

std::ostream &operator<<(std::ostream &flux, Boxe const& boxe) {
  flux << "(" << boxe.getIndexHeight() <<"," << boxe.getIndexWidth() <<")" ;
  if (boxe.containMine()) {
    flux << " --Mine" ;
  }
  if (boxe.isHidden()) {
    flux << " --hidden" ;
  }
  if (boxe.isFlag()) {
    flux << " --flag" ;
  }
  flux << " [" << boxe.getIndicator() << "]" ;
  return flux;
};
