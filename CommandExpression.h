#ifndef PROJECT1_COMMANDEXPRESSION_H
#define PROJECT1_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "createExpression.h"

class CommandExpression: public Expression {
    Command* command;
    vector<string>::iterator vectorIt;

public:
    CommandExpression(vector<string>::iterator &it, Command* command1){
        this->command = command1;
        this->vectorIt = it;
    }

    double calculate(map<string, double> &assignment);

    double calculate() {}
};


#endif //PROJECT1_COMMANDEXPRESSION_H