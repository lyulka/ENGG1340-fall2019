#include <iostream>
#include "Country.h"
using namespace std;

void Country::showInfo(){
    cout << name << endl;
    cout << " Population: " << population << endl;
    cout << " National debt (in USD): " << nationalDebt << endl;
}
