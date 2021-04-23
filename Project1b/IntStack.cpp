/*
Xu Song
Minh Vu
CSC 341 W20
Project 1b RPN CALCULATOR
 
 This is IntStack class implementation file, this file defines the constructor and all the methods of a IntStack object. The methods includes all the modifiers we need in the main file to make the RPN calculator works.
 
 */

#include "IntStack.hpp"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Default Constructor
IntStack::IntStack() {

}

// pop method returns the popped integer.
// side effect: pop the top element, IntStack size --
int IntStack::pop() {
    int topval = body.back();
    body.pop_back();
    return topval;
}

// push a new integer on the top of the IntStack
// side effect: IntStack size ++
void IntStack::push(int val) {
    body.push_back(val);
}

// make the stack empty
// side effect: IntStack size becomes 0
void IntStack::clear() {

    body.clear();
}

// check the stack size
int IntStack::size() {
    return body.size();
}

// check if the stack is Empty or not
bool IntStack::isEmpty() {
    return body.size() == 0;
}

// returns bool to indicate the modify is success or not
// side effect: IntStack size --; Error encounters will print error messages to console; adds the two numbers on the top of the stack (when size >=2) and push it back
bool IntStack::add() {
    int elenum = body.size();
    if (elenum >= 2) {
        int first = pop();
        int second = pop();
        push(first + second);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// returns bool to indicate the modify is success or not
// side effect: IntStack size --; Error encounters will print error messages to console; subtracts number on top of the stack from number that is next to the top (when size >=2) and push it back
bool IntStack::sub() {
    int elenum = body.size();
    if (elenum >= 2) {
        int first = pop();
        int second = pop();
        push(second - first);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// returns bool to indicate the modify is success or not
// side effect: IntStack size --; Error encounters will print error messages to console; multiplies the two number on the top of the stack (when size >=2) and push it back
bool IntStack::times() {
    int elenum = body.size();
    if (elenum >= 2) {
        int first = pop();
        int second = pop();
        push(second * first);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// return a bool, true for if both numbers have the same sign, false if they don't have same sign
bool IntStack::detectNegative(int a, int b) {
    if (a < 0 && b < 0) { return false; }
    else if (a > 0 && b > 0) { return false; }
    else if (a > 0 && b < 0) { return true; }
    else {
        return true;
    }
}

// returns bool to indicate the modify is success or not
// side effect: IntStack size --; Error encounters will print error messages to console;performs integer division, dividing the number that is second from the top of the stack by the number that is on the top of the stack (when size >=2)and push it back
bool IntStack::div() {
    int elenum = body.size();
    if (elenum >= 2) {
        int first = body.back();
        // when denominator is 0
        if (first == 0) {
            cout << "ERROR" << endl;
            return false;
        }
        pop();
        int second = pop();
        int result;
        bool negative = detectNegative(first, second);
        if (negative && (second % first != 0)) {
            result = (second / first) - 1;
        } else {
            result = second / first;
        }
        push(result);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// returns bool to indicate the operation is success or not
// side effect: IntStack size --;Error encounters will print error messages to console; pops the one remaining item from the stack and prints it to the standard out
bool IntStack::eq() {
    int elenum = body.size();
    if (elenum == 1) {
        int topval = pop();
        cout << topval << endl;
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// returns bool to indicate the modify is success or not
// side effect:swaps the order of the two items on the top of the stack; Error encounters will print error messages to console
bool IntStack::swap() {
    int elenum = body.size();
    if (elenum >= 2) {
        int first = pop();
        int second = pop();
        push(first);
        push(second);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}

// returns bool to indicate the modify is success or not
// side effect:duplicates whatever is on the top of the stack; Error encounters will print error messages to console,IntStack size ++
bool IntStack::duplicate() {
    int elenum = body.size();
    if (elenum >= 1) {
        int first = body.back();
        push(first);
        return true;
    } else {
        cout << "ERROR" << endl;
        return false;
    }
}
