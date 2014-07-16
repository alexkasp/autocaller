#include <iostream>
#include "./EventReader/EventReader.h"
#include "./Logger/LogManager.h"
#include "./Logger/Logger.h"
#include "CallViewer.h"
#include "TaskLoader.h"
#include "ReserveOperatorTaskManager.h"
#include "ReserveSchemaTaskManager.h"
#include <iostream>



using namespace std;

int main()
{
	LogManager lm;
	BoostLoggerInFile lg("autocaller_%N.log");
	lm.AddLogger(&lg);

	CallViewer cv;
	TaskLoader tl;
	
	cv.PrintOperators();
	SimpleTaskManager stm;
	ReserveOperatorTaskManager rotm;
	ReserveSchemaTaskManager rstm;
	
	tl.AddManager(&rstm);
	cv.AddManager(&rstm);

	tl.AddManager(&stm);
	cv.AddManager(&stm);

	tl.AddManager(&rotm);
	cv.AddManager(&rotm);

	tl.StartListen();
	EventReader reader("127.0.0.1",5038);
	reader.SetExecuter(&cv);
	stm.Start();
	reader.start();

 
	return 0;
}