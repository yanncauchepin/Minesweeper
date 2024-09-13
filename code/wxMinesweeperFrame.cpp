#include "wxMinesweeperFrame.hpp"
#include "abstractMinesweeper.hpp"
#include <string>
#include <wx/numdlg.h>

enum {
    ID_Menu_Restart = 1,
    ID_Menu_Initialize = 2,
    ID_Menu_SetSpacing = 3,
    ID_Resolve = 4
};

wxMinesweeperFrame::wxMinesweeperFrame(std::string name, wxPoint point, wxSize size) : wxFrame(NULL, wxID_ANY, name, point, size) {

    wxMenu *menuGame = new wxMenu ;
    menuGame->Append(ID_Menu_Restart, "Restart\tCtrl-R", "Restart your minesweeper game", wxITEM_NORMAL) ;
    menuGame->AppendSeparator() ;
    menuGame->Append(ID_Menu_Initialize, "Initialize\tCtrl-I", "Initialize your minesweeper game", wxITEM_NORMAL) ;
    menuGame->AppendSeparator();
    menuGame->Append(ID_Menu_SetSpacing, "SetSpacing\tCtrl-S", "Set the spacing between cases", wxITEM_NORMAL) ;
    menuGame->AppendSeparator();
    menuGame->Append(wxID_EXIT) ;

    wxMenu *menuAI = new wxMenu ;
    menuAI->Append(ID_Resolve, "Resolve\tCtrl-A", "Try to resolve your minesweeper game", wxITEM_NORMAL) ;

    wxMenu *menuInfo = new wxMenu ;
    menuInfo->Append(wxID_ABOUT) ;

    wxMenuBar *menuBar = new wxMenuBar() ;
    menuBar->Append(menuGame, "Game") ;
    menuBar->Append(menuAI, "AI") ;
    menuBar->Append(menuInfo, "Info") ;

    SetMenuBar(menuBar);
    CreateStatusBar();

    m_frameSizer = new wxBoxSizer(wxVERTICAL);

    m_initHeight = new int(10) ;
    m_initWidth = new int(10) ;
    m_initNbTotalMines = new int(20) ;
    m_initSpacingHeight = new int(2) ;
    m_initSpacingWidth = new int(2) ;
    m_minesweeper = new wxMinesweeper(*m_initHeight, *m_initWidth, *m_initNbTotalMines, this, wxID_ANY, wxDefaultPosition, wxDefaultSize, *m_initSpacingHeight, *m_initSpacingWidth);

    m_frameSizer->Add(m_minesweeper, 1, wxEXPAND|wxALL, 10) ;

    this->SetSizerAndFit(m_frameSizer) ;

    SetStatusMinesIdentified(m_minesweeper) ;

    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnRestart, this, ID_Menu_Restart);
    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnInitialize, this, ID_Menu_Initialize);
    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnSetSpacing, this, ID_Menu_SetSpacing);
    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &wxMinesweeperFrame::OnResolve, this, ID_Resolve);
    Bind(FLAG, &wxMinesweeperFrame::OnFlag, this, wxID_ANY);
    Bind(WIN, &wxMinesweeperFrame::OnWin, this, wxID_ANY);
    Bind(FAIL, &wxMinesweeperFrame::OnFail, this, wxID_ANY);

};

wxMinesweeperFrame::~wxMinesweeperFrame() { // Erreur de segmentation ici !
    delete m_minesweeper ;
    delete m_initHeight ;
    delete m_initWidth ;
    delete m_initNbTotalMines ;
    delete m_initSpacingHeight ;
    delete m_initSpacingWidth ;
    this->wxWindow::Close(true) ;
};

void wxMinesweeperFrame::SetStatusMinesIdentified(Minesweeper* minesweeper) {
  SetStatusText(wxString::Format(wxT("Mines identified : %i | %i"), minesweeper->getNbFlag(), minesweeper->getTotalMines()));
}

void wxMinesweeperFrame::OnExit(wxCommandEvent& event) {
    Close(true);
};

void wxMinesweeperFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This a Minesweeper game implemented in language C++",
                 "About Minesweeper", wxOK | wxICON_INFORMATION);
};

void wxMinesweeperFrame::OnRestart(wxCommandEvent& event) {
  m_frameSizer->Detach(m_minesweeper->getSizer()) ;
  delete m_minesweeper ;
  m_minesweeper = new wxMinesweeper(*m_initHeight, *m_initWidth, *m_initNbTotalMines, this, wxID_ANY, wxDefaultPosition, wxDefaultSize, *m_initSpacingHeight, *m_initSpacingWidth);
  m_frameSizer->Add(m_minesweeper, 1, wxEXPAND|wxALL, 10) ;
  this->SetSizerAndFit(m_frameSizer) ;
  SetStatusMinesIdentified(m_minesweeper) ;
}

void wxMinesweeperFrame::OnInitialize(wxCommandEvent& event) {
  int getHeight = wxGetNumberFromUser("Indiquez la hauteur du demineur", "Valeur", "Height", *m_initHeight, 2, Minesweeper::getMaxHeight()) ;
  if (getHeight != -1) {
    *m_initHeight = getHeight ;
    int getWidth = wxGetNumberFromUser("Indiquez la largeur du demineur", "Valeur", "Width", *m_initWidth, 2, Minesweeper::getMaxWidth()) ;
    if (getWidth != -1) {
      *m_initWidth = getWidth ;
      int getNbTotalMines = wxGetNumberFromUser("Indiquez le nombre de bombes", "Valeur", "TotalMines", *m_initNbTotalMines, 1, Minesweeper::getMaxTotalMines(*m_initHeight, *m_initWidth)) ;
      if (getNbTotalMines != -1) {
        *m_initNbTotalMines = getNbTotalMines ;
        wxMinesweeperFrame::OnRestart(event) ;
      }
    }
  }
};

void wxMinesweeperFrame::OnResolve(wxCommandEvent& event) {

};

void wxMinesweeperFrame::OnSetSpacing(wxCommandEvent& event) {
  int getSpacingHeight = wxGetNumberFromUser("Indiquez l'espacement hauteur", "Valeur", "Height", *m_initSpacingHeight, 0, 10) ;
  if (getSpacingHeight !=-1) {
    *m_initSpacingHeight = getSpacingHeight ;
    int getSpacingWidth = wxGetNumberFromUser("Indiquez l'espacement largeur", "Valeur", "Width", *m_initSpacingWidth, 0, 10) ;
    if (getSpacingWidth !=-1) {
      *m_initSpacingWidth = getSpacingWidth ;
      m_minesweeper->setSpacingHeight(*m_initSpacingHeight);
      m_minesweeper->setSpacingWidth(*m_initSpacingWidth);
      this->SetSizerAndFit(m_frameSizer) ;
    }
  }
}

void wxMinesweeperFrame::OnFlag(wxCommandEvent &event) {
    if (event.GetString()==wxString("Remove")) {
      m_minesweeper->decreaseNbFlag() ;
    }
    if (event.GetString()==wxString("Set")) {
      m_minesweeper->increaseNbFlag() ;
    }
    SetStatusMinesIdentified(m_minesweeper) ;
};

void wxMinesweeperFrame::OnWin(wxCommandEvent &event) {
};

void wxMinesweeperFrame::OnFail(wxCommandEvent &event) {

};
