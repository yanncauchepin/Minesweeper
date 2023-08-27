#ifndef ABSTRACT_BOXE_HPP_INCLUDED
#define ABSTRACT_BOXE_HPP_INCLUDED

#include <iostream>

class Boxe {

  public :

    Boxe(int indexHeight, int indexWidth) ;
    virtual ~Boxe() = 0 ;

    bool containMine() const ;
    bool isFlag() const ;
    int getIndicator() const ;
    int getIndexHeight() const ;
    int getIndexWidth() const ;
    bool isHidden() const ;

    void setIndicator(int indicator) ;
    void setMine(bool isMine) ;
    void setFlag() ;
    void removeFlag() ;
    void hidden() ;
    void exhibit() ;

  protected :

    int m_indexHeight ;
    int m_indexWidth ;
    bool m_hidden ;
    bool m_mineBoxe ;
    bool m_flag ;
    int m_indicator ;

};

#endif //ABSTRACT_BOXE_HPP_INCLUDED
