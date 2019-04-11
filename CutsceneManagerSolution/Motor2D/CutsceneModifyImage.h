#ifndef _CUTSCENE_MODIFY_IMAGE_H
#define _CUTSCENE_MODIFY_IMAGE_H

#include "CutsceneAction.h"
#include <string>

enum ImageActionType {
	DEFAULT_IMAGE = -1,
	ACTIVATE_IMAGE,
	DEACTIVATE_IMAGE
};

class CutsceneImage;


class CutsceneModifyImage :public CutsceneAction
{
public:
	CutsceneModifyImage(uint start, uint duration, std::string name, std::string action);
	~CutsceneModifyImage();

	void Execute(float dt);

private:
	CutsceneImage*		element = nullptr;
	ImageActionType		type = DEFAULT_IMAGE;
	std::string			name;

};

#endif // !_CUTSCENE_MODIFY_H

