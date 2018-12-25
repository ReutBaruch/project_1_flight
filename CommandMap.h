#include "Command.h"
#include "map"

#ifndef PROJECTNUM1_COMMANDMAP_H
#define PROJECTNUM1_COMMANDMAP_H


class CommandMap {
    map<string, Command *> commandMAp;

public:
    CommandMap(){}
    void addCommand(string key,Command* command);
    Command* getCommand(string key);
    bool isInMap(string key);
    ~CommandMap(){
        delete this;
    }
};


#endif //PROJECTNUM1_COMMANDMAP_H
