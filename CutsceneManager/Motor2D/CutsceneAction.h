#ifndef _CUTSCENE_ACTION_H_
#define _CUTSCENE_ACTION_H_
#include "p2Defs.h"
#include "PerfTimer.h"

class CutsceneAction {
public:

	CutsceneAction(uint start, uint duration)
	{
		start_time = start;
		duration_time = duration;
	};

	virtual ~CutsceneAction() {};

	virtual void Execute() {};

public:
	uint start_time;
	uint duration_time;

};

#endif // !

