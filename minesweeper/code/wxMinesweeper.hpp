#ifndef WXMINESWEEPER_H_INCLUDED
#define WXMINESWEEPER_H_INCLUDED

#include "abstractMinesweeper.hpp"
#include "wxBoxe.hpp"
#include "wxMinesweeperApp.hpp"

#include <wx/wx.h>
#include <list>

wxDECLARE_EVENT(WIN, wxCommandEvent);
wxDECLARE_EVENT(FAIL, wxCommandEvent);

class wxMinesweeper : public wxPanel, public Minesweeper {

  public:

    wxMinesweeper(int height, int width, int totalMines, wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, int spacingHeight=0, int spacingWidth=0);
    virtual ~wxMinesweeper() ;

    virtual void initializeBoxes() ;

    void setSpacingHeight(double spacingHeight) ;
    int& getSpacingHeight() ;
    void setSpacingWidth(double spacingWidth) ;
    int& getSpacingWidth() ;
    wxGridSizer* getSizer() ;

    void OnPaint (wxPaintEvent &event) ;
    void OnMine(wxCommandEvent &event) ;
    void OnExhibit(wxCommandEvent &event) ;
    void OnSpreading(wxCommandEvent &event) ;
    //void OnFlag(wxCommandEvent &event) ;

  private:

    wxGridSizer *m_minesweeperSizer ;
    int m_spacingHeight ;
    int m_spacingWidth ;


};



#endif //WXMINESWEEPER_H_INCLUDED
