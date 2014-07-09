#include "ReserveOperatorTaskManager.h"


int ReserveOperatorTaskManager::EndCall(Task& x)
{
		 
	std::string freeoperator = x.GetFreeOperator();
	if(freeoperator.size()>0)
	{
		std::string newnumber = x.GetNextNumber();
		if(newnumber.size()>0)
			manager.call(freeoperator,newnumber);
		return 1;
	}
	return 0;
}

int ReserveOperatorTaskManager::StartTask(std::vector<Task>::iterator& x)
{
	int freeoperators = x->GetFreeOperators();
	int startedcalls = 0;
	for(int i=0;i<freeoperators;++i)
	{
		std::string number = x->GetNextNumber();
		std::string freeoperator = x->GetFreeOperator();
		if(number.size()>0)
		{
			manager.call(freeoperator,number);
			startedcalls++;
		}
	}
	return startedcalls;
}