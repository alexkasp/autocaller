#include "ReserveSchemaTaskManager.h"

int ReserveSchemaTaskManager::EndCall(Task& x)
{
	std::string freeoperator = x.GetFreeOperator();
	if(freeoperator.size()>0)
	{
		std::string newnumber = x.GetNextNumber();
		std::string schema = x.GetSchema();
		if(newnumber.size()>0)
			manager.call(freeoperator,newnumber,schema);
		return 1;
	}
	return 0;
}

int ReserveSchemaTaskManager::StartTask(std::vector<Task>::iterator& x)
{
	int freeoperators = x->GetFreeOperators();
	int startedcalls = 0;
	for(int i=0;i<freeoperators;++i)
	{
		std::string number = x->GetNextNumber();
		std::string freeoperator = x->GetFreeOperator();
		std::string schema = x->GetSchema();

		if(number.size()>0)
		{
			manager.call(freeoperator,number,schema);
			startedcalls++;
		}
	}
	return startedcalls;
}