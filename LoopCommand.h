#ifndef PROJECT1_LOOPCOMMAND_H
#define PROJECT1_LOOPCOMMAND_H

#include "conditionParser.h"

class LoopCommand: public conditionParser {

public:
    LoopCommand(vector<string>::iterator &vectorIt);
    virtual int doCommand(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_LOOPCOMMAND_H
