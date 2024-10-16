// ======================================================================
// Name        : assign_7.cpp
// Author      : Omkar Sonawane
// Description : This program implements maps to store key-value pairs
// ======================================================================

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    typedef map<string, int> mapType;
    mapType populationMap;

    // Inserting population data
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karnataka", 6678993)); // Corrected spelling
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    mapType::iterator iter;

    cout << "======== Population of states in India ==========\n";
    cout << "\nSize of populationMap: " << populationMap.size() << "\n";

    string state_name;
    cout << "\nEnter name of the state: ";
    cin >> state_name;

    iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        cout << state_name << "'s population is " << iter->second << "\n";
    } else {
        cout << "Key is not in populationMap\n";
    }

    populationMap.clear();
    return 0;
}
