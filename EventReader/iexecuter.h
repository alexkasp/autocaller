#include "datatypes.h"

#ifndef __EXECUTER_INTERFACE
#define __EXECUTER_INTERFACE
class ExecuterInterface
{	
	public:
		virtual int Execute(ParamMap& data) = 0;
};
#endif