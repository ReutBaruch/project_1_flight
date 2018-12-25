#include "Expression.h"
#include <stack>
#include <string>
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Var.h"
#include "Neg.h"
#ifndef PROJECT1_CREATEEXPRESSION_H
#define PROJECT1_CREATEEXPRESSION_H

using namespace std;

class CreateExpression {
public:
    CreateExpression();
    Expression* convertToExpression(string str);

};


#endif //PROJECT1_CREATEEXPRESSION_H