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

	// TODO7: Find the corresponding entity depending on the entity_name that has been passed
	// All the elements are in a map, which first value is a string and a second one is a CutsceneElement
	// there is a function in maps which is find(). You have to find it by the name and acces to the second element. It is only one line

	if (start < duration_time)
	{
		if (element != nullptr) 
		{
			element->GetEntity()->speed = { player_speed.x * dt, player_speed.y * dt };
			if (duration_time - start < 100)
			{
				element->GetEntity()->speed = { 0,0 };
			}
		}
	}
}
