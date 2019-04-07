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

bool CutsceneManager::LoadCutscene(CutsceneCode code)
{	
	//TODO 1: Iterate the differents cutscene. Save the cutscene in the cutscenes vector.

	Cutscene* cutscene = nullptr;

	for(pugi::xml_node cutscene_node = cutscene_file.first_child().child("cutscene"); cutscene_node; cutscene_node = cutscene_node.next_sibling())
	{
		uint start = cutscene_node.child("time").attribute("start").as_uint();
		uint end = cutscene_node.child("time").attribute("end").as_uint();
		cutscene = new Cutscene(start, end, code);

		cutscenes.push_back(cutscene);
	}

	return true;
}

bool BuildingConstruction::Execute()
{


	return true;
}
