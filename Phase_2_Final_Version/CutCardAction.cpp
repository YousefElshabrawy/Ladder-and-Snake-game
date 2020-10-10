#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) :CopyCardAction(pApp)
{

}



void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	CopyCardAction::Execute();
	if (pGrid->GetClipboard())
		pGrid->RemoveObjectFromCell(clicked);


}