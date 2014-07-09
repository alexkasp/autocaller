#ifndef __TASK_PARSER
#define __TASK_PARSER
#include <vector>
#include <string>


/*
	class TaskParse
	implement parse of input data
	return prepared conteiners for create task
*/
class TaskParser
{
		
		TaskParser();
		std::vector<std::string> &nums;
		std::vector<std::string> &operators;
		std::string &caller;
		std::string &schema;
		std::string &outline;
		std::string &taskname;
		int strategy;
	/*
	ParseMode - mode of parsing
	0 - pasre undefined
	1 - wait instruction
	2 - add nums
	3 - add operators
	4 - add caller
	5 - add schema
	6 - add outline
	7 - add taskname
	*/

	int ParseMode;
	int CheckStrategy(std::string data);
	int CheckEnd(std::string data);
	int DecodeSection(std::string data,int Mode);
	int SectionParse(std::string data,int Mode);
	public:
		int GetStrategyCode(){return strategy;}
		TaskParser(std::vector<std::string> &_nums,std::vector<std::string> &_operators,std::string &_caller,std::string &_schema,std::string &_outline, std::string &_taskname):
			nums(_nums),operators(_operators),caller(_caller),schema(_schema),outline(_outline),taskname(_taskname),ParseMode(0),strategy(0)
		{}

		int Parse(std::string data);
};
#endif