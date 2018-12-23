#ifndef PROJECT1_IFCOMMAND_H
#define PROJECT1_IFCOMMAND_H

#include "conditionParser.h"

class ifCommand: public conditionParser {

public:
    ifCommand(vector<string>::iterator &vectorIt);
    virtual int doCommand(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_IFCOMMAND_H
