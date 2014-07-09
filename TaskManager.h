#include "Task.h"
#include "astmanager.h"

/*
	Interface for task manager childs should implement in EndCallHandle 
	call politic. Simple calls or Predictive calls
*/

class TaskManagerInterface
{
	std::vector<Task> Tasks;
	AsteriskManager manager;

	public:
		void BeginCallHandle();
		virtual int EndCallHandle() = 0;
};