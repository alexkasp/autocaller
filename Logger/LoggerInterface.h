#ifndef __LOGGER_INTERFACE
#define __LOGGER_INTERFACE
#include <ostream>
#include <string>
#include <string>

class LoggerInterface
{
public:
	virtual void LogMsg(std::string message) =0;

};
#endif