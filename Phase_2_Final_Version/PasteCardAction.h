#pragma once
#include"Action.h"

class PasteCardAction :public Action
{
	CellPosition clicked;
public:
	PasteCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

