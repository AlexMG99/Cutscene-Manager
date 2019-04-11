#ifndef _CUTSCENE_TEXT_H_
#define _CUTSCENE_TEXT_H_

#include "CutsceneElement.h"

class UILabel;

class CutsceneText :public CutsceneElement {
public:
	CutsceneText(int pos_x, int pos_y, std::string text, uint size, bool image);
	~CutsceneText();

	void ChangeState(bool active);

public:
	UILabel* text = nullptr;

};



#endif // !_CUTSCENE_TEXT_H_

