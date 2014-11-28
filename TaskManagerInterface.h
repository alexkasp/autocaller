#ifndef __TASKMANAGERINTERFACE
#define __TASKMANAGERINTERFACE

#include "Task.h"
#include "astmanager.h"


class TaskManagerInterface
{
	protected:
		std::vector<Task> Tasks;
		AsteriskManager manager;

	public:
		void PrintOperators();
		void PrintCalls();
		void PrintNumbers();
		virtual int GetStrategyCode() =0;

		TaskManagerInterface();
		int CleanTask();
		virtual ~TaskManagerInterface(){};
		void BeginCallHandle(std::string num,std::string calluniqueid);
		virtual int EndCallHandle(std::string num,std::string calluniqueid);
		int CreateTask(std::vector<std::string> _nums,std::vector<std::string> _operators,std::string _caller,std::string _schema,std::string _outline,std::string _TaskName);
		int CreateTask(Task& tsk);
		virtual int EndCall(Task& x) = 0;
		virtual int Start();
		virtual int Start(int TaskIndex);
		virtual int StartTask(std::vector<Task>::iterator& x) = 0;
};
#endif