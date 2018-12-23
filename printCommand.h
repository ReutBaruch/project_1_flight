
#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include <map>
#include <iostream>

class printCommand: public Command{
    SymbolTable* symbolTable1;
public:
    printCommand(SymbolTable* s);
    virtual int doCommand(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_PRINTCOMMAND_H
