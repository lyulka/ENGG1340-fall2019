#include <string>
#include "BigInteger.h"
using namespace std;
class Country{
    public:
        string name;
        BigInteger population;
        BigInteger nationalDebt;
        void showInfo(); //Display the information of the Country
};
