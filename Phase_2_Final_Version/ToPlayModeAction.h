#pragma once
#include"Action.h"

class ToPlayModeAction :public Action
{

public:
	ToPlayModeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

