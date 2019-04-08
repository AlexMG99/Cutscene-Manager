#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

enum PlayerState {
	IDLE_DOWN = 0,
	IDLE_RIGHT,
	IDLE_UP,
	IDLE_LEFT,
	WALKING_DOWN,
	WALKING_RIGHT,
	WALKING_UP,
	WALKING_LEFT
	
};


class Player : public Entity
{
public:
	Player(fPoint position, std::string path);
	~Player();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();

protected:
	PlayerState state = IDLE_DOWN;
};

#endif // _STATIC_ENTITY_H_



