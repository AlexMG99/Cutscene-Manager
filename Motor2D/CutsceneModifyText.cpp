#include "j1App.h"
#include "CutsceneManager.h"
#include "CutsceneModifyText.h"
#include "CutsceneText.h"
#include "UILabel.h"

CutsceneModifyText::CutsceneModifyText(uint start, uint duration, std::string name, std::string action, std::string text):CutsceneAction(start,duration)
{
	this->name = name;

	if (action == "activate")
	{
		type = ACTIVATE;
	}
	else if (action == "deactivate")
	{
		type = DEACTIVATE;
	}
	else if (action == "change")
	{
		type = CHANGE;
		this->text = text;
	}
}

CutsceneModifyText::~CutsceneModifyText()
{
}

void CutsceneModifyText::Execute(float dt)
{
	element = (CutsceneText*)App->cutscene_manager->elements.find(name)->second;

	switch (type)
	{
	case ACTIVATE:
		element->ChangeState(true);
		break;
	case DEACTIVATE:
		element->ChangeState(false);
		break;
	case CHANGE:
		element->text->SetText(text);
		break;
	default:
		break;
	}

}
