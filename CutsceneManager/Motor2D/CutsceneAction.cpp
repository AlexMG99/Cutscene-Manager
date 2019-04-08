#include "CutsceneAction.h"

void CutsceneAction::SetActive(bool active)
{
	this->active = active;
}

bool CutsceneAction::IsActive() const
{
	return active;
}
