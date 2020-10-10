#pragma once
#include "Grid.h"
#include"Player.h"
class Grid;
class PlayerPower
{
	int Turn = 0;
	bool Poison = 1;
	bool Ice = 1;
	bool Fire = 1;
	bool Lightning = 1;
public:
	bool PoisonF(int PN, Grid* pGrid);
	bool IceF(int PN, Grid* pGrid);
	bool FireF(int PN, Grid* pGrid);
	bool LightningF(int PN, Grid* pGrid);
	bool Available(string &S);
	void rTurn();
};

