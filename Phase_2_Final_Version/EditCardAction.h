#pragma once
#include"Action.h"


class EditCardAction :public Action
{
	CellPosition clicked;

public:
	EditCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

