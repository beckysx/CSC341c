/*
Xu Song
Minh Vu
CSC 341 W20
Project 1b Install Waldo
 
 This is adj_list class head file, this file declares the constructor and all the methods of a adj_list object. The methods includes all the modifiers we need in the main file to solve the proper order of the user input.
 Details of the adj_list are explained in the implementation file of adj_list class.
 
 */

#ifndef adj_list_hpp
#define adj_list_hpp

#include <iostream>
#include<string>
#include <vector>
#include <stack>
#include <map>
#include <stdio.h>

using namespace std;

class adj_list {
public:
    vector<string> result;
    vector<vector<string> > headList;
    map<string, int> dictionary;
    vector<int> markList;

    adj_list();

    bool pushToHeadlist(string name, int i);

    void pushToList(string headname, string name);

    void printResult();

    bool traverse(string name);

    int getIndex(string name);

    void mark(int i, string name);

    int getmark(string name);

};

#endif /* adj_list_hpp */
