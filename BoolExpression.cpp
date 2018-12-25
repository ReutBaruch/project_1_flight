#include "BoolExpression.h"

BoolExpression::BoolExpression(string stringCondition) {
    this->createBoolExpression(stringCondition);
}

void BoolExpression::createBoolExpression(string boolCondition) {
    CreateExpression *createExpression = new CreateExpression();
    this->action = "";
    string expression = "";
    int strLen = 0;
    while ((boolCondition[strLen] != '<') && (boolCondition[strLen] != '>') &&
           (boolCondition[strLen] != '=') && (boolCondition[strLen] != '!')) {
        expression += boolCondition[strLen];
        strLen++;
    }
    this->leftArgument = createExpression->convertToExpression(expression);
    while ((boolCondition[strLen] == '<') || (boolCondition[strLen] == '>') ||
           (boolCondition[strLen] == '=') || (boolCondition[strLen] == '!')) {
        action += boolCondition[strLen];
        strLen++;
    }
    expression = "";
    while ((boolCondition[strLen] != '<') && (boolCondition[strLen] != '>') &&
           (boolCondition[strLen] != '=') && (boolCondition[strLen] != '!') &&
           (strLen < boolCondition.length())) {
        expression += boolCondition[strLen];
        strLen++;
    }
    this->rightArgument = createExpression->convertToExpression(expression);
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
        throw "ERROR - invald argument";
    }
}