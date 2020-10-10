#pragma once

#include "Card.h"
class CardFourteen : public Card
{
	static bool loaded;
	static bool saved;

	friend NewGameAction;
	static int CardPrice;
	static int Fees;
	static int Check;
	static Player* Owner;

public:
	CardFourteen(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardFourteen();

	void Save(ofstream& Outfile, int Type);
	void Load(ifstream& Infile);

	 void editsetup();
	static void loadsetup();
	static void savesetup();
};
