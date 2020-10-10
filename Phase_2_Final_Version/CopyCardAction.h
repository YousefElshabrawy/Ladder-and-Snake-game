#pragma once
#include"Action.h"

class CopyCardAction :public Action
{
protected:
	CellPosition clicked;
public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

