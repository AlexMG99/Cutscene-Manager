#ifndef _CUTSCENE_ENTITY_H_
#define _CUTSCENE_ENTITY_H_

#include "CutsceneElement.h"
#include "Entity.h"


class CutsceneEntity :public CutsceneElement {
public:
	CutsceneEntity(int pos_x, int pos_y, std::string name);
	~CutsceneEntity();

	Entity* GetEntity();

protected:
	Entity* entity = nullptr;

};

#endif
