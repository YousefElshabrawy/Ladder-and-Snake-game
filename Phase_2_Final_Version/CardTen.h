#pragma once
#include "Card.h"
class CardTen :	public Card
{
	static bool loaded;
	static bool saved;

static int CardPrice;
static int Fees;
static int Check;
static Player* Owner;
friend NewGameAction;
public:
	CardTen(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	
	void Save(ofstream& Outfile, int Type);
	void Load(ifstream& Infile);

	virtual ~CardTen(); 

	 void editsetup();
	static void loadsetup();
	static void savesetup();
};
