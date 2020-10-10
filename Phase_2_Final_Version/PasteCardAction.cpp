#include "PasteCardAction.h"
#include"Action.h"
#include"Card.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"


PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void PasteCardAction::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("click on cell you would like to paste the card to");
	clicked = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (!(pGrid->GetClipboard())) 
	{
		pOut->PrintMessage("clipboard is empty...advice from freind copy or cut card first..click to continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

	ReadActionParameters();

	Card* prameters = pGrid->GetClipboard();
	int kind = pGrid->GetClipboard()->GetCardNumber();
	Card* pasted;

	switch (kind)
	{
	case 1:
		pasted = new CardOne(clicked);
		((CardOne*)(pasted))->setWalletAmount(prameters);
		break;
	case 2:
		pasted = new CardTwo(clicked);
		((CardTwo*)(pasted))->setWalletAmount(prameters);
		break;
	case 3:
		pasted = new CardThree(clicked);
		break;
	case 4:
		pasted = new CardFour(clicked);
		break;
	case 5:
		pasted = new CardFive(clicked);
		break;
	case 6:
		pasted = new CardSix(clicked);
		break;
	case 7:
		pasted = new CardSeven(clicked);
		break;
	case 8:
		pasted = new CardEight(clicked);
		break;
	case 9:
		pasted = new CardNine(clicked);
		((CardNine*)(pasted))->setcell(prameters);
		break;
	case 10:
		pasted = new CardTen(clicked);
		break;
	case 11:
		pasted = new CardEleven(clicked);
		break;
	case 12:
		pasted = new CardTwelve(clicked);
		break;
	case 13:
		pasted = new CardThirteen(clicked);
		break;
	case 14:
		pasted = new CardFourteen(clicked);
		break;

	default:
		break;
	}
	if (!(pGrid->AddObjectToCell(pasted))) 
	{
		pOut->PrintMessage("this cell has an object cant paste the card to it..click to continue ");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		delete pasted;
		pasted = NULL;
	}
}