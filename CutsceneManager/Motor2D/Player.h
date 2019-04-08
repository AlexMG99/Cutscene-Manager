#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

enum PlayerState {
	WALKING_DOWN = 0,
	WALKING_RIGHT,
	WALKING_UP,
	WALKING_LEFT,
	IDLE_DOWN,
	IDLE_RIGHT,
	IDLE_UP,
	IDLE_LEFT
	
};


class Player : public Entity
{
public:
	Player(fPoint position);
	~Player();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();

protected:
	PlayerState state = WALKING_DOWN;
};

#endif // _STATIC_ENTITY_H_



