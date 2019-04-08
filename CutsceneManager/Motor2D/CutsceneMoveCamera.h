#ifndef _CUTSCENE_MOVE_CAMERA_H
#define _CUTSCENE_MOVE_CAMERA_H

#include "CutsceneAction.h"
#include "p2Point.h"

class CutsceneMoveCamera :public CutsceneAction
{
public:
	CutsceneMoveCamera(uint start, uint duration, int speed_x, int speed_y);
	~CutsceneMoveCamera() {};

	void Execute();

private:
	iPoint camera_speed;




};




#endif