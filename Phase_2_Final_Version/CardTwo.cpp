#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//2-Get approbiate input
	pOut->PrintMessage("Enter the walletAmount of Increasing of the card ...");
	walletAmount = pIn->GetInteger(pOut);
	// Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Effect of CardTWo of CardTwo
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}

void CardTwo::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	Outfile << walletAmount << endl;

}
void CardTwo::Load(ifstream& Infile)
{
	Card::Load(Infile);
	Infile >> walletAmount;
}

void CardTwo::setWalletAmount(Card* pCard)
{

	CardTwo* ptr = dynamic_cast<CardTwo*>(pCard);
	walletAmount = ptr->walletAmount;
}