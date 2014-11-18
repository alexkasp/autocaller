
#include <unistd.h>
#include "astmanager.h"

int main()
{

    AsteriskManager manager;
    manager.call("063816103","89263137506");
    sleep(2000);
    return 1;
}