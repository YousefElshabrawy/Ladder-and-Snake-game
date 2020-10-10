#include "CardFourteen.h"

int CardFourteen::Fees = 0;
int CardFourteen::CardPrice = 0;
int CardFourteen::Check = 0;
Player* CardFourteen::Owner = NULL;

bool CardFourteen::loaded = false;
bool CardFourteen::saved = false;

CardFourteen::CardFourteen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 14;
}

CardFourteen::~CardFourteen(void)
{
}

void CardFourteen::ReadCardParameters(Grid* pGrid)
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

void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
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
			pOut->PrintMessage("You Lost a good Chance,click to continue ... ");
			pIn->GetCellClicked();
		}
	}
	else
	{
		if (pPlayer != Owner)
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			Owner->SetWallet(Owner->GetWallet() + Fees);
		}
	}
	pOut->ClearStatusBar();
}

void CardFourteen::Save(ofstream& Outfile, int Type)
{
	Card::Save(Outfile, Type);
	if (Type == 2) {
		if (!saved)
		{
			Outfile << CardPrice << " " << Fees;
			saved = true;		           //note yousef we need to make another 
										 //static boolean to check if data is read before or not
		}
		Outfile << endl;
	}
}
void CardFourteen::Load(ifstream& Infile)
{
	Card::Load(Infile);
	if (!loaded)
	{
		Infile >> CardPrice >> Fees;
		loaded = true;
	}
}

void CardFourteen::editsetup()
{
	Fees = 0;
}

void CardFourteen::loadsetup()
{
	loaded = false;
}
void CardFourteen ::savesetup()
{
	saved = false;
}