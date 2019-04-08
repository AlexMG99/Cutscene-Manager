#include "Entity.h"
#include "Textures.h"
#include "j1App.h"
#include "EntityManager.h"

Entity::Entity(fPoint position)
{
	this->position = position;

	sprite = App->tex->Load("sprites/pkmn_trainer.png");
	LoadAnimation("player");

}


Entity::~Entity()
{
}

bool Entity::Start()
{
	return true;
}

void Entity::LoadAnimation(std::string entity_name)
{
	pugi::xml_node entity = App->entity_manager->animations_doc.first_child().child(entity_name.c_str());

	pugi::xml_node animation;
	for (animation = entity.child("animations").first_child(); animation; animation = animation.next_sibling())
	{
		Animation anim;
		pugi::xml_node frame;
		for (frame = animation.child("frame"); frame; frame = frame.next_sibling("frame"))
		{
			anim.PushBack({ frame.attribute("x").as_int(), frame.attribute("y").as_int(), frame.attribute("w").as_int(), frame.attribute("h").as_int() });
		}
		anim.speed = animation.attribute("speed").as_float();
		anim.loop = animation.attribute("loop").as_bool(true);

		animations.push_back(anim);
	}
}
