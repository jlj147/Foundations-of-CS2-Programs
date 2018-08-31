// File Name: CharStack.cpp
//
// Author: Jayce Jones
// Date: 04/20/2016
// Assignment Number: 7
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
//Includes implemenatitons of the functions in the class declaration. Performs
//construction, push and pop functions, and checks if the string is full or
//if it is empty

#include <iostream>
#include <cassert>
#include <string>
#include "CharStack.h"

using namespace std;

//***********************************************************
// CharStack: Creates an empty stack string
//***********************************************************
CharStack::CharStack()
{
    stackString = "";
}

//*******************************************************************
// push: Appends the passed in character to the back of the string
// ch: The passed in character to be appended (popped) into the stack
//*******************************************************************
void CharStack::push(char ch)
{
    assert(!isFull());
    stackString += ch;
}

//*******************************************************************
// push: Pops off the character that is at the back of the string
//
// returns: The character that was popped
//*******************************************************************
char CharStack::pop()
{
    assert(!isEmpty());
    
    char removed = '\0'; //Initilization of bit to hold removed char
    
    for (char i=0; i < stackString.size(); i++)
    {
        removed = stackString.at(i);
    }
    stackString = stackString.substr(0, stackString.size()-1);
    
    return removed;
}

//**********************************************************************
// isFull: Checks if the string is full
//
//returns: Always returns false because the string (stack) is never full
//**********************************************************************
bool CharStack::isFull() const
{
    return false;
}

//**********************************************************************
// isEmpty: Checks if the string is empty
//
//returns: Returns true if the stack is empty, false otherwise
//**********************************************************************
bool CharStack::isEmpty() const
{
    if (stackString == "")
    {
        return true;
    }
    return false;
}

