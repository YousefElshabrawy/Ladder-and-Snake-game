#pragma once
#include"Action.h"
#include"fstream"
#include"Grid.h"

class LoadGridAction :public Action
{
	string filename;
public:
	LoadGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

