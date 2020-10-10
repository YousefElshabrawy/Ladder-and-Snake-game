#pragma once

#include "Card.h"
#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> 

class CardSeven : public Card  
{
	int RollDice;

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player

	void Save(ofstream& Outfile, int Type);


	virtual ~CardSeven(); // A Virtual Destructor
};

