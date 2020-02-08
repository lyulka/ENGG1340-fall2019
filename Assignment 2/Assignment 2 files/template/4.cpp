//
//  Assignment 2 Task 4 template
//  Copyright © 2019 HKU COMP2113. All rights reserved.
//

// CPP program to determine if array arr[]
// can be split into three equal sum sets.
#include <iostream>
using namespace std;

///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is

// returns the sum of members of a given array from index start to index end
int sumAll(int arr[], int start, int end) {
    int temp = 0;
    for (int i = start; i <= end; i++)
        temp += arr[i];

    return temp;
}

// checks if the division m / n leaves no remainder 
bool isDivisable(int m, int n) {
    if (m % n == 0)
        return true;
    else 
        return false;
}

// findSplit: try to partition the array (arr) into three non-empty parts with equal sums.
//
// input:  int arr[], int n:  the array to split ; the length of the array
// output: the equal sum (if we find such split) or 0 [-1] (if the array cannot be partitioned)
int findSplit(int arr[], int n)
{
    // possible solution:
    // let S be the sum of all values
    int sum;
    sum = sumAll(arr, 0, n - 1);
    
    // check if arr's size is divisable with 3 without leaving a remainder
    if (!isDivisable(sum, 3))
        return 0;

    // target values we'll use to pick out i and j
    int val_i = sum / 3;
    int val_j = 2 * val_i;
    int val_k = 3 * val_i;

    // store possible options for i and j
    int options_i[10000];
    for (int c = 0; c < n; c++) 
        options_i[c] = -1;
    int options_j[10000];
    for (int c = 0; c < n; c++) 
        options_j[c] = -1;

    // index variables for appending elements to options_i and options_j
    int count_i = 0;
    int count_j = 0;

    // loop through arr to find subarrays whose sum equal val_i
    int subSum = 0;
    for (int c = 0; c < n; c++) {
        subSum += arr[c];
        if (subSum == val_i) {
            options_i[count_i] = c;
            count_i++;
        }
    }

    // loop through arr to find subarrays whose sum equal val_j
    subSum = 0;
    for (int c = 0; c < n; c++) {
        subSum += arr[c];
        if (subSum == val_j) {
            options_j[count_j] = c;
            count_j++;
        }
    }

    // loop through options_i and options_j for options of i and j
    // and check if, for these choices, 
    // sum(arr[0...i]) = sum(arr[i+1...j]) = sum(arr[j+1...n-1]),
    // and store the choices of i and j such that i + j is minimised.
    int not_found = 123456;
    int minI_J = not_found; // set to a very large value for convenience
    int bestI = not_found;
    int bestJ = not_found;

    for (int cI = 0; cI < count_i; cI++) {
        for (int cJ = 0; cJ < count_j; cJ++) {
            int i = options_i[cI];
            int j = options_j[cJ];
            if (i >= j) continue; // array index choices not valid

            // each of the subarrays have to be equal to val_i, i.e. sum / 3
            if (sumAll(arr, 0, i) == val_i &&
            sumAll(arr, i + 1, j) == val_i &&
            sumAll(arr, j + 1, n - 1) == val_i) {
                if (i +j < minI_J) {
                    minI_J = i + j;
                    bestI = i;
                    bestJ = j;
                }
            }
        }
    }

    // if bestI and bestJ are found, print them out in (bestI, bestJ) form
    if (bestI != not_found && bestJ != not_found) 
        cout << "(" << bestI << "," << bestJ << ")";

    // return minI_J if a valid minI_J was found, otherwise return 0
    if (minI_J != not_found) 
        return minI_J;
    else
        return 0;
}

///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
    int total_number;
    cin >> total_number;
    int* arr =  new int[total_number];
    for (int i = 0 ; i < total_number ; i++){
        cin >> arr[i];
    }

    if (findSplit(arr, total_number) == 0)
        cout << "-1";
    return 0;
}




