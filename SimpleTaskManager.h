#ifndef SIMPLE_TASK_MANAGER
#define SIMPLE_TASK_MANAGER
#include "TaskManagerInterface.h"

class SimpleTaskManager: public TaskManagerInterface
{
	public:
		virtual int GetStrategyCode(){return 1;}
		virtual int EndCall(Task& task);
		virtual int StartTask(std::vector<Task>::iterator& x);
};
#endif