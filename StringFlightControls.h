#ifndef PROJECT1_STRINGFLIGHTCONTROLS_H
#define PROJECT1_STRINGFLIGHTCONTROLS_H

#include <string>

using namespace std;

class StringFlightControls {
    string controlCommand;
public:
    StringFlightControls(){
        controlCommand = "";
    }
    void setControl(string s){
        this->controlCommand = s;
    }

    string getControl(){
        return this->controlCommand;
    }


};


#endif //PROJECT1_STRINGFLIGHTCONTROLS_H
