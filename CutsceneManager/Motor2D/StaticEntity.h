#ifndef _STATIC_ENTITY_H_
#define _STATIC_ENTITY_H_

#include "Entity.h"

enum Static_State {
	STATIC_IDLE,
	STATIC_CONSTRUCT
};


class StaticEntity : public Entity
{
public:
	StaticEntity(fPoint position);
	~StaticEntity();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();

protected:
	Static_State state = STATIC_IDLE;
};

#endif // _STATIC_ENTITY_H_



