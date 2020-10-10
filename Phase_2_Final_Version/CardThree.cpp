#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Effect of CardThree of CardThree
	L=(pGrid->GetNextLadder((pPlayer->GetCell())->GetCellPosition()));
	if (L)
	{
		NC = L->GetPosition();
		pPlayer->PreventPF();
		pPlayer->Move(pGrid, NC.GetCellNum() - ((pPlayer->GetCell())->GetCellPosition()).GetCellNum());
		pPlayer->MturnCount();
	}
}

void CardThree::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}
