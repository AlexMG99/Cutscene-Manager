#include "CutsceneMap.h"
#include "j1App.h"
#include "Map.h"

CutsceneMap::CutsceneMap(std::string path)
{

	App->map->Load(path.c_str());
}

CutsceneMap::~CutsceneMap()
{
	App->map->CleanUp();
}
