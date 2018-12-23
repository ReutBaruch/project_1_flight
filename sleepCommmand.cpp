#include <unistd.h>
#include "sleepCommmand.h"


int sleepCommmand::doCommand(vector<string>::iterator &vectorIt){
    int num = atoi((*vectorIt).c_str());
    sleep(num);
    vectorIt += 2;
}
