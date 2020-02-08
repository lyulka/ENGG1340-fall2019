#include <iostream>
#include <math.h>
using namespace std;

class MeanSd {
    public:
        double inputs[5];

        void getInput() {
            for (int i = 0; i < 5; i++) {
                cin >> inputs[i];
            }
        }

        double getMean() {
            double temp;

            for (int i = 0; i < 5; i++) {
                temp += inputs[i];
            }

            return temp / 5;
        }

        double getSd() {
            double mean =  getMean(), res = 0;

            for (int i = 0; i < 5; i++) {
                res += (inputs[i] - mean) * (inputs[i] - mean);
            }
            
            return sqrt(res / 5);
        }

        void printInputs() {
            for (int i = 0; i < 5; i++) {
                cout << inputs[i] << endl;
            }
        }
};

int main() {
    MeanSd meanSd;

    meanSd.getInput();
    cout << "Mean = " << meanSd.getMean() << endl;
    cout << "Standard deviation = " << meanSd.getSd() << endl;

    return 0;
}
