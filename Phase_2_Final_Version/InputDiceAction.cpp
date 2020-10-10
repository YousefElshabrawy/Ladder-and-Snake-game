#include "InputDiceAction.h"
#include "Grid.h"
#include "Player.h"



InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter a dice number...");
	diceNumber = pIn->GetInteger(pOut);
	if (diceNumber > 6 || diceNumber < 1)
	{
		pGrid->PrintErrorMessage("Invalid dice number it will be changed to one,Click any where to continue...");
		diceNumber = 1;
	}
	pOut->ClearStatusBar();
}

void InputDiceAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	bool EG = pGrid->GetEndGame();
	if (EG)
	{
		pGrid->PrintErrorMessage("The Game was finished ...");
	}
	
	else
	{
		(pGrid->GetCurrentPlayer())->Move(pGrid, diceNumber);
		pGrid->AdvanceCurrentPlayer();
	}

}

InputDiceAction::~InputDiceAction()
{
}
