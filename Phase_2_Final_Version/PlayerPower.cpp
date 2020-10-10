#include "PlayerPower.h"

bool PlayerPower::PoisonF(int PN, Grid* pGrid)
{
	if (Poison && Turn < 2)
	{
		Player* P = pGrid->GetPlayerByNum(PN);
		P->PoisonP();
		Poison = 0;
		Turn++;
		return 1;
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("You have used this power,Click any where to continue...");
		pIn->GetCellClicked();
		return 0;
	}
}
bool PlayerPower::IceF(int PN, Grid* pGrid)
{
	if (Ice && Turn < 2)
	{
		Player* P = pGrid->GetPlayerByNum(PN);
		P->PreventMoving(1);
		Ice = 0;
		Turn++;
		return 1;
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("You have used this power,Click any where to continue...");
		pIn->GetCellClicked();
		return 0;
	}
}
bool PlayerPower::FireF(int PN, Grid* pGrid)
{
	if (Fire && Turn < 2)
	{
		Player* P = pGrid->GetPlayerByNum(PN);
		P->FireP();
		Fire = 0;
		Turn++;
		return 1;
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("You have used this power,Click any where to continue...");
		pIn->GetCellClicked();
		return 0;
	}
}
bool PlayerPower::LightningF(int PN, Grid* pGrid)
{
	if (Lightning && Turn < 2)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i != PN)
			{
				Player* P = pGrid->GetPlayerByNum(i);
				P->SetWallet(P->GetWallet() - 20);
			}
		}
		Lightning = 0;
		Turn++;
		return 1;
	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("You have used this power,Click any where to continue...");
		pIn->GetCellClicked();
		return 0;
	}
}
bool PlayerPower::Available(string& S)
{
	S = "Press ";
	if (Ice)
	{
		S = S + "1-Ice ";
	}
	if (Fire)
	{
		S = S + "2-Fire ";
	}
	if (Poison)
	{
		S = S + "3-Poison ";
	}
	if (Lightning)
	{
		S = S + "4-Lightning ";
	}
	S = S + "You can use one of them " + to_string(2 - Turn) + " more Time ";
	if (Turn < 2)
	{
		return 1;
	}
	else
		return 0;
}

void PlayerPower::rTurn()
{
	Turn = 0;
}
