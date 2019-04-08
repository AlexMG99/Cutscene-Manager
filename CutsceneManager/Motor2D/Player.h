#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

enum PlayerState {
	STATIC_IDLE,
	STATIC_WALKING,
	STATIC_ATTACK
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
	PlayerState state = STATIC_IDLE;
};

#endif // _STATIC_ENTITY_H_



