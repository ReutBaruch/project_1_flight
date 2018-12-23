#include "parser.h"
#include "SetControlCommand.h"
#include "CommandExpression.h"
#include "SetControlCommand.h"

parser::parser(){
    this->bindMap = new PathMap();
    this->valueMap = new FlightValueMap();
    this->connection = new CheckConnection();
    this->stringControl = new StringFlightControls();
    this->symbols = new SymbolTable(this->valueMap, this->bindMap);
    this->commands.insert(pair<string, Command*>("openDataServer", new OpenServerCommand(this->connection,
            this->valueMap)));
    this->commands.insert(pair<string, Command*>("connect", new ConnectCommand(this->connection,
                                                                               this->stringControl)));
    this->commands.insert(pair<string, Command*>("var", new VarCommand(this->symbols)));
    this->commands.insert(pair<string, Command*>("control", new SetControlCommand(this->stringControl,
                                                                                  this->symbols)));
}

void parser::runParser(vector<string> v){
    vector<string>:: iterator vectorIt;
    for (vectorIt = v.begin(); vectorIt != v.end(); vectorIt++) {
        if (this->commands.count(*vectorIt)) {
            Command *com = this->commands.find(*vectorIt)->second;
            vectorIt++;
            com->doCommand(vectorIt);
        }else if(this->symbols->getSymbols().count(*vectorIt)){
            CommandExpression* commmandEX = new CommandExpression(vectorIt,new SetControlCommand(this->stringControl,
                    this->symbols));
            map<string, double> mapSymbol = this->symbols->getSymbols();
            vectorIt += commmandEX->calculate(mapSymbol);
        } else if (*vectorIt == "while"){
            //TODO
        } else if (*vectorIt == "if"){
            //TODO
        } else if (*vectorIt == "print"){
            //TODO
        } else if (*vectorIt == "sleep"){
            //TODO
        } else {
            VarCommand* var = new VarCommand(this->symbols);
            var->doCommand(vectorIt);
        }
       // vectorIt++;
    }
    while (true){

    }

    //cout << "work parser" << endl;
}