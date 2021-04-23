/*
Xu Song
Minh Vu
CSC 341 W20
Project 1b RPN CALCULATOR
 
 This is IntStack class head file, this file declares the constructor and all the methods of a IntStack object. The methods includes all the modifiers we need in the main file to make the RPN calculator works.
 */

#ifndef IntStack_hpp
#define IntStack_hpp

#include <iostream>
#include <vector>

using namespace std;

class IntStack {
private:
    vector<int> body;
public:
    IntStack();

    int pop();

    void push(int val);

    void clear();

    int size();

    bool isEmpty();

    bool add();

    bool sub();

    bool times();

    bool div();

    bool swap();

    bool duplicate();

    bool eq();

    bool detectNegative(int a, int b);

};

#endif /* IntStack_hpp */
