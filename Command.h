#include <string>
#include <vector>

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <map>
#include <mutex>

using namespace std;

class Command {
public:
    map<string, double> symbolTable;
    //std::map<string, Command*> commands;
public:
    Command(){}
    virtual int doCommand(vector<string>::iterator &vectorIt) = 0;

};


#endif //PROJECT1_COMMAND_H
