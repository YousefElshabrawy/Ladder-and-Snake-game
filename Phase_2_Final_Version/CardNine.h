#pragma once

#include "Card.h"


class CardNine :	public Card
{
	
	CellPosition NC;

public:
	CardNine(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	
	void Save(ofstream& Outfile, int Type);
	void Load(ifstream& Infile);


	virtual ~CardNine(); 

	void setcell(Card*pCard);
};
