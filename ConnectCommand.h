#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "string"
#include "CheckConnection.h"
#include "StringFlightControls.h"

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H

using namespace std;

class ConnectCommand : public Command {
    CheckConnection* isConnected;
    StringFlightControls* flightString;

public:
    ConnectCommand(CheckConnection* check, StringFlightControls* flightStr);
    virtual int doCommand(vector<string>::iterator &vectorIt);
};

#endif //PROJECT1_CONNECTCOMMAND_H
