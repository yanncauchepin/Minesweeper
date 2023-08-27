#include "wxMinesweeper.hpp"
#include "wxBoxe.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <iostream>
#include <algorithm>
#include <wx/window.h>

wxDEFINE_EVENT(WIN, wxCommandEvent);
wxDEFINE_EVENT(FAIL, wxCommandEvent);

wxMinesweeper::wxMinesweeper(int height, int width, int totalMines, wxWindow *parent, wxWindowID id, const wxPoint &position, const wxSize &size, int spacingHeight, int spacingWidth) : Minesweeper(height, width, totalMines), wxPanel(parent, id, position, size), m_spacingHeight(spacingHeight), m_spacingWidth(spacingWidth) {

    SetBackgroundStyle(wxBG_STYLE_PAINT) ;

    m_minesweeperSizer = new wxGridSizer (height, width, spacingHeight, spacingWidth) ;

    wxMinesweeper::initializeBoxes() ;
    Minesweeper::initializeMines() ;
    Minesweeper::initializeIndicatorBoxes() ;
    Minesweeper::run() ;

    this->Bind(wxEVT_PAINT, &wxMinesweeper::OnPaint, this) ;
    this->Bind(MINE, &wxMinesweeper::OnMine, this) ;
    this->Bind(EXHIBIT, &wxMinesweeper::OnExhibit, this) ;
    this->Bind(SPREADING, &wxMinesweeper::OnSpreading, this) ;
    //this->Bind(FLAG, &wxMinesweeper::OnFlag, this) ;

    this->SetSizerAndFit(m_minesweeperSizer) ;

};

wxMinesweeper::~wxMinesweeper() {
  this->wxWindow::Close(true) ;
};


void wxMinesweeper::initializeBoxes() {
  int idBoxe(0);
  for(int h(0) ; h < Minesweeper::m_height ; h ++) {
    m_Boxes.push_back(std::vector<Boxe*>(Minesweeper::m_width)) ;
  }
  for (int h(0) ; h < Minesweeper::m_height ; h ++) {
    for (int w(0) ; w < Minesweeper::m_width ; w++) {
      idBoxe = w + h * Minesweeper::m_height ;
      m_Boxes[h][w] = new wxBoxe(h, w, this, idBoxe) ;
      wxBoxe *boxe = (wxBoxe*) Minesweeper::getBoxe(h, w) ;
      m_minesweeperSizer->Add(boxe, 1, wxEXPAND|wxALL) ;
    }
  }
};

void wxMinesweeper::setSpacingHeight(double spacingHeight) {
    m_spacingHeight = spacingHeight ;
    m_minesweeperSizer->SetHGap(m_spacingHeight);
    this->SetSizerAndFit(m_minesweeperSizer) ;
};
int& wxMinesweeper::getSpacingHeight() {
    return m_spacingHeight ;
};
void wxMinesweeper::setSpacingWidth(double spacingWidth) {
    m_spacingWidth = spacingWidth ;
    m_minesweeperSizer->SetVGap(m_spacingWidth);
    this->SetSizerAndFit(m_minesweeperSizer) ;
};
int& wxMinesweeper::getSpacingWidth() {
    return m_spacingWidth ;
};
wxGridSizer* wxMinesweeper::getSizer() {
    return m_minesweeperSizer ;
};

void wxMinesweeper::OnPaint(wxPaintEvent &event) {
  for(int h(0) ; h < Minesweeper::m_height ; h ++) {
    for (int w(0) ; w < Minesweeper::m_width ; w++) {
      wxBoxe *boxe = (wxBoxe*) Minesweeper::getBoxe(h, w) ;
      if (boxe != 0) {
        boxe->OnPaint(event, this) ;
      }
    }
  }
};

void wxMinesweeper::OnMine(wxCommandEvent &event) {
    Refresh() ;
    wxMessageBox("You have selected a mine.", "You fail !", wxOK);
    wxCommandEvent eventFail(FAIL, wxID_ANY);
    Minesweeper::exhibitAll() ;
    Minesweeper::fail() ;
    Refresh() ;
};

void wxMinesweeper::OnExhibit(wxCommandEvent &event) {
    Refresh() ;
    Minesweeper::increaseNbEmptyExhibit() ;
    Refresh() ;
    if (Minesweeper::isWin()) {
      wxMessageBox("You have completed the grid without selecting a mine.", "You win !", wxOK);
      wxCommandEvent eventWin(WIN, wxID_ANY);
    }
};

void wxMinesweeper::OnSpreading(wxCommandEvent &event) {
    Refresh() ;
    int width = event.GetId() % Minesweeper::m_width ;
    int height = (event.GetId() - width) / Minesweeper::m_height ;
    Minesweeper::increaseNbEmptyExhibit() ;
    Minesweeper::spreadEmptyBoxeInArea(height, width) ;
    Refresh() ;
    if (Minesweeper::isWin()) {
      wxMessageBox("You have completed the grid without selecting a mine.", "You win !", wxOK);
      wxCommandEvent eventWin(WIN, wxID_ANY);
    }
};

/*void wxMinesweeper::OnFlag(wxCommandEvent &event) {
    if (event.GetString()==wxString("Delete")) {
      Minesweeper::decreaseNbFlag() ;
    } else {
      Minesweeper::increaseNbFlag() ;
    }
    Refresh() ;
};*/
