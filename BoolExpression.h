#include "Expression.h"
#include "CreateExpression.h"
#include <map>
#ifndef PROJECT1_BOOLEXPRESSION_H
#define PROJECT1_BOOLEXPRESSION_H


class BoolExpression  {
    Expression* leftArgument;
    Expression* rightArgument;
    string action;
public:

    BoolExpression(string stringCondition) {
        this->createBoolExpression(stringCondition);
    }

    void createBoolExpression(string conditionToCheck);
    bool calculateBool(map <string,double> symbolMap);

    ~BoolExpression();

};

#endif //PROJECT1_BOOLEXPRESSION_H