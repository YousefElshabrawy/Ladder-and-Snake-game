#include "Snake.h"
#include "Ladder.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.VCell() > startCellPos.VCell() && endCellPos.HCell() == startCellPos.HCell())
		this->endCellPos = endCellPos;
	
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	// 2- Apply the Snake's effect by moving the player to the startCellPos
	pPlayer->PreventPF();
	pPlayer->Move(pGrid, (GetStartPosition().GetCellNum()) - ((pPlayer->GetCell())->GetCellPosition()).GetCellNum());
	pPlayer->MturnCount();
	//    Review the "pGrid" functions and decide which function can be used for that
	pOut->ClearStatusBar();

//	pGrid->UpdatePlayerCell(pPlayer, position); yousef think so
}

CellPosition Snake::GetStartPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& Outfile, int Type)
{
	if (Type == 1)
	{
		Outfile <<position.GetCellNum() << " " <<endCellPos.GetCellNum() << endl;
	}
}

void Snake::Load(ifstream& Infile)
{
		int x, y;
		Infile >> x>> y;
		CellPosition c1(x);
		CellPosition c2(y);
	    position = c1;
		endCellPos = c2;
	

}

bool Snake::IsOverLapping(GameObject* newObj)const
{
	Snake* S = dynamic_cast <Snake*>(newObj);
	Ladder* L = dynamic_cast <Ladder*>(newObj);
	if (S)
	{
		if ((S->position).HCell() == position.HCell())
		{
			if (position.VCell() > (S->endCellPos).VCell() || (S->position).VCell() > endCellPos.VCell())
				return false;
			else
				return true;
		}
		else
			return false;
	}
	else if (L)
	{
		if ((L->GetPosition()).HCell() == position.HCell())
		{
			if (position.VCell() ==L->GetEndPosition().VCell())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	S = NULL;
}

Snake::~Snake()
{
}
