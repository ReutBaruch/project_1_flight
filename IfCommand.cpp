#include "IfCommand.h"


int IfCommand::doCommand(vector<string>::iterator &script) {
    if (this->boolExpression->calculateBool(this->symbolTable->getSymbols())) {
        list<CommandExpression *>::iterator itr;
        for (itr = this->commandExpressions.begin();
             itr != this->commandExpressions.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*itr)->calculate(symbolMap);
        }
    }
}