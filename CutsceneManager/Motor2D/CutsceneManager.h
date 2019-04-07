#ifndef _CUTSCENE_MANAGER_H__
#define _CUTSCENE_MANAGER_H__

#include "Module.h"
#include "PerfTimer.h"


enum CutsceneType
{
	PRE_RENDERED,
	IN_GAME
};

enum CutsceneCode
{
	CUTSCENE_1,
	CUTSCENE_2
};

class Cutscene {
public:

	Cutscene(uint start, uint end)
	{
		start_time = start;
		end_time = start;
	};
	virtual ~Cutscene();

	virtual bool Execute() { return true; };

private:
	uint start_time;
	uint end_time;
};



class CutsceneManager: public Module {
public:

	CutsceneManager();
	virtual ~CutsceneManager() {};

	bool Awake(pugi::xml_node&);

	bool Start() { return true; };
	bool Update(float dt) { return true; };
	bool CleanUp() { return true; };

	bool LoadCutscene(CutsceneCode code, CutsceneType type);
	void ExecuteCutscene() {};

private:
	PerfTimer cutscene_timer;

	pugi::xml_document cutscene_file;
	std::vector<Cutscene*> cutscenes;
};




#endif // !_CUTSCENE_MANAGER_H__

