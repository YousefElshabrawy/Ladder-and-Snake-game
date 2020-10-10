#include"ToPlayModeAction.h"
#include"Action.h"



ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ToPlayModeAction::ReadActionParameters()
{




}

void ToPlayModeAction::Execute()
{


	Output* pOut = pManager->GetGrid()->GetOutput();
	pOut->CreatePlayModeToolBar();


}