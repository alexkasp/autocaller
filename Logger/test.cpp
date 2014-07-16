#include "LogManager.h"
#include "Logger.h"

int main()
{
	LogManager lm;
	BoostLoggerInFile lg("autocaller_%N.log");
	lm.AddLogger(&lg);
	lm.PutLog("test log");

}