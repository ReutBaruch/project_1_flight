
#include "createExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"

createExpression::createExpression() {

}

// shunting yard
Expression *createExpression::convertToExpression(string str) {
    string oprtatorList = "";
    stack<Expression *> expressions;
    stack<string> operators;
    int stringLength = 0;
    int resultLenght = 0;
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
            string temp = string(1,str[stringLength]);
            operators.push(temp);
        }
        stringLength++;
    }
    while (!operators.empty()) {
        oprtatorList += operators.top();
        operators.pop();
    }
    while (resultLenght < oprtatorList.length()) {
        Expression *newExpression;
        Expression *rightExpression;
        Expression *leftExpression;
        if (oprtatorList[resultLenght] == '+') {
            rightExpression = expressions.top();
            expressions.pop();
            leftExpression = expressions.top();
            expressions.pop();
            newExpression = new Plus(leftExpression, rightExpression);
        } else if (oprtatorList[resultLenght] == '*') {
            rightExpression = expressions.top();
            expressions.pop();
            leftExpression = expressions.top();
            expressions.pop();
            newExpression = new Mul(leftExpression, rightExpression);
        } else if (oprtatorList[resultLenght] == '/') {
            rightExpression = expressions.top();
            expressions.pop();
            leftExpression = expressions.top();
            expressions.pop();
            newExpression = new Div(leftExpression, rightExpression);
        } else if (oprtatorList[resultLenght] == '-') {
            rightExpression = expressions.top();
            expressions.pop();
            leftExpression = expressions.top();
            expressions.pop();
            newExpression = new Minus(leftExpression, rightExpression);
        } else{
            string s=string(1,oprtatorList[resultLenght]);
            double d = atof(s.c_str());
            newExpression=new Num(d);
        }
        expressions.push(newExpression);
        resultLenght++;
    }
    return expressions.top();
}