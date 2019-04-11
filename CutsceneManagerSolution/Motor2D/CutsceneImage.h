#ifndef _CUTSCENE_IMAGE_H_
#define _CUTSCENE_IMAGE_H_

#include "CutsceneElement.h"

class SDL_Rect;
class UIImage;

class CutsceneImage :public CutsceneElement
{
public:
	CutsceneImage(int pos_x, int pos_y, SDL_Rect rect, bool image);
	~CutsceneImage();

	void ChangeState(bool active);

private:
	UIImage* image = nullptr;
};


#endif // !_CUTSCENE_IMAGE_H_

