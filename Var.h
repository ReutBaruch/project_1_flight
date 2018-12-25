#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H

#include <string>
#include "Expression.h"
class Var: public Expression {
    string var;
public:
    Var(string v);
    virtual double calculate(map<string, double> &assignment);

    double calculate();

};

#endif //PROJECT1_VAR_H
