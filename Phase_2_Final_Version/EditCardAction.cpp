#include "EditCardAction.h"
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


EditCardAction::EditCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void EditCardAction::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("click on the card you wish you edit");
	 clicked = pIn->GetCellClicked();

	
}

void EditCardAction::Execute()
{

	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Card* toedit = pGrid->GetCard(clicked);

	if (toedit == NULL) 
	{
		pOut->PrintMessage("do you think we dont know what is card ...click to continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

	int cardnum=toedit->GetCardNumber();

	if (cardnum == 1 || cardnum == 2 || cardnum==9) 
	{
		toedit->ReadCardParameters(pGrid);
	}
	else if (cardnum > 9 && cardnum < 15) 
	{
		toedit->editsetup();
		//CardTen::editsetup();
		//CardEleven::editsetup();
		//CardTwelve::editsetup();
		//CardThirteen::editsetup();
		//CardFourteen::editsetup();
		toedit->ReadCardParameters(pGrid);
	}
	else 
	{
		pOut->PrintMessage("there is no parameters for this card...click to continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();

	}
	
	



}