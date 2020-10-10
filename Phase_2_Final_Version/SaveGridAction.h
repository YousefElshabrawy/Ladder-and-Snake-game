#pragma once
#include"Action.h"
#include"fstream"
#include"Grid.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

class SaveGridAction :public Action
{
	string filename;
public:
	SaveGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	void Execute();

};

