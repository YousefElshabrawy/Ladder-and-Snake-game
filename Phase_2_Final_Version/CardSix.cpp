#include "CardSix.h"

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output*pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You will Move backword,Click any where to continue");
	pIn->GetCellClicked();
	pPlayer->PreventPF();
	pPlayer->Move(pGrid,-(pPlayer->GetjustRolledDiceNum()));
	pPlayer->MturnCount();
	pOut->ClearStatusBar();

}
void CardSix::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}
