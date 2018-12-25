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

    BoolExpression(string stringCondition);
    void createBoolExpression(string boolCondition);
    bool calculateBool(map <string,double> symbolMap);

};


#endif //PROJECT1_BOOLEXPRESSION_H