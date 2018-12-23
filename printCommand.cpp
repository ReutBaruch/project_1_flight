#include "printCommand.h"

printCommand::printCommand(SymbolTable* s){
    this->symbolTable1 = s;
}

int printCommand::doCommand(vector<string>::iterator &vectorIt){
    if (this->symbolTable1->getSymbols().count(*vectorIt)){
        double result = this->symbolTable1->getValue(*vectorIt);
        cout << result << endl;
    } else {
        string result = "";
        while ((*vectorIt) != ";"){
            result += (*vectorIt);
        }
        result.substr(1, (result.length() - 2));
        cout << result << endl;
    }

    return 0;
}