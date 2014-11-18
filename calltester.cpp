
#include <unistd.h>
#include "astmanager.h"

int main()
{


    AsteriskManager manager;
    while(1)
    {
	manager.call("063816103","89263137506","000950896");
	sleep(60);
    }
    return 1;
}