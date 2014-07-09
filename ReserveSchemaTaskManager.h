#ifndef _RESERVE_SCHEMA_TASK_MANAGER_H
#define _RESERVE_SCHEMA_TASK_MANAGER_H
#include "TaskManagerInterface.h"

class ReserveSchemaTaskManager: public TaskManagerInterface
{
	virtual int GetStrategyCode(){return 3;}
	virtual int EndCall(Task& x);
	virtual int StartTask(std::vector<Task>::iterator& x);
};
#endif