#include "CreateExpression.h"

CreateExpression::CreateExpression() {

}

// shunting yard
Expression *CreateExpression::convertToExpression(string str) {
    string oprtatorList = "";
    stack<Expression *> expressions;
    stack<string> operators;
    int stringLength = 0;
    int resultLength = 0;
    while (stringLength < str.length()) {
        if (str[stringLength] == '(') {
            operators.push("(");
        } else if (str[stringLength] == ')') {
            string temp;
            while (operators.top() != "(") {
                temp = operators.top();
                oprtatorList += temp;
                operators.pop();
            }
            operators.pop();
        } else if (str[stringLength] != '+' && str[stringLength] != '-' &&
                   str[stringLength] != '*' && str[stringLength] != '/') {

            oprtatorList += str[stringLength];
        } else {
            string operatorPush = "";
            if ((stringLength == 0) && (str[stringLength] == '-')) {
                operatorPush = "^";
            } else {
                char previousChar = str[stringLength - 1];
                char currentChar = str[stringLength];
                if ((currentChar == '-') &&
                    ((previousChar == '*') || (previousChar == '+') ||
                     (previousChar == '/') || (previousChar == '-'))) {
                    operatorPush = "^";
                } else {
                    operatorPush = string(1, str[stringLength]);
                    oprtatorList +=",";

                }

            }
            operators.push(operatorPush);


        }
        stringLength++;
    }
    while (!operators.empty()) {
        oprtatorList += operators.top();
        operators.pop();
    }
    while (resultLength < oprtatorList.length()) {
        Expression *newExpression;
        Expression *rightExpression;
        Expression *leftExpression;
        if (oprtatorList[resultLength] != ' ') {
            if (oprtatorList[resultLength] == '+') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Plus(leftExpression, rightExpression);
            } else if (oprtatorList[resultLength] == '*') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Mul(leftExpression, rightExpression);
            } else if (oprtatorList[resultLength] == '/') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Div(leftExpression, rightExpression);
            } else if (oprtatorList[resultLength] == '-') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                newExpression = new Minus(leftExpression, rightExpression);
                resultLength++;
            } else if (oprtatorList[resultLength] == '^') {
                newExpression = new Neg(expressions.top());
                resultLength++;
            } else if (isdigit(oprtatorList[resultLength])) {
                string num = "";
                while (((oprtatorList[resultLength]) != ',') && (isdigit(oprtatorList[resultLength]))) {
                    string s = string(1, oprtatorList[resultLength]);
                    num = num + s;
                    resultLength++;
                }
                double d = atof(num.c_str());
                newExpression = new Num(d);
            } else if (oprtatorList[resultLength] != ' ') {
                string tempVar = "";
                while ((oprtatorList[resultLength] != ',') || (isdigit(oprtatorList[resultLength])) ||
                       (isalpha(oprtatorList[resultLength]))) {
                    string s = string(1, oprtatorList[resultLength]);
                    tempVar = tempVar + s;
                    resultLength++;
                }

                newExpression = new Var(tempVar);
            }
            expressions.push(newExpression);
            Expression *e = expressions.top();
            if(oprtatorList[resultLength] == ',') {
                resultLength++;
            }
        } else {
            resultLength++;
        }
    }
    return expressions.top();

}