#include "CardNine.h"

CardNine::CardNine(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 9; 
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid * pGrid)
{
	
	
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	pOut->PrintMessage("Chose the specific cell,Click on the cell to continue....");
	NC=pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->PreventPF();
	pPlayer->Move(pGrid, NC.GetCellNum() - ((pPlayer->GetCell())->GetCellPosition()).GetCellNum());
	pPlayer->MturnCount();
}

void CardNine::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << NC.GetCellNum() << endl;
}
void CardNine::Load(ifstream& Infile)
{
	int celltogo;
	Card::Load(Infile);
	Infile >> celltogo;
	CellPosition  cell(celltogo);
	NC = cell;
}

void CardNine:: setcell(Card* pCard) 
{
	NC = ((CardNine*)(pCard))->NC;
}