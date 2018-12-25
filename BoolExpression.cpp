#include "BoolExpression.h"

void BoolExpression::createBoolExpression(string conditionToCheck) {

    CreateExpression* createExpression = new CreateExpression();

    string expression = "";
    this->action = "";
    int strLen = 0;

    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '!') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '>')) {
        expression += conditionToCheck[strLen];
        strLen++;
    }

    this->leftArgument = createExpression->convertToExpression(expression);
    while ((conditionToCheck[strLen] == '<') || (conditionToCheck[strLen] == '>') ||
           (conditionToCheck[strLen] == '=') || (conditionToCheck[strLen] == '!')) {
        action += conditionToCheck[strLen];
        strLen++;
    }
    expression = "";

    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '>') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '!') &&
           (strLen < conditionToCheck.length())) {
        expression += conditionToCheck[strLen];
        strLen++;
    }
    this->rightArgument = createExpression->convertToExpression(expression);
    delete (createExpression);
}

bool BoolExpression::calculateBool(map<string, double> symbolMap) {
    if (this->action == "<") {
        return ((leftArgument->calculate(symbolMap)) <
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">") {
        return ((leftArgument->calculate(symbolMap)) >
                rightArgument->calculate(symbolMap));
    } else if (this->action == "<=") {
        return ((leftArgument->calculate(symbolMap)) <=
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">=") {
        return ((leftArgument->calculate(symbolMap)) >=
                rightArgument->calculate(symbolMap));
    } else if (this->action == "==") {
        return ((leftArgument->calculate(symbolMap)) ==
                rightArgument->calculate(symbolMap));
    } else if (this->action == "!=") {
        return ((leftArgument->calculate(symbolMap)) !=
                rightArgument->calculate(symbolMap));
    } else {
        throw "Invald argument";
    }
}

BoolExpression::~BoolExpression(){
    delete this;
}