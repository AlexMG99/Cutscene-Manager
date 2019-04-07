#include "Entity.h"
#include "Textures.h"
#include "j1App.h"

Entity::Entity(fPoint position)
{
	this->position = position;

	sprite = App->tex->Load("building.png");

}


Entity::~Entity()
{
}

void Entity::LoadAnimations()
{
	////load animations
	//pugi::xml_node animation;
	//for (animation = anim_config.child("animations").first_child(); animation; animation = animation.next_sibling())
	//{
	//	Animation anim;
	//	pugi::xml_node frame;
	//	for (frame = animation.child("frame"); frame; frame = frame.next_sibling("frame"))
	//	{
	//		anim.PushBack({ frame.attribute("x").as_int(), frame.attribute("y").as_int(), frame.attribute("width").as_int(), frame.attribute("height").as_int() });
	//	}
	//	anim.speed = animation.attribute("speed").as_float();
	//	anim.loop = animation.attribute("loop").as_bool(true);

	//	animations.push_back(anim);
	/*}*/
}