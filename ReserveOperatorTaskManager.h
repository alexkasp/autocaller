#ifndef RESERVER_OPERATOR_TASK_MANAGER
#define RESERVER_OPERATOR_TASK_MANAGER
#include "TaskManagerInterface.h"

class ReserveOperatorTaskManager: public TaskManagerInterface
{
	virtual int GetStrategyCode(){return 2;}
	virtual int EndCall(Task& x);
	virtual int StartTask(std::vector<Task>::iterator& x);
};
#endif