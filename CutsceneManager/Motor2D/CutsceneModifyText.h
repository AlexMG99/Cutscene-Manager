#ifndef _CUTSCENE_MODIFY_TEXT_H
#define _CUTSCENE_MODIFY_TEXT_H

#include "CutsceneAction.h"
#include <string>

enum ActionType {
	DEFAULT = -1,
	ACTIVATE,
	DEACTIVATE,
	CHANGE
};

class CutsceneText;


class CutsceneModifyText :public CutsceneAction
{
public:
	CutsceneModifyText(uint start, uint duration, std::string name, std::string action, std::string text = "");
	~CutsceneModifyText();

	void Execute(float dt);

private:
	CutsceneText*		element = nullptr;
	ActionType			type = DEFAULT;
	std::string			text;
	std::string			name;

};

#endif // !_CUTSCENE_MODIFY_H

