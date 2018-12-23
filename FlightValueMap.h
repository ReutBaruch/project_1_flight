#ifndef PROJECT1_FLIGHTVALUEMAP_H
#define PROJECT1_FLIGHTVALUEMAP_H

#include <map>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class FlightValueMap {
    map<string,double> mapOfFlightValue;
public:
    FlightValueMap();
    void initalize();
    void updateMap(string values);
    map<string,double> getFlightVauleMap();
    //double getValue(string key);
    //bool isKeyInMap(string key) const;

};


#endif //PROJECT1_FLIGHTVALUEMAP_H
