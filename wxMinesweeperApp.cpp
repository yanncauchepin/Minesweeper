#include "wxMinesweeperApp.hpp"

#include "wxMinesweeperFrame.hpp"
#include <string>

bool wxMinesweeperApp::OnInit() {

  wxMinesweeperFrame *frame = new wxMinesweeperFrame("Demineur", wxDefaultPosition, wxDefaultSize);
  frame->Show();
  return true;
};

IMPLEMENT_APP(wxMinesweeperApp);

/*
En fait, la macro IMPLEMENT_APP(wxMinesweeperApp) sert à indiquer à wxWidgets que la classe wxMinesweeperApp est la classe principale de
l'application, et que c'est en fonction de la valeur de retour de sa méthode OnInit() qu'il faudra ou non continuer à faire
tourner l'exécutable.
*/
