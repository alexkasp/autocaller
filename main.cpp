#include <iostream>
#include "./EventReader/EventReader.h"
#include "CallViewer.h"
#include "TaskLoader.h"
#include "ReserveOperatorTaskManager.h"
#include "ReserveSchemaTaskManager.h"
#include <iostream>
#include "Logger.h"


using namespace std;

int main()
{
	LoggerCall lgc;
	//lgc.LogMsg("Test");


	CallViewer cv;
	TaskLoader tl;
	
	cv.PrintOperators();
	SimpleTaskManager stm;
	ReserveOperatorTaskManager rotm;
	ReserveSchemaTaskManager rstm;
	//stm.CreateTask({"84996474040","84996474040","84996474040"},{"063816101","063816102","063816103"},"000963224","0638161004996478049","063816101","Test Task");
	
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