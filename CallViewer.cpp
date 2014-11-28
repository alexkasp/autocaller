#include "CallViewer.h"

#include <iostream>

int CallViewer::AnswerCallHandler(const ParamMap& data,std::string eventname)
{
	std::cout << "Recieve data (answer):" << data.find("src")->second << "  callid:" << data.find("callid")->second << std::endl;
	for (auto x = managers.begin(); x != managers.end(); x++)
	{
		//if ((eventname == "answercall") && ((*x)->GetStrategyCode() == 2))
		//	continue;
		//if ((eventname == "initcall") && ((*x)->GetStrategyCode() == 1))
		//	continue;
		(*x)->BeginCallHandle(data.find("src")->second, data.find("callid")->second);
		(*x)->BeginCallHandle(data.find("dst")->second, data.find("callid")->second);
	}
	return 1;
}
int CallViewer::FinishCallHandler(const ParamMap& data)
{
	std::string calluniqueid = data.find("Uniqueid:")->second;
	std::cout << "Recieve data (finisg):" << data.find("src")->second << "  callid:" << calluniqueid << std::endl;
	for (auto x = managers.begin(); x != managers.end(); x++)
	{
		(*x)->EndCallHandle(data.find("src")->second, calluniqueid);
		std::cout << "src=" << data.find("src")->second << std::endl;
		(*x)->EndCallHandle(data.find("dst")->second, calluniqueid);
		std::cout << "dst=" << data.find("dst")->second << std::endl;
	}
	return 1;
}

int CallViewer::HangupCallHandler(const ParamMap& data)
{
	std::string calluniqueid = data.find("Uniqueid:")->second;
	std::cout << "Recieve data (finisg):" << data.find("CallerIDNum")->second << "  callid:" << calluniqueid << std::endl;
	for (auto x = managers.begin(); x != managers.end(); x++)
	{
		(*x)->EndCallHandle(data.find("CallerIDNum")->second, calluniqueid);
		std::cout << "src=" << data.find("CallerIDNum")->second << std::endl;
		(*x)->EndCallHandle(data.find("ConnectedLineNum")->second, calluniqueid);
		std::cout << "dst=" << data.find("ConnectedLineNum")->second << std::endl;
	}
	return 1;
}

int CallViewer::Execute(ParamMap& data)
{
	PrintNumbers();

	if (data.find("Event:")->second == "Hangup")
	{
		HangupCallHandler(data);
	}
	if(data.find("Event:")->second == "UserEvent")
	{
		if(data.find("UserEvent:")->second=="initcall")
		{	
			AnswerCallHandler(data,"initcall");
		}
		if (data.find("UserEvent:")->second == "answercall")
		{
			AnswerCallHandler(data,"answercall");
		}
		if(data.find("UserEvent:")->second=="finishcall")
		{
			FinishCallHandler(data);
		}
		PrintOperators();
		PrintCalls();
		PrintNumbers();
	}
	return 1;
}

CallViewer::CallViewer()
{
	/*operators.insert(std::pair<std::string,int>("063816101",0));
	operators.insert(std::pair<std::string,int>("063816102",0));
	operators.insert(std::pair<std::string,int>("063816103",0));
	*/
	//sart test call
	//manager.call("063816101","84996474807");
	PrintOperators();
		PrintCalls();
		PrintNumbers();
}
CallViewer::~CallViewer()
{

}
void CallViewer::PrintOperators()
{
	for(auto x = managers.begin();x!=managers.end();x++)
	{
		(*x)->PrintOperators();
	
	}
}

void CallViewer::PrintCalls()
{
	for(auto x = managers.begin();x!=managers.end();x++)
	{
		(*x)->PrintCalls();
	
	}
}

void CallViewer::PrintNumbers()
{
	for(auto x = managers.begin();x!=managers.end();x++)
	{
		(*x)->PrintNumbers();
	
	}
	
}