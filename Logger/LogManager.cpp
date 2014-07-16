#include "LogManager.h"

void LogManager::PutLog(std::string Message)
{
	
	for(auto x = Loggers.begin();x!=Loggers.end();++x)
	{
		(*x)->LogMsg(Message);
	}
}