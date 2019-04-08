#ifndef _CUTSCENE_ELEMENT_H_
#define _CUTSCENE_ELEMENT_H_

#include <string>

class CutsceneElement
{
public:
	CutsceneElement() {};
	~CutsceneElement() {};

public:
	bool active;
	std::string path;
	std::string name;
};




#endif // !_CUTSCENE_ELEMENT_H_

