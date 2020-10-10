#pragma once
#include"Action.h"
#include"CopyCardAction.h"

class CutCardAction :public CopyCardAction
{

public:
	CutCardAction(ApplicationManager* pApp);


	void Execute();

};

