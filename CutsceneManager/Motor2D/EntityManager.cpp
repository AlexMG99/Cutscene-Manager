#include "j1App.h"
#include "Render.h"
#include "Textures.h"
#include "Input.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"



EntityManager::EntityManager()
{
	name = "entity_manager";
}

EntityManager::~EntityManager()
{
}

bool EntityManager::Awake(pugi::xml_node &)
{
	animations_doc.load_file("anim.xml");
	return true;
}

bool EntityManager::Start()
{
	return true;
}

bool EntityManager::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN)
		draw_path = !draw_path;

	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->Update(dt);
	}

	return true;
}

bool EntityManager::PreUpdate()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->PreUpdate();
	}

	return true;
}

bool EntityManager::PostUpdate()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->PostUpdate();
	}

	return true;
}

bool EntityManager::CleanUp()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->CleanUp();
		entity = entities.erase(entity);
	}
	entities.clear();
	id_count = 0;

	return true;
}

bool EntityManager::Load(pugi::xml_node &)
{
	return true;
}

bool EntityManager::Save(pugi::xml_node &) const
{
	return true;
}

Entity* EntityManager::CreateEntity(fPoint position, std::string path)
{
	std::string id = std::to_string(id_count);
	Entity* entity = nullptr;

	entity = new Player(position, path);

	entities.push_back(entity);
	id_count++;

	return entity;
}

bool EntityManager::DeleteEntity(Entity * entity)
{
	entity->CleanUp();
	entities.remove(entity);
	delete entity;
	return true;
}
