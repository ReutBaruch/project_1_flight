#include "CommandExpression.h"

double CommandExpression::calculate(map<string, double> &assignment) {
    int countSteps=0;
    string expression;
    int resultExpression;
    vector<string> newVector;
    Expression *newExpression;
    vector<string>::iterator tempItr;
    tempItr=this->vectorIt;
    CreateExpression *createExpression = new CreateExpression();
    if (((*this->vectorIt) == "openDateServer") || ((*this->vectorIt) == "sleep")) {
        this->vectorIt++;
        countSteps++;
        while ((*this->vectorIt) != ";") {
            expression = (*vectorIt);
            newExpression = createExpression->convertToExpression(expression);
            resultExpression = (int) newExpression->calculate(assignment);
            newVector.push_back(to_string(resultExpression));
            vectorIt++;
            countSteps++;
        }
        vector<string>::iterator itr;
        itr=newVector.begin();
        this->command->doCommand(itr);
    } else if((*vectorIt) == "connect"){
        vectorIt++;
        countSteps++;
        string ip = (*vectorIt);
        newVector.push_back(ip);
        vectorIt++;
        countSteps++;
        expression = (*vectorIt);
        newExpression = createExpression->convertToExpression(expression);
        resultExpression = (int) newExpression->calculate(assignment);
        newVector.push_back(to_string(resultExpression));
        vector<string>::iterator itr;
        itr=newVector.begin();
        this->command->doCommand(itr);

    } else if((*vectorIt) == "print"){
        vectorIt++;
        countSteps++;
        if((*vectorIt)[0]=='\"'){

            this->command->doCommand(vectorIt);
        } else {
            while ((*this->vectorIt) != ";") {
                expression = (*vectorIt);
                newExpression = createExpression->convertToExpression(expression);
                resultExpression = (int) newExpression->calculate(assignment);
                newVector.push_back(to_string(resultExpression));
                vectorIt++;
                countSteps++;
            }
            vector<string>::iterator itr;
            itr=newVector.begin();
            this->command->doCommand(itr);
        }

    } else if ((*vectorIt)=="var"){
        vectorIt++;
        countSteps++;
        countSteps+=this->command->doCommand(vectorIt);
    } else {
        newVector.push_back(*this->vectorIt);
        string expressin = "";

        this->vectorIt += 2;
        countSteps += 2;
        while ((*this->vectorIt) != ";") {
            expressin += (*this->vectorIt);
            this->vectorIt++;
            countSteps++;
        }
        newExpression = createExpression->convertToExpression(expressin);
        double result = newExpression->calculate(assignment);
        //newVector.push_back("=");
        newVector.push_back(to_string(result));
        vector<string>::iterator newVectorIt;
        newVectorIt = newVector.begin();
        this->command->doCommand(newVectorIt);
    }
    this->vectorIt=tempItr;
    return countSteps;
}

double CommandExpression::calculate() {
    map<string, double> temp;
    calculate(temp);
}
