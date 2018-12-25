#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "SymbolTable.h"
#include "CommandExpression.h"
#include "CommandMap.h"
#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


class ConditionParser : public Command {
public:
    list<CommandExpression *> expressionCommandList;
    CommandMap* commandMap;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;


    ConditionParser();

    ConditionParser(CommandMap* commandMap,SymbolTable* symbolMap);

    virtual int doCommand(vector<string>::iterator &script);
    void createCommand(vector<string>::iterator &vectorIt);

};


#endif //PROJECTNUM1_CONDITIONPARSER_H