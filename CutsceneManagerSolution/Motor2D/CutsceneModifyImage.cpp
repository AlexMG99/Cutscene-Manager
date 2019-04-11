#include "j1App.h"
#include "CutsceneManager.h"
#include "CutsceneModifyImage.h"
#include "CutsceneImage.h"
#include "UILabel.h"

CutsceneModifyImage::CutsceneModifyImage(uint start, uint duration, std::string name, std::string action):CutsceneAction(start,duration)
{
	this->name = name;

	if (action == "activate")
	{
		type = ACTIVATE_IMAGE;
	}
	else if (action == "deactivate")
	{
		type = DEACTIVATE_IMAGE;
	}

}

CutsceneModifyImage::~CutsceneModifyImage()
{
}

void CutsceneModifyImage::Execute(float dt)
{
	element = (CutsceneImage*)App->cutscene_manager->elements.find(name)->second;

	switch (type)
	{
	case ACTIVATE_IMAGE:
		element->ChangeState(true);
		break;
	case DEACTIVATE_IMAGE:
		element->ChangeState(false);
		break;
	default:
		break;
	}

}
