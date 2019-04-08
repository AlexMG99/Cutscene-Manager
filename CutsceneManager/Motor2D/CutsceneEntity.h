#ifndef _CUTSCENE_ENTITY_H_
#define _CUTSCENE_ENTITY_H_

#include "CutsceneElement.h"
#include "Entity.h"


class CutsceneEntity :public CutsceneElement {
public:
	CutsceneEntity() {};
	~CutsceneEntity() {};

private:
	Entity* entity = nullptr;

};

#endif
