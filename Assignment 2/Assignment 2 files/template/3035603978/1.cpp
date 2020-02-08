//
//  Assignment 2 Task 1 template
//  Copyright © 2019 HKU COMP2113. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double e=2.72;
const int MAX_T = 100;

///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// You may implement additional functions here


// Function: sigmoid activation function
// Input: double x: the input of sigmoid activation function
// Ouput: the output of sigmoid activation function
double sigmoid(double x)
{
  return (1.0 / (1.0 + pow(e, -x)));
}

// Function: tanh activate function
// Input: double x: the input of tanh activation function
// Ouput: double: the output of tanh activation function.
double tanh(double x)
{
  return (2 * sigmoid(2 * x) - 1);
}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  return tanh(0.6 * x - 2 * h);
}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  return sigmoid(0.2 * x + 2 * h);
}

// Function: print the values stored in a 1D-array to screen
// Input: double xs[]: the value of the sequence
//        int seq_len: the length of the sequence
void PrintSeqs(double xs[], int seq_len)
{
  for (int i = 0; i < seq_len; i++)
    cout << xs[i] << " ";
}

// Function: main function
int main()
{
  // storing hStates, xInputs, and oOutputs in arrays of doubles
  int t;
  cin >> t;
  double hStates[10000];
  cin >> hStates[0];
  double xInputs[10000];
  double oOutputs[10000];

  double xInput;
  // as instructed, fill up oOutputs and hStates with 
  // all of their subvalues, skipping hState number 0 
  // as that has been provided previously.
  for (int i = 0; i < t; i++) {
    cin >> xInput;
    oOutputs[i] = ComputeO(xInput, hStates[i]);
    hStates[i + 1] = ComputeH(xInput, hStates[i]);
  }

  // set number of decimal places in std::cout
  cout << setprecision(10);
  for (int i = 1; i < t + 1; i++)
    cout << hStates[i] << " "; 
  cout << endl;
  PrintSeqs(oOutputs, t);
}