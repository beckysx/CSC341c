/*
   Xu Song
   Minh Vu
   CSC 341 W20
   Project 1c Install Waldo
   
     This file contains the main function of the project. In this project, the user input would consists of a sequence of lines describing the dependency of install some packages. The goal of the project is to find a proper order to install the "waldo" package. In this program, we assume following conditions:
            (1) packages have distinct names, and contain no spaces
            (2) the user input always include the "waldo" package
            (3) in every line of input, the first package is the target package and following packages are ones to support the target package

     How to compile:
           put all the source files in one folder. In the shell, change the directory to the folder and then compile it.
           On Linux System:
           To compile:
                 g++ -Wall  *.cpp -o 1c

           To run:
                 ./1c

           ***A compile example***
           cd /Users/Becky/Desktop/WI20/Project1/project1c
           g++ -Wall  *.cpp -o 1c
           ./1c

           
*/

#include <iostream>
#include "adj_list.hpp"
#include<string>
#include <vector>
#include <map>
#include<sstream>

using namespace std;

int main() {
    // create a adjacent list
    adj_list graph;
    string inputString, package;
    // store each package name when sstream separate from one line input
    vector<string> packages;
    // a counter
    int i = 0;
    bool flag = true;
    // while the user input not EOF
    while (getline(cin, inputString)) {
        // put one line of inputString into the sstream
        stringstream input(inputString);
        // separate each package name through space
        while (getline(input, package, ' ')) {
            // get the package name, put into packages vector
            packages.push_back(package);
            // the first package name in one line goes to head list
            if (packages.size() == 1) {
                flag = graph.pushToHeadlist(package, i);
                if (!flag) { break; }
            }
                // other supporting packages goes to sub list
            else { graph.pushToList(packages.at(0), package); }
        }
        // clear the vector, ready for next line of input
        packages.clear();
        // the index counter for next target package
        i++;
    }
    // if we can get a result
    if (graph.traverse("waldo")) {
        graph.printResult();
    } else {
        cout << "ERROR" << endl;
    }
    return 0;
}
