/*
Xu Song
Minh Vu
CSC 341 W20
Project 1b Install Waldo
 
 This is adj_list class implementation file, this file defines the constructor and all the methods of an adj_list object. The methods includes all the modifiers we need in the main file to solve the proper order of the user input.
 
 
 *****Detail Description*****
 Here are the attributes of an adj_list object (adjacent list)
 
     vector<string> result;
     vector<vector <string> > headList;
     map<string, int> dictionary;
     vector<int> markList;
 
 The headList is a 2D vector which contains multiple vectors contains strings (package names). For each line of the input, the first package will be also be the first element in the sub-vector of headList. All the packages that support this first package will be stored in the sub-vector as well. The index of a sub-vector in the headList is corresponding to one package name store in the dictionary. The dictionary is a map that uses package name as key word and the index of sub-vector of this package in the headList as the value.
 
 The basic algorithm of the design is using topological sort and recursion. Every package has three mark, stored in the markList. 0 refers to haven't check, 1 refers to temperate mark, 2 refers to permeant mark. Start with the "waldo" package, if a package is 0, mark to 1, if it can be installed, mark to 2, and push to result. If a package is already marked 1, but revisits again, return false, because we got a loop.
 
 
 */

#include "adj_list.hpp"
#include <iostream>
#include<string>
#include <vector>
#include <stack>
#include <map>
#include <stdio.h>

using namespace std;

adj_list::adj_list() {}

//return a bool value to check if the operation can be done
// side effect: add one new vector inside the 2D vector "HeadList"; add a pair to the map "dictionary"; add one int to markList (mark the package as haven't reached)
bool adj_list::pushToHeadlist(string name, int i) {
    if (!(dictionary.count(name) > 0)) {
        dictionary[name] = i;
        markList.push_back(0);
        vector<string> head;
        head.push_back(name);
        headList.push_back(head);
        return true;
    } else { return false; }
}

// push supporting packages to the head package
// side effect: add one new string inside one of the 2D vector "HeadList"
void adj_list::pushToList(string headname, string name) {
    int i = getIndex(headname);
    headList.at(i).push_back(name);
}

// get index of package in 2D list by passing the package name
// no side effect
int adj_list::getIndex(string name) {
    return dictionary.find(name)->second;
}

// side effect: print all the strings in the result on console
void adj_list::printResult() {
    for (int i = 0; (unsigned) i < (unsigned) result.size(); i++) {
        cout << result.at(i) << endl;
    }
}

// mark the given package to "i"
void adj_list::mark(int i, string name) {
    int index = getIndex(name);
    markList.at(index) = i;
}

// return the mark of the package
// no side effect
int adj_list::getmark(string name) {
    int index = getIndex(name);
    return markList.at(index);
}

// return true if find the sollution
bool adj_list::traverse(string name) {
    // if can't find the package in dictionary (the package is unreachable)
    if (dictionary.find(name) == dictionary.end()) {
        return false;
    }
    int index = getIndex(name);
    // if the package is already installed
    if (getmark(name) == 2) {
        return true;
    }
        // if the package have been visited once before
    else if (getmark(name) == 1) {
        return false;
    }
    // mark to one
    mark(1, name);
    vector<string> v = headList.at(index);
    // recurse for each supporting packages
    for (int a = 1; (unsigned) a < (unsigned) v.size(); a++) {
        if (!traverse(v.at(a))) {
            return false;
        }
    }
    // mark to installed
    mark(2, name);
    result.push_back(name);
    return true;


}

