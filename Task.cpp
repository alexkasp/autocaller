#include "Task.h"
#include <iostream>

const int Task::IsComplete() const
{
	return nums.size()<=currentnum;
}


int Task::IncOperatorCalls(std::string worker,std::string call)
{
	auto x = operators.find(worker);
	if(x != operators.end())
	{
		(*x).second++;
		calls.insert(std::pair<std::string,std::string>(call,worker));
		auto num = nums.find(worker);
		if(num!=nums.end())
		{
			(*num).second++;
		}
		return 1;
	}
	return 0;
}
int Task::DecOperatorCalls(std::string worker,std::string call)
{
		auto callentry = calls.find(call);
		if(callentry!=calls.end())
		{
			calls.erase(callentry);
			auto x = operators.find(worker);
			if (x != operators.end())
			{
				(*x).second--;
			}
			return 1;
		}
	
		return callentry != calls.end();
}


int Task::GetFreeOperators()
{
	PrintOperators();

	int count = 0;
	for(auto x = operators.begin();x!=operators.end();++x)
	{
		if(x->second==0)
			count++;
	}
	return count;
}
const std::string Task::GetNextNumber()
{
	if(IsComplete())
		return "";

	int size = nums.size();
	auto x = nums.begin();
	do
	{
		std::advance(x,currentnum);
		++currentnum;
		
		if((currentnum>=size)&&(x->second>0))
			return "";

	}while(x->second>0);

	
	x->second=1;
	return x->first;
}

int Task::init(std::vector<std::string> _nums,std::vector<std::string> _operators,std::string _schema,std::string _outline,std::string _caller,std::string _TaskName)
{
	schema = _schema;outline = _outline; caller = _caller; TaskName = _TaskName;

	for(auto x = _operators.begin();x!=_operators.end();++x)
		operators.insert(std::pair<std::string,int>((*x),0));

	for(auto x = _nums.begin();x!=_nums.end();++x)
		nums.insert(std::pair<std::string,int>((*x),0));

	currentnum = 0;
	currentoperator = 0;
}

void Task::PrintOperators()
{
	auto x = operators.begin();

	for(;x!=operators.end();++x)
	{
		std::cout<<(*x).first<<" calls:"<<(*x).second<<std::endl;
	}
}

void Task::PrintCalls()
{
	auto x = calls.begin();
	for(;x!=calls.end();++x)
	{
		std::cout<<(*x).first<<" call:"<<(*x).second<<std::endl;
	}
}

void Task::PrintNumbers()
{
	auto x = nums.begin();
	for(;x!=nums.end();++x)
	{
		std::cout<<(*x).first<<" call:"<<(*x).second<<std::endl;
	}
	
}

const std::string Task::GetFreeOperator()
{
	auto x = operators.begin();
	int size = operators.size();

	int startposition = currentoperator;
	do
	{
		std::advance(x,currentoperator);
		currentoperator = (currentoperator+1)%size;
		
		if((startposition==currentoperator)&&(x->second>0))
			return "";

	}while(x->second>0);
	
	return x->first;
}