#include <iostream>
#include "EventReader.h"
#include "CRMUrlBuilder.h"
#include "Parser.h"

using namespace std;

int main()
{
	EventReader reader("127.0.0.1",5038);
	reader.SetExecuter(new CRMUrlBuilder(Parser()));
	reader.start();

 
	return 0;
}