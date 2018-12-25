#ifndef PROJECT1_COMMANDEXPRESSION_H
#define PROJECT1_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "CreateExpression.h"

class CommandExpression: public Expression {
    Command* command;
    vector<string>::iterator vectorIt;

public:
    CommandExpression(vector<string>::iterator &it, Command* command1){
        this->command = command1;
        this->vectorIt = it;
    }

    double calculate();
    double calculate(map<string, double> &assignment);

    ~CommandExpression(){
        delete this;
    }
};


#endif //PROJECT1_COMMANDEXPRESSION_H
