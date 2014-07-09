#include "./EventReader/iexecuter.h"
#include "SimpleTaskManager.h"
#include <map>
#include <vector>

class CallViewer: public ExecuterInterface
{
	
	std::vector<TaskManagerInterface*> managers;

	public:
		CallViewer();
		~CallViewer();
		void AddManager(TaskManagerInterface* manager){managers.push_back(manager);}
		void PrintOperators();
		void PrintCalls();
		void PrintNumbers();
		virtual int Execute(ParamMap& data);
};