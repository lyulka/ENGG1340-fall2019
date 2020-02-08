//
//  Assignment 2 Task 2 template
//  Copyright © 2019 HKU COMP2113. All rights reserved.
//


#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;


///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is


// You may implement additional functions here
void printMaze(int map[][MAX_SIZE], int map_h, int map_w) {
  for (int y = 0; y < map_h; y++) {
    for (int x = 0; x < map_w; x++) {
      cout << map[y][x] << " ";
    }
    cout << endl;
  }
}

int* getOrigin(int map[][MAX_SIZE], int map_h, int map_w) {
  int res[2];

  res[0] = -1;
  res[1] = -1;

  for (int y = 0; y < map_h; y++) {
    for (int x = 0; x < map_w; x++) {
      if (map[y][x] == 1) {
        res[0] = y;
        res[1] = x;
      }
    }
  }

  return res;
}

int* getEnd(int map[][MAX_SIZE], int map_h, int map_w) {
  int res[2];

  res[0] = -1;
  res[1] = -1;

  for (int y = 0; y < map_h; y++) {
    for (int x = 0; x < map_w; x++) {
      if (map[y][x] == -2) {
        res[0] = y;
        res[1] = x;
      }
    }
  }
  
  return res;
}

void markPath(int map[][MAX_SIZE], int curY, int curX, int curStep) {

  // If the current spot hasn't been marked, mark it.
  if (map[curY][curX] == 0 || map[curY][curX] > curStep)
    map[curY][curX] = curStep;

  // cout << "Current step: " << curStep << endl; // DEBUG
  // printMaze(map, map_h, map_w); // DEBUG

  // Mark to the left...
  if (curX - 1 >= 0 && (map[curY][curX - 1] == 0 || map[curY][curX - 1] > curStep + 1)) 
    markPath(map, curY, curX - 1, curStep + 1);

  // Mark to the bottom!
  if (map[curY + 1][curX] == 0 || map[curY + 1][curX] > curStep + 1)
    markPath(map, curY + 1, curX, curStep + 1);

  // Mark to the right...
  if (map[curY][curX + 1] == 0 || map[curY][curX + 1] > curStep + 1)
    markPath(map, curY, curX + 1, curStep + 1);

  // Mark to the top!
  if (curY - 1 >= 0 && (map[curY - 1][curX] == 0 || map[curY - 1][curX] > curStep + 1))
    markPath(map, curY - 1, curX, curStep + 1);
}

// Get the minimum value amongst the four tiles surrounding the finish line
int getMin(int map[][MAX_SIZE], int max_h, int max_w) {
  int curMin = 10000; // arbitrarily large int so as to accomodate all cases

  int endY = getEnd(map, max_h, max_w)[0];
  int endX = getEnd(map, max_h, max_w)[1];

  // Check to the left...
  if (endX - 1 >= 0 && map[endY][endX - 1] < curMin && map[endY][endX - 1] >= 1)
    curMin = map[endY][endX - 1]; 

  // Check to the bottom!
  if (map[endY + 1][endX] < curMin && map[endY + 1][endX] >= 1)
    curMin = map[endY + 1][endX];

  // Check to the right...
  if (map[endY][endX + 1] < curMin && map[endY][endX + 1] >= 1)
    curMin = map[endY][endX + 1];

  // Check to the top!
  if (endY - 1 >= 0 && map[endY - 1][endX] < curMin && map[endY - 1][endX] >= 1)
    curMin = map[endY - 1][endX];

  // If a minimum value isn't found, just return 0.
  if (curMin == 10000) return 0;
  else return curMin; // otherwise, return the minimum value.
  
}


// Function: find the smallest number of steps to go from the starting point
//           to the destination in a given map.
//
// Input: int map[][]: 2D-array map
//        int map_h: the height of the map
//        int map_w: the width of the map
// Output: return true if a path is found, and store the smallest number of
//                      steps taken in &num_steps (pass-by-reference)
//         return false if there is no path
// ==============================================================
bool FindPath(int map[][MAX_SIZE], int map_h, int map_w, int &num_steps)
{
  int maxSteps = 0;
  int originY = getOrigin(map, map_h, map_w)[0];
  int originX = getOrigin(map, map_h, map_w)[1];

  // Check if supplied map actually has a start, if not, return false;
  if (originY == -1)
    return false;

  // Check if the supplied map actually has an end, if not, return false.
  if (getEnd(map, map_h, map_w)[0] == -1)
    return false; 

// Marks the path complete with step numbers
  markPath(map, originY, originX, 1);

// Fetches the minimum tile value adjacent to the end
  maxSteps = getMin(map, map_h, map_w);

  // printMaze(map, map_h, map_w); 

  if (maxSteps > 0) {
    num_steps = maxSteps;
    return true;
  } else 
    return false;
}

///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  int map_h;
  int map_w;
  cin >> map_h >> map_w;

  int map[MAX_SIZE][MAX_SIZE];

  // initialize map
  for (int i=0; i<MAX_SIZE; i++)
    for (int j=0; j<MAX_SIZE; j++)
      map[i][j] = -1;

  // read map from standard input
  for (int i=0; i<map_h; i++)
    for (int j=0; j<map_w; j++)
      cin >> map[i][j];

  int steps;
  // print to screen number of steps if a path is found, otherwise print "No"
  if (FindPath(map, map_h, map_w, steps))
    cout << steps << endl;
  else
    cout << "No" << endl;
}
