#pragma once

#include "Card.h"

class CardTwo : public Card
{
	// CardTwo Parameters:
	int walletAmount;

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player

	void Save(ofstream& Outfile, int Type);
	void Load(ifstream& Infile);

	virtual ~CardTwo(); // A Virtual Destructor

	void setWalletAmount(Card* pCard);
};
