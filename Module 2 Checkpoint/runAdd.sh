#!/bin/bash

#compile the code
g++ add.cpp -o add
#Run the code and display result
./add < input.txt > output.txt

cat output.txt