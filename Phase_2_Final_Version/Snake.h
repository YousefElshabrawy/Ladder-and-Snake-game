#pragma once
#include "GameObject.h"
#include "Ladder.h"
class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"

	CellPosition endCellPos; // here is the Snake's End Cell Position
public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the Snake by moving player to Snake's end cell

	CellPosition GetStartPosition() const; // A getter for the startCellPos data member
	virtual void Save(ofstream& Outfile, int Type);
	virtual void Load(ifstream& Infile);
	bool IsOverLapping(GameObject* newObj)const ;
	virtual ~Snake(); // Virtual destructor
};
