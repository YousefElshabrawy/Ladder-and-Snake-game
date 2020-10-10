#include "CopyCardAction.h"
#include"Action.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("click on the card wish to copy/cut");
	clicked = pIn->GetCellClicked();

}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pGrid->SetClipboard(clicked);  //yousef changed setClipboarda() implementation
	if (pGrid->GetClipboard())
		pOut->PrintMessage("card is now in your clipboard..click to continue");
	else
		pOut->PrintMessage("do you think i dont know how a card looks like..click to continue ");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}