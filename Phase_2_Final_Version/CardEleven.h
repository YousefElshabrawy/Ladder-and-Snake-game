#pragma once

#include "Card.h"
class CardEleven : public Card
{
	static bool loaded;
	static bool saved;

	friend NewGameAction;
	static int CardPrice;
	static int Fees;
	static int Check;
	static Player* Owner;

public:
	CardEleven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardEleven();

	void Save(ofstream& Outfile, int Type);
	void Load(ifstream& Infile);

	 void editsetup();
	static void loadsetup();
	static void savesetup();
};
