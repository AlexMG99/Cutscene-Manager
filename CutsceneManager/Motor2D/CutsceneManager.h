#ifndef _CUTSCENE_MANAGER_H__
#define _CUTSCENE_MANAGER_H__

#include "Module.h"
#include "Entity.h"
#include "PerfTimer.h"

enum CutsceneCode
{
	CUTSCENE_1,
	CUTSCENE_2
};

class Cutscene {
public:

	Cutscene(uint start, uint end, CutsceneCode code)
	{
		start_time = start;
		end_time = end;
		this->code = code;
	};

	virtual ~Cutscene() {};

	virtual bool Execute() { return true; };

protected:
	uint start_time;
	uint end_time;
	CutsceneCode code;
};

class BuildingConstruction : public Cutscene
{
public:
	BuildingConstruction(uint32 start_time, uint32 end_time, Entity* actor, float speed) : Cutscene(start_time, end_time, code) {
		this->actor = actor;
		this->speed = speed;
	};
	~BuildingConstruction() {};

	bool Execute();
private:
	Entity* actor = nullptr;
	float speed;
};



class CutsceneManager: public Module {
public:

	CutsceneManager();
	virtual ~CutsceneManager() {};

	bool Awake(pugi::xml_node&);

	bool Start() { return true; };
	bool Update(float dt) { return true; };
	bool CleanUp() { return true; };

	bool LoadCutscene(CutsceneCode code);
	void ExecuteCutscene() {};

private:
	PerfTimer cutscene_timer;

	pugi::xml_document cutscene_file;
	std::vector<Cutscene*> cutscenes;
};




#endif // !_CUTSCENE_MANAGER_H__

