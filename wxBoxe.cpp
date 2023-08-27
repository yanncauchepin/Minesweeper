#include "wxBoxe.hpp"
#include <wx/colour.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <string>

wxDEFINE_EVENT(MINE, wxCommandEvent);
wxDEFINE_EVENT(EXHIBIT, wxCommandEvent);
wxDEFINE_EVENT(SPREADING, wxCommandEvent);
wxDEFINE_EVENT(FLAG, wxCommandEvent);

wxBoxe::wxBoxe(int indexHeight, int indexWidth, wxWindow *parent, wxWindowID id) : Boxe(indexHeight, indexWidth), wxPanel(parent, id, wxDefaultPosition, wxSize(30,30)) {

    this->Bind(wxEVT_LEFT_DOWN, &wxBoxe::sendMouseLeftDownEvent, this);
    this->Bind(wxEVT_RIGHT_DOWN, &wxBoxe::sendMouseLeftRightEvent, this) ;
};

wxBoxe::~wxBoxe() {
  this->wxWindow::Close(true) ;
};

wxString wxBoxe::getTextBoxe() {
  if (this->isHidden()) {
    if (this->isFlag()) {
      return wxString("!") ;
    } else {
    return wxString("") ;
    }
  } else {
    if (this->containMine()) {
      return wxString("#") ;
    } else {
      if (this->getIndicator()!=0){
        return wxString(std::to_string(this->getIndicator())) ;
      } else {
        return wxString("") ;
      }
    }
  }
};


wxColor wxBoxe::getTextColorBoxe() {
  if (this->isHidden()) {
    if (this->isFlag()) {
      return wxColor(190,0,0) ;
    } else {
      return wxColor(0,0,0) ;
    }
  } else {
    switch(this->getIndicator()) {
      case 1 :
        return wxColor(0,30,190) ;
        break ;
      case 2 :
        return wxColor(0,140,10) ;
        break ;
      case 3 :
        return wxColor(150,0,0) ;
        break ;
      case 4 :
        return wxColor(150,0,180) ;
        break ;
      case 5 :
        return wxColor(180,110,0) ;
        break ;
      case 6 :
        return wxColor(180,0,70) ;
        break ;
      default :
        return wxColor(0,0,0) ;
        break ;
    }
  }
};


wxColor wxBoxe::getColorBoxe() {
  if (this->isHidden()) {
      return wxColor(50,160,0) ;
  } else {
    return wxColor(250,250,250) ;
  }
};

wxFont wxBoxe::getTextFont() {
  wxFont textFont = *wxNORMAL_FONT ;
  textFont.SetPixelSize(wxSize(GetSize().GetWidth()/4 + 10, GetSize().GetHeight()/4 + 10)) ;
  if (!this->isHidden() && this->containMine())  {
    textFont.MakeBold() ;
  }
  return textFont ;
}

void wxBoxe::OnPaint(wxPaintEvent &event, wxWindow* parent) {

    wxPaintDC dc(parent);
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc) {
        gc->SetPen(wxPen(*wxBLACK)) ;
        gc->SetBrush(wxBrush(getColorBoxe()));
        gc->DrawRectangle(GetPosition().x, GetPosition().y, GetSize().GetWidth()-1, GetSize().GetHeight()-1);
        gc->SetFont(getTextFont(), getTextColorBoxe());
        double textWidth, textHeight;
        gc->GetTextExtent(getTextBoxe(), &textWidth, &textHeight);
        gc->DrawText(getTextBoxe(), GetPosition().x + GetSize().GetWidth() / 2.0 - textWidth / 2.0, GetPosition().y + GetSize().GetHeight() / 2.0 - textHeight / 2.0);
        delete gc;
    }
};

void wxBoxe::sendMouseLeftDownEvent(wxMouseEvent &event) {
    if (!Boxe::isFlag()){
      if (Boxe::isHidden()) {
        if (Boxe::containMine()) {
          Boxe::exhibit() ;
          wxCommandEvent eventMine(MINE, wxID_ANY);
          ProcessWindowEvent(eventMine);
        } else {
          if (Boxe::getIndicator()==0) {
            Boxe::exhibit() ;
            wxCommandEvent eventSpreading(SPREADING, this->GetId());
            ProcessWindowEvent(eventSpreading);
          } else {
            Boxe::exhibit() ;
            wxCommandEvent eventExhibit(EXHIBIT,wxID_ANY);
            ProcessWindowEvent(eventExhibit);
          }
        }
      }
    }
    Refresh() ;
};

void wxBoxe::sendMouseLeftRightEvent(wxMouseEvent &event) {
    if (Boxe::isHidden()) {
      wxCommandEvent eventFlag(FLAG, wxID_ANY);
      if (Boxe::isFlag()){
        Boxe::removeFlag() ;
        eventFlag.SetString(wxString("Remove")) ;
      } else {
        Boxe::setFlag() ;
        eventFlag.SetString(wxString("Set")) ;
      }
      ProcessWindowEvent(eventFlag);
    }

    Refresh() ;
};
