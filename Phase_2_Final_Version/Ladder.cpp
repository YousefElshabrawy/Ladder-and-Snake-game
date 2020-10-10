#include "Ladder.h"
#include "Snake.h"
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	///TODO: Do the needed validation
	if (endCellPos.VCell() < startCellPos.VCell() && endCellPos.HCell() == startCellPos.HCell())
		this->endCellPos = endCellPos;

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pPlayer->PreventPF();
	pPlayer->Move(pGrid,GetEndPosition().GetCellNum()-((pPlayer->GetCell())->GetCellPosition()).GetCellNum());
	pPlayer->MturnCount();
	//    Review the "pGrid" functions and decide which function can be used for that
	pOut->ClearStatusBar();
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& Outfile, int Type)
{
	if (Type == 0)
	{
		Outfile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}

void Ladder::Load(ifstream& Infile)
{
		int x, y;
		Infile >> x >> y;
		CellPosition c1(x);
		CellPosition c2(y);
		position = c1;
		endCellPos = c2;
}

bool Ladder::IsOverLapping(GameObject* newObj) const
{
	Ladder* L = dynamic_cast <Ladder*>(newObj);
	Snake *S= dynamic_cast <Snake*>(newObj);
	if (L)
	{
		if ((L->position).HCell() == position.HCell())
		{
			if (position.VCell() < (L->endCellPos).VCell() || (L->position).VCell() < endCellPos.VCell())
				return false;
			else
				return true;
		}
		else
			return false;
	}

	else if (S)
	{
		if ((S->GetPosition()).HCell() == position.HCell())
		{
			if ((S->GetPosition()).VCell() == GetEndPosition().VCell())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	else
		return false;

	L = NULL;
}


Ladder::~Ladder()
{
}
