#ifndef _CUTSCENE_MANAGER_H__
#define _CUTSCENE_MANAGER_H__

#include "Module.h"
#include "Entity.h"
#include "PerfTimer.h"
#include "CutsceneAction.h"


class CutsceneManager: public Module {
public:

	CutsceneManager();
	virtual ~CutsceneManager() {};

	bool Awake(pugi::xml_node&);

	bool Start() { return true; };
	bool Update(float dt) { return true; };
	bool CleanUp() { return true; };

	bool LoadCutscene();
	void ExecuteCutscene();

	double GetTimer();

private:
	PerfTimer cutscene_timer;

	pugi::xml_document cutscene_file;
	std::vector<CutsceneAction*> cutscenes;
};




#endif // !_CUTSCENE_MANAGER_H__

