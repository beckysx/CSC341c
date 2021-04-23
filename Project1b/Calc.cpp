/*
    Xu Song
    Minh Vu
    CSC 341 W20
    Project 1b RPN CALCULATOR
    
      This in the main file creates a RPN calculator based on a stack. The calculator only takes integers and 7 operators which can modify the stack and output result. Any Error encounters, we clear the stack and ask for input continuously until EOF.
 
      How to compile:
            put all the source files in one folder. In the shell, change the directory to the folder and then compile it.
            On Linux System:
            To compile:
                  g++ -Wall  *.cpp -o 1b
 
            To run:
                  ./1b
 
            ***A compile example***
            cd /Users/Becky/Desktop/WI20/Project1/project1b
            g++ -Wall  *.cpp -o 1b
            ./1b
 
            
 */

#include <iostream>
#include <locale>
#include <cctype>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include "IntStack.hpp"

using namespace std;

// return a bool to indicate if the argument is a integer or not
bool isInteger(string s) {
    char negSign = s.at(0);
    // if the first character of the argument is negative sign, it is a potential negative integer
    if (negSign == '-' && s.length() > 1) {
        // ignore the negative sign, checking starts at second character
        for (int i = 1; (unsigned) i < (unsigned) s.length(); i++) {
            if (!isdigit(s[i])) { return false; }
        }
        return true;
    }
    // if no negative sign is detected, it's a potential positive integer
    // checking starts at the first character
    for (int i = 0; (unsigned) i < (unsigned) s.length(); i++) {
        if (!isdigit(s[i])) { return false; }
    }
    return true;
}


// convert the input string to a integer by using string stream
int convertToInt(string s) {
    stringstream tool;
    int num;
    tool << s;
    tool >> num;
    return num;
}

// returns bool to indicate operations are success or not
// side effects: change the stack accordingly by getting different inputs from the user. When an error is encountered, the error message will show on the console accordingly.
bool opp(IntStack &stack, char sin) {
    if (sin == '+') { return stack.add(); }
    else if (sin == '-') { return stack.sub(); }
    else if (sin == '*') { return stack.times(); }
    else if (sin == '/') { return stack.div(); }
    else if (sin == '=') { return stack.eq(); }
    else if (sin == 's') { return stack.swap(); }
    else if (sin == 'd') { return stack.duplicate(); }
    else {
        cout << "ERROR" << endl;
        return false;
    }
}


// returns bool to indicate operations are success or not
// side effects: change the stack accordingly by getting different inputs from the user. When an error is encountered, the error message will show on the console accordingly.
bool calculator(IntStack &stack) {
    bool flag = true;
    while (flag) {
        string input;
        // if input not EOF
        if (cin >> input) {
            // if input is a integer
            if (isInteger(input)) {
                // change input form string to input
                int num = convertToInt(input);
                stack.push(num);
            }
                // if input is potential operator
            else {
                // when string length longer than 1 and is not a negative number
                if (input.length() > 1) {
                    cout << "ERROR" << endl;
                    stack.clear();
                    flag = false;
                }
                    // string length is 1, potential operator
                else {
                    char char_array[1];
                    // change input string to character array
                    strcpy(char_array, input.c_str());
                    // put stack and the first character of the character array to opp() function
                    flag = opp(stack, char_array[0]);
                }
                if (flag == false) {
                    stack.clear();
                }
            }
        }
            // if user input EOF
        else {
            if (stack.size() != 0) {
                cout << "ERROR" << endl;
            }
            stack.clear();
            return false;
        }
    }
    return true;
}

int main() {
    IntStack cal;
    bool flag = true;
    while (flag) {
        flag = calculator(cal);
    }
    return 0;
}
