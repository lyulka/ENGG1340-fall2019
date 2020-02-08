using namespace std;

class mean_sd {
    public: //  This is how you delineate between private and public vars in C++++
        double inputs[5]; // The syntax for creating arrays in C++ is upside down.
        void getInput();
        double getMean();
        double getSd();
};