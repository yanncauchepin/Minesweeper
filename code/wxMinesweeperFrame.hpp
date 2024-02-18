#ifndef WXMINESWEEPERFRAME_H_INCLUDED
#define WXMINESWEEPERFRAME_H_INCLUDED

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wxMinesweeper.hpp"
#include "wxMinesweeperApp.hpp"
#include "abstractMinesweeper.hpp"
#include <wx/grid.h>
#include <string>

class wxMinesweeperFrame : public wxFrame {
  public:
    wxMinesweeperFrame(std::string name, wxPoint point, wxSize size);
    ~wxMinesweeperFrame();

  private:
    wxMinesweeper *m_minesweeper ;
    wxSizer *m_frameSizer ;
    int *m_initHeight ;
    int *m_initWidth ;
    int *m_initNbTotalMines ;
    int *m_initSpacingHeight ;
    int *m_initSpacingWidth ;

    void SetStatusMinesIdentified(Minesweeper* minesweeper);

    void OnRestart(wxCommandEvent& event);
    void OnInitialize(wxCommandEvent& event);
    void OnResolve(wxCommandEvent& event);
    void OnSetSpacing(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnFlag(wxCommandEvent& event);
    void OnWin(wxCommandEvent& event);
    void OnFail(wxCommandEvent& event);

};

#endif // WXMINESWEEPERFRAME_H_INCLUDED
