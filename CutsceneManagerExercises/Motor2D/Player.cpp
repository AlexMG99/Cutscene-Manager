#include "p2Log.h"

#include "j1App.h"
#include "Render.h"
#include "Textures.h"

#include "Player.h"



Player::Player(fPoint position, std::string path) : Entity(position, path)
{

}


Player::~Player()
{
	LOG("destructor called");
}

bool Player::Update(float dt)
{
	PerformActions();

	position.x += speed.x;
	position.y += speed.y;
	current_frame = animations[state].GetCurrentFrame(dt);

	return true;
}

bool Player::CleanUp()
{
	if (sprite) 
	{
		App->tex->UnLoad(sprite);
		sprite = nullptr;
	}

	return true;
}

void Player::PerformActions()
{
	if (speed.x == 0 && speed.y == 0)
	{
		switch (state)
		{
		case WALKING_DOWN:
			state = IDLE_DOWN;
			break;
		case WALKING_RIGHT:
			state = IDLE_RIGHT;
			break;
		case WALKING_UP:
			state = IDLE_UP;
			break;
		case WALKING_LEFT:
			state = IDLE_LEFT;
			break;
		default:
			break;
		}
	}
	else
	{
		if (speed.x < 0)
		{
			state = WALKING_LEFT;
		}
		else if (speed.x > 0)
		{
			state = WALKING_RIGHT;
		}

		if (speed.y > 0)
		{
			state = WALKING_DOWN;
		}
		else if (speed.y < 0)
		{
			state = WALKING_UP;
		}
	}
}

bool Player::PostUpdate()
{
	fPoint render_position = { position.x - current_frame.w / 2, position.y - current_frame.h };
	App->render->Blit(sprite, render_position.x, render_position.y, &current_frame);

	return true;
}

