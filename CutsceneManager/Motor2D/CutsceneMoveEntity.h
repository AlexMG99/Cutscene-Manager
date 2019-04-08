#ifndef _CUTSCENE_MOVE_ENTITY_H_
#define _CUTSCENE_MOVE_ENTITY_H_

#include "CutsceneAction.h"
#include "p2Point.h"

class CutsceneMoveEntity :public CutsceneAction {
public:
	CutsceneMoveEntity(uint start, uint duration, float speed_x, float speed_y);
	~CutsceneMoveEntity() {};

	void Execute(float dt);

protected:
	fPoint player_speed;
};




#endif
