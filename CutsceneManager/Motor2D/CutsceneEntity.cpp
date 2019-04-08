#include "j1App.h"
#include "CutsceneEntity.h"
#include "EntityManager.h"

CutsceneEntity::CutsceneEntity(int pos_x, int pos_y, std::string name)
{
	entity = App->entity_manager->CreateEntity({ (float)pos_x, (float)pos_y}, name.c_str());
}

CutsceneEntity::~CutsceneEntity()
{
	App->entity_manager->DeleteEntity(entity);
}
