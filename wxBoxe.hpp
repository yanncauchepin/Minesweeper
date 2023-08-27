#ifndef WXBOXE_HPP_INCLUDED
#define WXBOXE_HPP_INCLUDED

#include "abstractBoxe.hpp"
#include "abstractMinesweeper.hpp"
#include "wxMinesweeperApp.hpp"
#include <iostream>
#include <wx/wx.h>

wxDECLARE_EVENT(MINE, wxCommandEvent);
wxDECLARE_EVENT(EXHIBIT, wxCommandEvent);
wxDECLARE_EVENT(SPREADING, wxCommandEvent);
wxDECLARE_EVENT(FLAG, wxCommandEvent);

class wxBoxe : public wxPanel, public Boxe {

  public :
    wxBoxe(int indexHeight, int indexWidth, wxWindow *parent, wxWindowID id) ;
    virtual ~wxBoxe() ;

    void OnPaint(wxPaintEvent &event, wxWindow* parent) ;

    wxString getTextBoxe() ;
    wxColor getTextColorBoxe() ;
    wxColor getColorBoxe() ;
    wxFont getTextFont() ;

    void sendMouseLeftDownEvent(wxMouseEvent &event) ;
    void sendMouseLeftRightEvent(wxMouseEvent &event) ;

};

#endif //WXBOXE_HPP_INCLUDED
