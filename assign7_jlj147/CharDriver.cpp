// File Name: CharDriver.cpp
//
// Author: Jayce Jones
// Date: 04/20/2016
// Assignment Number: 7
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
//Driver for CharStack program, given a file name it determines if all the
//parenthese, curly braces, and square brackets match. If they do not the
//appropiate error messages are given

#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

#include "Charstack.h"

using namespace std;

int main()
{
    string infix;
    int size;
    char postfix[size];
    
    
    cout << "Enter and expression to be converted from infix to postfix: ";
    getline(cin, infix);
    size = strlen(infix.c_str());
    convesrion(infix,postfix,size);
    
    
}
