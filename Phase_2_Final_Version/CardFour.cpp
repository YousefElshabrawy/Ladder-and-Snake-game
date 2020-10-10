#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4;
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	Snake* S = (pGrid->GetNextSnake((pPlayer->GetCell())->GetCellPosition()));
	if (S)
	{
		pPlayer->PreventPF();
		pPlayer->Move(pGrid, (S->GetPosition()).GetCellNum() - ((pPlayer->GetCell())->GetCellPosition()).GetCellNum());
		pPlayer->MturnCount();
	}
}

void CardFour::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}

