#include "p2Log.h"

#include "j1App.h"
#include "Render.h"
#include "Textures.h"

#include "Player.h"



Player::Player(fPoint position) : Entity(position)
{

}


Player::~Player()
{
	LOG("destructor called");
}

bool Player::Update(float dt)
{

	current_frame = animations[state].GetCurrentFrame(dt);

	return true;
}

bool Player::CleanUp()
{
	if(sprite)
		App->tex->UnLoad(sprite);

	return true;
}

bool Player::PostUpdate()
{
	fPoint render_position = { position.x - current_frame.w / 2, position.y - current_frame.h };
	App->render->Blit(sprite, render_position.x, render_position.y, &current_frame);

	return true;
}

