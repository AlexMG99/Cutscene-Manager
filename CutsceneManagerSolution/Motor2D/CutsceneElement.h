#ifndef _CUTSCENE_ELEMENT_H_
#define _CUTSCENE_ELEMENT_H_

#include <string>

class CutsceneElement
{
public:
	CutsceneElement() {};
	virtual ~CutsceneElement() {};

public:
	bool active = false;
	std::string name;
};




#endif // !_CUTSCENE_ELEMENT_H_

