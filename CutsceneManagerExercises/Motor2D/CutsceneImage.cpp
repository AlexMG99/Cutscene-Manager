#include "j1App.h"
#include "CutsceneImage.h"
#include "p2Log.h"
#include "GUI.h"
#include "UIImage.h"
#include "SDL/include/SDL_rect.h"

CutsceneImage::CutsceneImage(int pos_x, int pos_y, SDL_Rect rect, bool image)
{
	this->image = App->gui->CreateImage({ pos_x, pos_y }, rect, image);
}

CutsceneImage::~CutsceneImage()
{
	App->gui->DeleteElement(image);
}


void CutsceneImage::ChangeState(bool active)
{
	this->image->image = active;
}