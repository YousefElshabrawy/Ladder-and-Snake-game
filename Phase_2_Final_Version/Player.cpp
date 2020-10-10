#include "Player.h"
#include "GameObject.h"

Player::Player(Cell* pCellx, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	pCell = pCellx;
	turnCount = 0;
	Prevent = 0;
	PP = new PlayerPower();
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetplayerNum() const
{
	return playerNum;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	// 3- Set the justRolledDiceNum with the passed diceNumber
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	// 6- Apply() the game object of the reached cell (if any)
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	
	if (Poison > 0 && PreventP)
	{
		diceNumber--;
		Poison--;
	}
	if (Fire > 0 && PreventP)
	{
		wallet = wallet - 20;
		Fire--;
	}

	if ((turnCount+1)%3 == 0)
	{
		Output* pOut = pGrid->GetOutput();
		if (wallet < 0)
		{
			wallet =wallet+diceNumber*10;
		}
		if (Prevent == 0)
		{
			Input* pIn = pGrid->GetInput();
			pOut->PrintMessage("If you wnat to use special power instead of recharging type 1 else 0");
			int x = pIn->GetInteger(pOut);
			if (x == 0)
			{
				wallet = wallet + diceNumber * 10;
			}
			if (x == 1)
			{
				string S;
				if (PP->Available(S))
				{
					pOut->PrintMessage(S);
					int x=pIn->GetInteger(pOut);
					if (x == 1)
					{
						pOut->PrintMessage("Type a Player Number");
						int PN = pIn->GetInteger(pOut);
						if (PP->IceF(PN, pGrid))
						{
							pOut->PrintMessage("Ice activated");
							pIn->GetCellClicked();
						}
					}
					else if (x == 2)
					{
						pOut->PrintMessage("Type a Player Number");
						int PN = pIn->GetInteger(pOut);
						if (PP->FireF(PN, pGrid))
						{
							pOut->PrintMessage("Fire activated");

						}
					}
					else if (x == 3)
					{
						pOut->PrintMessage("Type a Player Number");
						int PN = pIn->GetInteger(pOut);
						if(PP->PoisonF(PN, pGrid))
						{
							pOut->PrintMessage("Poison activated");
						}
					}
					else if (x == 4)
					{
						if (PP->LightningF((pGrid->GetCurrentPlayer())->GetplayerNum(), pGrid))
						{
							pOut->PrintMessage("Lightning activated");
							
						}
					}
					else
					{
						pOut->PrintMessage("There is no such spectial power,Click any where to continue...");
						pIn->GetCellClicked();
						wallet = wallet + diceNumber * 10;
					}
				}
				else
				{
					pOut->PrintMessage("You finished your spectial power,Click any where to continue...");
					pIn->GetCellClicked();
					wallet = wallet + diceNumber * 10;
				}
			}
		}
		if (Prevent > 0)
		{
			Prevent--;
		}
		turnCount++;
		pOut->ClearStatusBar();
		return;
	}

	if (wallet < 0)
	{
		pGrid->PrintErrorMessage("You can't Move or use spetial power as you don't have sufficient wallet value,Click any where to continue");
	}
	else
	{
		if (Prevent == 0)
		{
			justRolledDiceNum = diceNumber;

			if (pCell->GetCellPosition().GetCellNum() == NumHorizontalCells * NumVerticalCells)
			{
				pGrid->SetEndGame(true);
				pGrid->UpdatePlayerCell(this, CellPosition(99));
				return;
			}
			pGrid->UpdatePlayerCell(this, CellPosition((pCell->GetCellPosition()).GetCellNum() + diceNumber));
			if (pCell->GetGameObject() != NULL)
			{
				pCell->GetGameObject()->Apply(pGrid, this);
			}
		}
	}

	if (Prevent > 0)
	{
		Prevent--;
	}
	
	turnCount++;
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::MturnCount()
{
	turnCount--;
	PreventP = 1;
}
void Player::PreventMoving(int N)
{
	Prevent = N+1;
}
void Player::rest(Grid* pGrid)
{
	int M = (GetCell()->GetCellPosition()).GetCellNum();
	turnCount = 0;
	Move(pGrid, 1 - M);
	turnCount = 0;
	Prevent = 0;
	PP->rTurn();
	Poison = 0;
	Fire = 0;
	PreventP = 1;
}
void Player::FireP()
{
	Fire = 3;
}
void Player::PreventPF()
{
	PreventP = 0;
}
void Player::PoisonP()
{
	Poison = 5;
}