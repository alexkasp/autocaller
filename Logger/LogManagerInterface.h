#ifndef __LOG_MANAGER_INTERFACE
#define __LOG_MANAGER_INTERFACE
#include "LoggerInterface.h"
#include <string>
#include <vector>

class LogManagerInterface
{
	protected:
		std::vector<LoggerInterface*> Loggers; 
	public:
		int AddLogger(LoggerInterface*);
		virtual void PutLog(std::string Message) = 0;
};
#endif