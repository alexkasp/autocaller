#include "SimpleTaskManager.h"

int SimpleTaskManager::EndCall(Task& x)
{
	
	std::string newnumber = x.GetNextNumber();
	if(newnumber.size()>0)
		manager.call(x.GetCaller(),newnumber,x.GetOutLine(),x.GetSchema());
	
}

int SimpleTaskManager::StartTask(std::vector<Task>::iterator& x)
{
	int freeoperators = x->GetFreeOperators();
	int startedcalls = 0;
	for(int i=0;i<freeoperators;++i)
	{
		std::string number = (*x).GetNextNumber();
		if(number.size()>0)
		{
			manager.call((*x).GetCaller(),number,(*x).GetOutLine(),(*x).GetSchema());
			sleep(1);
			startedcalls++;
		}
	}
	return startedcalls;
}

