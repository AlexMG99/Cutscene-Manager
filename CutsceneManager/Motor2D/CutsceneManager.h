#ifndef _CUTSCENE_MANAGER_H__
#define _CUTSCENE_MANAGER_H__

#include "Module.h"
#include "Entity.h"
#include "PerfTimer.h"
#include "CutsceneAction.h"
#include "CutsceneElement.h"
#include <map>


class CutsceneManager: public Module {
public:

	CutsceneManager();
	virtual ~CutsceneManager() {};

	bool Awake(pugi::xml_node&);

	bool Start() { return true; };
	bool Update(float dt) { return true; };
	bool CleanUp() { return true; };

	//Cutscene Functions

	bool LoadCutscene();
	void ExecuteCutscene(float dt);
	void ClearCutscene();

	double GetTimer();
	void SetExecuting(bool executing);

private:
	PerfTimer cutscene_timer;
	bool is_executing = false;
	bool start = true;

public:
	pugi::xml_document cutscene_file;
	std::vector<CutsceneAction*> actions;
	std::map<std::string, CutsceneElement*> elements;
	
	std::vector<CutsceneAction*>::iterator item;

};





#endif // !_CUTSCENE_MANAGER_H__

