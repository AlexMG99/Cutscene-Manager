#include "j1App.h"
#include "Render.h"
#include "CutsceneMoveCamera.h"
#include "CutsceneManager.h"

CutsceneMoveCamera::CutsceneMoveCamera(uint start, uint duration, int speed_x, int speed_y):CutsceneAction(start,duration)
{
	camera_speed.x = speed_x;
	camera_speed.y = speed_y;

	active = true;
}

void CutsceneMoveCamera::Execute()
{
	double start = App->cutscene_manager->GetTimer() - start_time;

	if (start < duration_time)
	{
		App->render->camera.x -= camera_speed.x;
		App->render->camera.y -= camera_speed.y;
	}
}
