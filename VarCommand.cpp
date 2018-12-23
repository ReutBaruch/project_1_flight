#include "VarCommand.h"


int VarCommand::doCommand(vector<string>::iterator &vectorIt){
    //vectorIt++;
    string temp = *vectorIt;
    vectorIt +=2;
    if (*vectorIt == "bind"){
        vectorIt++;
        string path = (*vectorIt).substr(1, (*vectorIt).length() -2);
        this->symbols->addPairSymbol(temp, path);

    } else {
        if(this->symbols->getSymbols().count(*vectorIt)){
            this->symbols->setSymbol(temp, this->symbols->getSymbols().find(*vectorIt)->second);
        }
    }
    //double num = atof((*vectorIt).c_str());
    //this->symbols->setSymbol(temp, num);
    vectorIt++;
}
