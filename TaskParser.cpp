#include "TaskParser.h"
#include <iostream>
#include <sstream>

/*
	int TaskParser::CheckStrategy(std::string data)
	get strategy - this would be used by TaskLoader object
	or any another who will create Task
*/
int TaskParser::CheckStrategy(std::string data)
{
	int newstrategy = 0;
	std::string value;
	std::stringstream ss;
	ss << data;
	ss >> value;
	if(value == "strategy")
		ss >> newstrategy;
	else
		return 0;

	return newstrategy;
}
/* 
	int TaskParser::CheckEnd(std::string data)
	Check if task section or all task is over
	return 0 - Not end
	return 1 - End section
		   2 - End Task
*/
int TaskParser::CheckEnd(std::string data)
{
	std::stringstream ss;
	ss << data;
	std::string value;
	ss >> value;
	if(value == "end")
	{
		ss >> value;
		if(value == "start")
		{
			return 2;
		}
		return 1;
	}
	return 0;
}

/*
	int TaskParser::Parse(std::string data)
	main parse loop

	return 1 - Task parse complete
	return 0 - Task parse in process
*/
int TaskParser::Parse(std::string data)
{
	std::cout<<data<<std::endl<<"ParseMode ="<<ParseMode<<std::endl;

	int newstrategy = 0;
	if(ParseMode == 0)
	{
		if(newstrategy = CheckStrategy(data))
			strategy = newstrategy;
	}
	int isEnd = CheckEnd(data);
	std::cout<<"isEnd="<<isEnd<<std::endl;
	if(isEnd == 2)
	{
		return 1;
	}
	if(isEnd == 1)
	{
		ParseMode = 1;
	}
	if(isEnd == 0)
	{
		std::cout<<"SectionParse";
		ParseMode = SectionParse(data,ParseMode);
		std::cout<<"  return "<<ParseMode<<std::endl;
	}
	return 0;
}
/*
	int TaskParser::DecodeSection(std::string data,int Mode)
	try to recognize next data section
*/
int TaskParser::DecodeSection(std::string data,int Mode)
{
	if(data == "phones")
		Mode = 2;
	if(data == "operators")
		Mode = 3;
	if(data == "caller")
		Mode = 4;
	if(data == "schema")
		Mode = 5;
	if(data == "outline")
		Mode = 6;
	if(data == "taskname")
		Mode = 7;	

	return Mode;
}
/*
	int TaskParser::SectionParse(std::string data,int Mode)
	Read data and change values for new task
*/
int TaskParser::SectionParse(std::string data,int Mode)
{
	switch(Mode)
	{
		case(0):
		{
			if(data=="start")
				Mode = 1;
			break;
		}
		case(1):
		{
			Mode = DecodeSection(data,Mode);
			break;
		}
		case(2):
		{
			nums.push_back(data);
			break;
		}
		case(3):
		{
			operators.push_back(data);
			break;
		}
		case(4):
		{
			caller = data;
			std::cout<<"caller="<<caller<<std::endl;
			break;
		}
		case(5):
		{
			schema = data;
			std::cout<<"schema="<<schema<<std::endl;
			break;
		}
		case(6):
		{
			outline = data;
			std::cout<<"outline="<<outline<<std::endl;
			break;
		}
		case(7):
		{
			taskname = data;
			std::cout<<"taskname="<<taskname<<std::endl;
			break;
		}
	}
	return Mode;
}