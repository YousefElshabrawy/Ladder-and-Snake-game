#include "NewGameAction.h"

#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	int i = 0;
	while(i<4 || (pGrid->GetCurrentPlayer())->GetplayerNum()!=0)
	{
		(pGrid->GetCurrentPlayer())->rest(pGrid);
		(pGrid->GetCurrentPlayer())->SetWallet(100);
		pGrid->AdvanceCurrentPlayer();
		i++;
	}
	CardTen::Check = 0;
	CardEleven::Check = 0;
	CardTwelve::Check = 0;
	CardThirteen::Check = 0;
	CardFourteen::Check = 0;
}

NewGameAction::~NewGameAction()
{

}
