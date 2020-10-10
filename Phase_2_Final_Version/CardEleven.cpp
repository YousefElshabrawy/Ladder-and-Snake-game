#include "CardEleven.h"

int CardEleven::Fees = 0;
int CardEleven::CardPrice = 0;
int CardEleven::Check = 0;
Player* CardEleven::Owner = NULL;

bool CardEleven::loaded = false;
bool CardEleven::saved = false;

CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (!Fees)
	{
		pOut->PrintMessage("Enter The Card Price ...");
		CardPrice = pIn->GetInteger(pOut);

		pOut->PrintMessage("Enter The Card Fees ...");
		Fees = pIn->GetInteger(pOut);

		pOut->ClearStatusBar();
	}
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (!Check)
	{
		string SpOut = "The cell price is " + to_string(CardPrice) + " If You Want To Buy This Cell Type 1 else Type 0 ...";
		pOut->PrintMessage(SpOut);
		Check = pIn->GetInteger(pOut);
		if (Check)
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				Owner = pPlayer;
			}
			else
			{
				pOut->PrintMessage("You can't buy it, You Dont Have Enough Money ,click to continue...");
				pIn->GetCellClicked();
				Check = 0;
			}
		}
		else
		{
			pOut->PrintMessage("You Lost a good Chance, click to continue ... ");
			pIn->GetCellClicked();
		}
	}
	else
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		Owner->SetWallet(Owner->GetWallet() + Fees);
	}
	pOut->ClearStatusBar();
}

void CardEleven::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2)
	{
		if (!saved)
		{
			Outfile << CardPrice << " " << Fees;
			saved = true;		           //note yousef we need to make another 
										 //static boolean to check if data is read before or not
		}
		Outfile << endl;
	}
}
void CardEleven::Load(ifstream& Infile)
{
	Card::Load(Infile);
	if (!loaded)
	{
		Infile >> CardPrice >> Fees;
		loaded = true;
	}
}

void CardEleven::editsetup()
{
	Fees = 0;
}

void CardEleven::loadsetup()
{
	loaded = false;
}
void CardEleven::savesetup()
{
	saved = false;
}