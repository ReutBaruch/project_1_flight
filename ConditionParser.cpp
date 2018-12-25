#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"

ConditionParser::ConditionParser() {
}

ConditionParser::ConditionParser(CommandMap* commandMap,
                                 SymbolTable *symbolMap) {
    this->symbolTable = symbolMap;
    this->commandMap = commandMap;

}

int ConditionParser::doCommand(vector<string>::iterator &script) {
    string ifOrWhile=(*script);
    string condition = "";
    Command *newCommand;
    script++;
    while ((*script) != "{") {
        condition += (*script);
        script++;
    }
    this->boolExpression = new BoolExpression(condition);
    script++;
    this->createCommand(script);
    if (ifOrWhile == "if") {
        newCommand = new IfCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    } else if (ifOrWhile == "while") {
        newCommand = new LoopCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    }
    newCommand->doCommand(script);
    return 0;

}

void ConditionParser::createCommand(vector<string>::iterator &vectorIt) {
    Command *newCommand;
    Expression *newExpression;
    CommandExpression *commandExp;

    while ((*vectorIt) != "}") {
        map<string, double> symbolsMap = this->symbolTable->getSymbols();
        if (this->symbolTable->getSymbols().count(*vectorIt)) {
            Command *newCommand = this->commandMap->getCommand(
                    "control");
            commandExp = new CommandExpression(vectorIt, newCommand);
            this->expressionCommandList.push_back(commandExp);
        } else if (this->commandMap->isKeyInMap(*vectorIt)) {
            commandExp = new CommandExpression(vectorIt,
                    this->commandMap->getCommand(*vectorIt));
            this->expressionCommandList.push_back(commandExp);
        }
        while ((*vectorIt) != ";"){
            vectorIt++;
        }
        vectorIt++;
    }
}
