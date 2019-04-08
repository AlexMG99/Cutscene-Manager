#include "CutsceneManager.h"
#include "p2Log.h"
#include "CutsceneMoveCamera.h"
#include "CutsceneMoveEntity.h"
#include "CutsceneEntity.h"
#include "CutsceneMap.h"

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

	CutsceneAction* cutscene_action = nullptr;

	for (pugi::xml_node cutscene_action_node = cutscene_file.first_child().child("actions").child("cutscene"); cutscene_action_node; cutscene_action_node = cutscene_action_node.next_sibling())
	{
		std::string action = cutscene_action_node.attribute("action").as_string();

		uint start = cutscene_action_node.child("time").attribute("start").as_uint();
		uint duration = cutscene_action_node.child("time").attribute("duration").as_uint();

		if (action == "move_camera")
		{
			cutscene_action = new CutsceneMoveCamera(start, duration, cutscene_action_node.child("time").attribute("speed_x").as_int(), cutscene_action_node.child("time").attribute("speed_y").as_int());
		}
		else if (action == "move_entity")
		{
			cutscene_action = new CutsceneMoveEntity(start, duration, 
				cutscene_action_node.child("time").attribute("speed_x").as_float(), cutscene_action_node.child("time").attribute("speed_y").as_float(),
				cutscene_action_node.attribute("entity").as_string());
		}

		actions.push_back(cutscene_action);
	}

	CutsceneElement* cutscene_element = nullptr;

	for (pugi::xml_node cutscene_element_node = cutscene_file.first_child().child("elements").child("element"); cutscene_element_node; cutscene_element_node = cutscene_element_node.next_sibling())
	{
		std::string type = cutscene_element_node.attribute("type").as_string();
		std::string name = cutscene_element_node.attribute("name").as_string();

		if (type == "entity")
		{
			cutscene_element = new CutsceneEntity(cutscene_element_node.attribute("pos_x").as_int(), 
				cutscene_element_node.attribute("pos_y").as_int(),
				cutscene_element_node.attribute("name").as_string());
		}
		else if (type == "map")
		{
			cutscene_element = new CutsceneMap(cutscene_element_node.attribute("path").as_string());
		}

		elements.insert(std::pair <std::string, CutsceneElement*>(name, cutscene_element));
	}

	return true;
}

void CutsceneManager::ExecuteCutscene(float dt)
{
	if (is_executing)
	{
		if (start) {
			cutscene_timer.Start();

			item = actions.begin();
			start = false;
		}

		if ((cutscene_timer.ReadMs() - (*item)->start_time) > (*item)->duration_time)
		{
			(*item)->~CutsceneAction();
			++item;
		}

		if (item != actions.end())
		{
			if(cutscene_timer.ReadMs() > (*item)->start_time)
				(*item)->Execute(dt);
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
