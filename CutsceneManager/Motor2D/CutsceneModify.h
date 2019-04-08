#ifndef _CUTSCENE_MODIFY_H
#define _CUTSCENE_MODIFY_H

#include "CutsceneAction.h"

enum ActionType {
	DEACTIVATE,
	CHANGE
};


class CutsceneModify :public CutsceneAction
{
public:
	CutsceneModify();
	~CutsceneModify();

	void Execute(float dt);
};

#endif // !_CUTSCENE_MODIFY_H

