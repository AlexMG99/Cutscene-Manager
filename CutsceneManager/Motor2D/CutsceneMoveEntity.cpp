#include "j1App.h"
#include "CutsceneMoveEntity.h"
#include "CutsceneManager.h"
#include "CutsceneEntity.h"

CutsceneMoveEntity::CutsceneMoveEntity(uint start, uint duration, float speed_x, float speed_y, std::string entity):CutsceneAction(start,duration)
{
	player_speed = { speed_x, speed_y };
	entity_name = entity;
}

void CutsceneMoveEntity::Execute(float dt)
{
	CutsceneEntity* element = nullptr;
	double start = App->cutscene_manager->GetTimer() - start_time;

	if (entity_name == "gold")
	{
		element = (CutsceneEntity*)App->cutscene_manager->elements.find("gold")->second;
	}
	else if (entity_name == "silver")
	{
		element = (CutsceneEntity*)App->cutscene_manager->elements.find("silver")->second;
	}

	if (start < duration_time)
	{
		element->GetEntity()->speed = { player_speed.x * dt, player_speed.y * dt };
		if (duration_time - start < 100)
		{
			element->GetEntity()->speed = { 0,0 };
		}
	}
}
