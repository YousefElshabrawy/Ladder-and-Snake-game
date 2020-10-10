#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) 
{
	cardNumber = 7; 
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	int RollDice=0;
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool EG =pGrid->GetEndGame();
	if (EG)
	{

	}
	else
	{
		pOut->PrintMessage("Bounce Roll Dice of,Click any Where to continue ...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		srand((int)time(NULL));
		RollDice = 1 + rand() % 6;
	}
	pPlayer->PreventPF();
	pPlayer->Move(pGrid, RollDice);
	pPlayer->MturnCount();
}

void CardSeven::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << endl;
}
