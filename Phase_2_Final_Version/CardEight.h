#pragma once

#include "Card.h"
#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> 

class CardEight : public Card  
{
	bool Check=false;
public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player

	void Save(ofstream& Outfile, int Type);

	virtual ~CardEight(); // A Virtual Destructor
};

