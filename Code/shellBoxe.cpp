#include "shellBoxe.hpp"
#include <iostream>

shellBoxe::shellBoxe(int indexHeight, int indexWidth) : Boxe(indexHeight, indexWidth) {
};

shellBoxe::~shellBoxe() {
};

void shellBoxe::draw(bool hidden) const {
  if (hidden) {
    if (m_flag) {
      std::cout << "\033[1;7;35m[!]\033[0m" ;
    } else if (m_hidden) {
      std::cout << "[ ]" ;
    } else if (!m_hidden) {
      if (m_mineBoxe) {
        std::cout << "\033[1;7;31m[#]\033[0m" ;
      } else {
        std::cout << "[" ;
        switch (m_indicator) {
          case 0 :
            std::cout << m_indicator ;
            break ;
          case 1 :
            std::cout << "\033[1;33m" << m_indicator << "\033[0m" ;
            break ;
          case 2 :
            std::cout << "\033[1;32m" << m_indicator << "\033[0m" ;
            break ;
          case 3 :
            std::cout << "\033[1;31m" << m_indicator << "\033[0m" ;
            break ;
          case 4 :
            std::cout << "\033[1;35m" << m_indicator << "\033[0m" ;
            break ;
          case 5 :
            std::cout << "\033[1;36m" << m_indicator << "\033[0m" ;
            break ;
          case 6 :
            std::cout << "\033[1;36m" << m_indicator << "\033[0m" ;
            break ;
          case 7 :
            std::cout << "\033[1;36m" << m_indicator << "\033[0m" ;
            break ;
          case 8 :
            std::cout << "\033[1;36m" << m_indicator << "\033[0m" ;
            break ;
          default :
            std::cout << m_indicator ;
            break ;
        }
        std::cout << "]" ;
      }
    }
  } else {
    if (m_mineBoxe) {
      std::cout << "\033[1;7;31m[#]\033[0m" ;
    } else {
      std::cout << "[" ;
      switch (m_indicator) {
        case 0 :
          std::cout << m_indicator ;
          break ;
        case 1 :
          std::cout << "\033[1;33m" << m_indicator << "\033[0m" ;
          break ;
        case 2 :
          std::cout << "\033[1;32m" << m_indicator << "\033[0m" ;
          break ;
        case 3 :
          std::cout << "\033[1;31m" << m_indicator << "\033[0m" ;
          break ;
        case 4 :
          std::cout << "\033[1;35m" << m_indicator << "\033[0m" ;
          break ;
        case 5 :
          std::cout << "\033[1;36m" << m_indicator << "\033[0m" ;
          break ;
        case 6 :
          std::cout << "\033[1;34m" << m_indicator << "\033[0m" ;
          break ;
        case 7 :
          std::cout << "\033[1;34m" << m_indicator << "\033[0m" ;
          break ;
        case 8 :
          std::cout << "\033[1;34m" << m_indicator << "\033[0m" ;
          break ;
        default :
          std::cout << m_indicator ;
          break ;
      }
      std::cout << "]" ;
    }
  }
};
