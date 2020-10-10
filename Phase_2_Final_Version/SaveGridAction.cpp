#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp)
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();

	Pout->PrintMessage("enter the name of the text folder followed by .txt");
	filename = Pin->GetSrting(Pout);
	Pout->ClearStatusBar();
}

void SaveGridAction::Execute()
{

	ReadActionParameters();

	ofstream Outfile;

	Outfile.open(filename);

	pManager->GetGrid()->SaveAll(Outfile, 0);
	pManager->GetGrid()->SaveAll(Outfile, 1);
	pManager->GetGrid()->SaveAll(Outfile, 2);

	Outfile.close();

	CardTen::savesetup();
	CardEleven::savesetup();
	CardTwelve::savesetup();
	CardThirteen::savesetup();
	CardFourteen::savesetup();

}