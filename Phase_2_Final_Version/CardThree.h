#pragma once

#include "Card.h"

class CardThree : public Card
{
	CellPosition NC;
	Ladder* L = NULL;
public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player

	void Save(ofstream& Outfile, int Type);


	virtual ~CardThree(); // A Virtual Destructor
};
