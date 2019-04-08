#include "j1App.h"
#include "CutsceneMoveEntity.h"
#include "CutsceneManager.h"
#include "CutsceneEntity.h"

CutsceneMoveEntity::CutsceneMoveEntity(uint start, uint duration, float speed_x, float speed_y):CutsceneAction(start,duration)
{
	player_speed = { speed_x, speed_y };
}

void CutsceneMoveEntity::Execute(float dt)
{
	double start = App->cutscene_manager->GetTimer() - start_time;

	CutsceneEntity* element = (CutsceneEntity*)App->cutscene_manager->elements.find("gold")->second;
	if (start < duration_time)
	{
		element->GetEntity()->speed = { player_speed.x * dt, player_speed.y * dt };
		if (duration_time - start < 100)
		{
			element->GetEntity()->speed = { 0,0 };
		}
	}
}
