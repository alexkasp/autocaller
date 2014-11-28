#include "TaskManagerInterface.h"

int TaskManagerInterface::CleanTask()
{
	for(auto x = Tasks.begin();x!=Tasks.end();)
	{
		if(x->IsComplete())
			x = Tasks.erase(x);
		else
			++x;
	}

	return Tasks.size();
}

void TaskManagerInterface::BeginCallHandle(std::string num,std::string calluniqueid)
{
	for(auto x = Tasks.begin();x!=Tasks.end();++x)
	{
		(*x).IncOperatorCalls(num,calluniqueid);
	}
}

int TaskManagerInterface::EndCallHandle(std::string num,std::string calluniqueid)
{
	for(auto x = Tasks.begin();x!=Tasks.end();++x)
	{
		if((*x).DecOperatorCalls(num,calluniqueid))
		{
			 return EndCall(*x);
		}
		else if ((*x).DecNumCalls(num, calluniqueid))
		{
			return EndCall(*x);
		}

	}
	return 0;
}

int TaskManagerInterface::CreateTask(std::vector<std::string> _nums,std::vector<std::string> _operators,std::string _caller,std::string _schema,std::string _outline,std::string _TaskName)
{
	Task newtask;
	newtask.init(_nums, _operators,_schema, _outline, _caller, _TaskName);
	Tasks.push_back(newtask);
	return Tasks.size();		
}

int TaskManagerInterface::CreateTask(Task& newtask)
{
	Tasks.push_back(newtask);
	return Tasks.size();
}

TaskManagerInterface::TaskManagerInterface()
{

}

void TaskManagerInterface::PrintOperators()
{
	for(auto x=Tasks.begin();x!=Tasks.end();++x)
		(*x).PrintOperators();
}

void TaskManagerInterface::PrintCalls()
{
	for(auto x=Tasks.begin();x!=Tasks.end();++x)
		(*x).PrintCalls();
}

void TaskManagerInterface::PrintNumbers()
{
	for(auto x=Tasks.begin();x!=Tasks.end();++x)
		(*x).PrintNumbers();
}

int TaskManagerInterface::Start()
{
	for(auto x = Tasks.begin();x!=Tasks.end();++x)
	{
		StartTask(x);
	}

	return 1;
}

int TaskManagerInterface::Start(int TaskIndex)
{
	if(TaskIndex<=Tasks.size())
	{
		auto x = Tasks.begin();
		std::advance(x,TaskIndex-1);
		StartTask(x);
	}
	else
		return 0;
	
	

	return 1;
}