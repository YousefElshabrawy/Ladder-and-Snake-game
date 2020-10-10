#pragma once
#include "Grid.h"
#include "Cell.h"
#include"PlayerPower.h"
class PlayerPower;
class Player
{
	Cell* pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
						   // player number does NOT change after construction (const.)
	bool PreventP = 1;
	int stepCount;		 // step count which is the same as his cellNum: from 1 to					  NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount=0;         // a counter that starts with 0, is incremented with each dice roll
	int Prevent=0;				   // and reset again when reached 3
	int Poison = 0;// it is used to indicate when to move and when to add to your wallet
	int Fire = 0;
	PlayerPower* PP;
public:

	Player(Cell* pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell* cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	int GetplayerNum() const;
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======
	int GetjustRolledDiceNum() const;

	void Move(Grid* pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
												// and Applies the Game Object's effect (if any) of the end reached cell 
												// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string& playersInfo) const; // Appends player's info to the input string, 
	void MturnCount();
	void rest(Grid* pGrid);
	void PreventMoving(int);
	void PoisonP();
	void FireP();
	void PreventPF();
};

