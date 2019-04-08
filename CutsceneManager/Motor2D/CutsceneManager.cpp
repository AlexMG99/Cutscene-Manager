#include "CutsceneManager.h"
#include "p2Log.h"
#include "CutsceneMoveCamera.h"

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

bool CutsceneManager::LoadCutscene()
{	
	//TODO 1: Iterate the differents cutscene. Save the cutscene in the cutscenes vector.

	CutsceneAction* cutscene = nullptr;

	for(pugi::xml_node cutscene_node = cutscene_file.first_child().child("actions").child("cutscene"); cutscene_node; cutscene_node = cutscene_node.next_sibling())
	{
		std::string name = cutscene_node.attribute("name").as_string();

		uint start = cutscene_node.child("time").attribute("start").as_uint();
		uint duration = cutscene_node.child("time").attribute("duration").as_uint();

		if (name == "move_camera")
		{
			cutscene = new CutsceneMoveCamera(start, duration, cutscene_node.child("time").attribute("speed_x").as_int(), cutscene_node.child("time").attribute("speed_y").as_int());
		}

		cutscenes.push_back(cutscene);
	}

	return true;
}

void CutsceneManager::ExecuteCutscene()
{
	if (is_executing)
	{
		if (start) {
			cutscene_timer.Start();

			item = cutscenes.begin();
			start = false;
		}

		if ((cutscene_timer.ReadMs() - (*item)->start_time) > (*item)->duration_time)
		{
			(*item)->~CutsceneAction();
			++item;
		}

		if (item != cutscenes.end())
		{
			if(cutscene_timer.ReadMs() > (*item)->start_time)
				(*item)->Execute();
		}
		else
		{
			is_executing = false;
			start = true;
		}
	}
}

double CutsceneManager::GetTimer()
{
	return cutscene_timer.ReadMs();
}

void CutsceneManager::SetExecuting(bool executing)
{
	is_executing = executing;
}
