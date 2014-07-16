#ifndef __LOG_MANAGER_H
#define __LOG_MANAGER_H
#include "LogManagerInterface.h"

class LogManager: public LogManagerInterface
{
	public:	
		void PutLog(std::string Message);
};


#endif