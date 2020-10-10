#include"ToDesignModeAction.h"
#include"Action.h"



ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp):Action(pApp)
{

}

void ToDesignModeAction::ReadActionParameters()
{




}

void ToDesignModeAction::Execute()
{



	Output* pOut = pManager->GetGrid()->GetOutput();
	pOut->CreateDesignModeToolBar();


}