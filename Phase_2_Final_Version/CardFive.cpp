#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	
	Output*pOut = pGrid->GetOutput();
	Card::Apply(pGrid,pPlayer);
	pPlayer->PreventPF();
	pPlayer->Move(pGrid,pPlayer->GetjustRolledDiceNum());
	pPlayer->MturnCount();
}

void CardFive::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}
