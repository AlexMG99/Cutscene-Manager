#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>

#include "p2Defs.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class Entity
{
public:
	Entity(fPoint position);
	~Entity();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt) { return true; };
	virtual bool PostUpdate() { return true; };
	virtual bool CleanUp() { return true; };

	void LoadAnimations();


public:
	fPoint position;

protected:
	std::vector<Animation> animations;
	SDL_Rect current_frame;
	SDL_Texture* sprite = nullptr;
};
#endif // _ENTITY_H_