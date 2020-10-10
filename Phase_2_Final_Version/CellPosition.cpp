#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (0 <= v && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else
	{
		vCell = -1;
		return false;
	}
}

bool CellPosition::SetHCell(int h) 
{
	if (0 <= h && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else
	{
		hCell = -1;
		return false;
	}
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (0 <= hCell && hCell < NumHorizontalCells && 0 <= vCell && vCell < NumVerticalCells)
		return true;
	else
		return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	if (cellPosition.hCell >= 0 && cellPosition.vCell >= 0)
		return (NumVerticalCells - (cellPosition.vCell + 1)) * NumHorizontalCells + (cellPosition.hCell + 1);
	else
		return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	CellPosition position;
	if (cellNum > 0 && cellNum < NumVerticalCells * NumHorizontalCells + 1)
	{
		int i;
		for (i = 1; i < NumVerticalCells; i++)
		{
			if (cellNum <= NumHorizontalCells * i)
			{
				break;
			}
		}
		position.SetVCell(NumVerticalCells - i);
		position.SetHCell(cellNum - ((NumVerticalCells - (position.vCell + 1)) * NumHorizontalCells + 1));
	}
	else
	{
		position.SetVCell(-1);
		position.SetHCell(-1);
	}
	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	CellPosition(GetCellNum() + addedNum);
}