#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) 
{
	cardNumber = 8; 
}

CardEight::~CardEight(void)
{
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You are Prevented From Rolling next time,Click any where to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	if (!Check)
	{
		pPlayer->PreventMoving(1);
		Check = true;
	}
}

void CardEight::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}

