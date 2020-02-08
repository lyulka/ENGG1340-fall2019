#include <iostream>
#include "BigInteger.h"
#include "Country.h"
using namespace std;
int main(){
     Country c1, c2; //  this world sucks man
     BigInteger world_population;
     
     c1.name="China";
     c1.population.setNumber("1344130000");
     c1.nationalDebt.setNumber("2356079942424");
     c1.showInfo();

     c2.name="U.S.";
     c2.population.setNumber("313914040");
     c2.nationalDebt.setNumber("16584599414424");
     c2.showInfo();
     
     //cout << "Just a modification" << endl;

     return 0;
}
   
