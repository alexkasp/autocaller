#include "LogManagerInterface.h"

int LogManagerInterface::AddLogger(LoggerInterface* logger)
{
	Loggers.push_back(logger);

	return Loggers.size();
}