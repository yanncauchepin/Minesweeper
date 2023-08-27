#ifndef SHELL_BOXE_HPP_INCLUDED
#define SHELL_BOXE_HPP_INCLUDED

#include "abstractBoxe.hpp"
#include <iostream>

class shellBoxe : public Boxe {

  public :
    shellBoxe(int indexHeight, int indexWidth) ;
    virtual ~shellBoxe() ;
    void draw(bool hidden=false) const ;

};

#endif //SHELL_BOXE_HPP_INCLUDED
