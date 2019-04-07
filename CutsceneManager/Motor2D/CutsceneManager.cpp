#include "CutsceneManager.h"
#include "p2Log.h"

CutsceneManager::CutsceneManager()
{
	name = "cutscene_manager";
}

bool CutsceneManager::Awake(pugi::xml_node &config)
{
	LOG("Starting Cutscene Manager:");
	bool ret = false;

	pugi::xml_parse_result result = cutscene_file.load_file(config.first_child().child_value());

	if (result == NULL)
		LOG("Could not load map xml file cutscene.xml. Pugi error: %s", result.description());
	else
		ret = true;

	return ret;
}

bool CutsceneManager::LoadCutscene(CutsceneCode code, CutsceneType type)
{





	return true;
}
