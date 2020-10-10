#pragma once

#include "Card.h"

class CardSix : public Card
{

public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Save(ofstream& Outfile, int Type);


	virtual ~CardSix(); // A Virtual Destructor
};

