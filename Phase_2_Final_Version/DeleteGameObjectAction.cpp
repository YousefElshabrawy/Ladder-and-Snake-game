#include "DeleteGameObjectAction.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp)
{

}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please click on the cell you want to delete its object");
	clicked = pIn->GetCellClicked();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->ClearStatusBar();
	pGrid->RemoveObjectFromCell(clicked);
	

}