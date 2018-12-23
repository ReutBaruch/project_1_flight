
#include "CommandExpression.h"


double CommandExpression::calculate(map<string, double> &assignment) {
    string temp = (*vectorIt);
    int count = 0;
    this->vectorIt += 2;
    count +=2;
    string exp = "";
    while ((*vectorIt) != ";"){
        exp += (*vectorIt);
        this->vectorIt++;
        count ++;
    }
    createExpression* expression = new createExpression();
    Expression* newExp = expression->convertToExpression(exp);
    double result = newExp->calculate(assignment);
    vector<string> resultVector;
    resultVector.push_back(temp);
    //resultVector.push_back("=");
    resultVector.push_back(to_string(result));
    vector<string>::iterator itForDoCommand;
    itForDoCommand = resultVector.begin();
    this->command->doCommand(itForDoCommand);
    return count;
}