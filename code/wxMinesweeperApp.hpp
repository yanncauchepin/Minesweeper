#ifndef WXMINESWEEPERAPP_H_INCLUDED
#define WXMINESWEEPERAPP_H_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class wxMinesweeperApp : public wxApp {
  public:
    virtual bool OnInit();
};

DECLARE_APP(wxMinesweeperApp);

#endif // WXMINESWEEPERAPP_H_INCLUDED
