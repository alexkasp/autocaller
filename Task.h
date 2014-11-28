#ifndef __TASK_12345
#define __TASK_12345
#include <vector>
#include <string>
#include <map>


class Task
{
	std::multimap<std::string,int> nums;
	std::string schema;
	std::string outline;
	std::string caller;

	std::map<std::string,int> operators;
	std::multimap<std::string,std::string> calls;

	
	int currentnum;
	int currentoperator;
	int numbercount;

	int started;
	int wasinited;

	std::string TaskName;
	public:
		void PrintOperators();
		void PrintCalls();
		void PrintNumbers();
		int GetFreeOperators();
		
		int IncOperatorCalls(std::string,std::string);
		int DecOperatorCalls(std::string,std::string);
		int DecNumsCall(std::string, std::string);
		Task():started(0),wasinited(0)
		{};
		const std::string GetNextNumber();
		const std::string GetFreeOperator();
		const int IsComplete() const;
		const std::string GetSchema(){return schema;}
		const std::string GetCaller(){return caller;}
		const std::string GetOutLine(){return outline;}
		int init(std::vector<std::string> _nums,std::vector<std::string> _operators,std::string _schema,std::string _outline,std::string _caller,std::string _TaskName);

};
#endif