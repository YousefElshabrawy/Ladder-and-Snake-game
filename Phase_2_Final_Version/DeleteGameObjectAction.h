#pragma once
#include"Action.h"

class DeleteGameObjectAction :public Action
{
	CellPosition clicked;
public:
	DeleteGameObjectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

