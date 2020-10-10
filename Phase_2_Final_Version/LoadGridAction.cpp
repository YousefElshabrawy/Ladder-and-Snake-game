#include "LoadGridAction.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"


LoadGridAction::LoadGridAction(ApplicationManager* pApp) :Action(pApp)
{

}

void LoadGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();

	Pout->PrintMessage("enter the name of the text folder followed by .txt");
	filename = Pin->GetSrting(Pout);
	Pout->ClearStatusBar();
}

void LoadGridAction::Execute()
{


	ReadActionParameters();

	


	ifstream Infile;
	Infile.open(filename);

	if (Infile.fail()) 
	{
		Output *Out= pManager->GetGrid()->GetOutput();
		Input* In = pManager->GetGrid()->GetInput();
		Out->PrintMessage("you entered file doesnt exist..click to continue");
		In->GetCellClicked();
		Out->ClearStatusBar();
		return;
	}
		

	pManager->GetGrid()->Load_cleanups();

	int objectnum;
	GameObject** GameOPtr;

	Infile >> objectnum; 
	
	//start saving ladders
	GameOPtr = new GameObject*[objectnum];

	for (int i = 0; i < objectnum; i++)
	{
		CellPosition temp1, temp2;
		GameOPtr[i] = new Ladder(temp1, temp2);
	}

	for (int i = 0; i < objectnum; i++)
	{
		GameOPtr[i]->Load(Infile);
		pManager->GetGrid()->AddObjectToCell(GameOPtr[i]);

	}


/*
changed
	for (int i = 0; i < objectnum; i++)
	{
		CellPosition temp1, temp2;
		Ladder* L = new Ladder(temp1, temp2);
		L->Load(Infile, 0);
		pManager->GetGrid()->AddObjectToCell(L);

	}
*/
//end saving ladders

//start saving snakes

	Infile >> objectnum;

	GameOPtr = new GameObject * [objectnum];

	for (int i = 0; i < objectnum; i++)
	{
		CellPosition temp1, temp2;
		GameOPtr[i] = new Snake(temp1, temp2);
	}

	for (int i = 0; i < objectnum; i++)
	{
		GameOPtr[i]->Load(Infile);
		pManager->GetGrid()->AddObjectToCell(GameOPtr[i]);

	}



/*
	for (int i = 0; i < objectnum; i++)
	{
		CellPosition temp1, temp2;
		Snake* S = new Snake(temp1, temp2);
		S->Load(Infile, 1);
		pManager->GetGrid()->AddObjectToCell(S);

	}
*/
	//end saving snakes

	//start saving cards

	Infile >> objectnum;
	int kind;


	Card* CardOPtr;

	for (int i = 0; i < objectnum; i++) 
	{
		Infile >> kind;
		CellPosition temp;

		switch (kind) 
		{
		case 1:
			CardOPtr = new CardOne(temp);
			break;
		case 2:
			CardOPtr = new CardTwo(temp);
			break;
		case 3:
			CardOPtr = new CardThree(temp);
			break;
		case 4:
			CardOPtr = new CardFour(temp);
			break;
		case 5:
			CardOPtr = new CardFive(temp);
			break;
		case 6:
			CardOPtr = new CardSix(temp);
			break;
		case 7:
		    CardOPtr = new CardSeven(temp);
			break;
		case 8:
			CardOPtr = new CardEight(temp);
			break;
		case 9:
			CardOPtr = new CardNine(temp);
			break;
		case 10:
			CardOPtr = new CardTen(temp);
			break;
		case 11:
			CardOPtr = new CardEleven(temp);
			break;
		case 12:
			CardOPtr = new CardTwelve(temp);
			break;
		case 13:
			CardOPtr = new CardThirteen(temp);
			break;
		case 14:
			CardOPtr = new CardFourteen(temp);
			break;

		default:
			break;
		}
		CardOPtr->Load(Infile);
		pManager->GetGrid()->AddObjectToCell(CardOPtr);

	}


/*changed
	for (int i = 0; i < objectnum; i++)
	{
		CellPosition temp1, temp2;
		Card* C = new Card(temp1);
		C->Load(Infile, 3);
		pManager->GetGrid()->AddObjectToCell(C);

	}
*/

	CardTen::loadsetup();
	CardEleven::loadsetup();
	CardTwelve::loadsetup();
	CardThirteen::loadsetup();
	CardFourteen::loadsetup();
}