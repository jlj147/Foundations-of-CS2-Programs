// File Name: PasswordDriver.cpp
//
// Author: Jayce Jones
// Date: 3/17/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instruc1tor: Jill Seaman
//
//Functions that allow the password manager to operate

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include "PasswordManager.h"

using namespace std;

//*******************************************************************
// encrypt: Takes a string (password) entered by the user and encrypts
//          it using a Caesar Cipher
//
// newPassword: String entered by the user to be encrypted
// returns: The encrypted form of the use entered password
//********************************************************************
string PasswordManager::encrypt(string newPassword)
{

    string ePass;   //string that holds the proposed password
                    //and then the encrypted password
    
    for(int i=0;i < newPassword.length();i++)
    {
        ePass += ((newPassword[i]-33)+10)%94+33;
    }
    
    return ePass;
}


//*******************************************************************
// verifyPassword: Takes a string (proposed password) entered by the
//                 user and checks to see if it meets the criteria
//
// newPassword: String entered by the user to be tested
// returns: True if the string meets the criteria
//          False if the string does not meet the criteria
//********************************************************************
bool PasswordManager::verifyPassword(string newPassword)
{
    bool uppercaseCheck = false; //test flag for uppercase letters
    bool lowercaseCheck = false; //test flag for lowercase letters
    bool numberCheck = false;   //test flag for numbers
    bool symbolCheck = false;   //test flag for symbols
    
    //testing for criteira
    for (int i=0; i < newPassword.length(); i++)
    {
        if(isupper(newPassword[i]))
            uppercaseCheck = true;
        if(islower(newPassword[i]))
            lowercaseCheck = true;
        if(isdigit(newPassword[i]))
            numberCheck = true;
        if(ispunct(newPassword[i]))
            symbolCheck = true;
    }
    
    //testing if sets of criteria have been met
    if (uppercaseCheck == true && lowercaseCheck == true &&
        numberCheck == true && symbolCheck == true && newPassword.length() > 7)
        return true;
    
    if (uppercaseCheck == true && lowercaseCheck == true && numberCheck ==
        true && newPassword.length() > 7)
        return true;
    
    if(uppercaseCheck == true && lowercaseCheck == true && symbolCheck ==
            true && newPassword.length() > 7)
        return true;
    
    if(uppercaseCheck == true && symbolCheck == true && numberCheck ==
            true && newPassword.length() > 7 == true)
        return true;
    
    if(lowercaseCheck == true && symbolCheck == true && numberCheck ==
            true && newPassword.length() > 7 == true)
        return true;
    
    else
        return false;
}

//*******************************************************************
// setEncryptedPassword: A setter function that takes the encrypted
//                       password and stores it in the member variable
//
// ePass: Encrypted password that is to be stored in the member variable
// returns: True when the encrypted password is stored in the member variable
//********************************************************************
bool PasswordManager::setEncryptedPassword(string ePass)
{
    encryptedPass=ePass;
    return true;
}

//*******************************************************************
// getEncryptedPassword: A getter function that returns the value of the
//                       encrypted password in the member variable
//
// returns: The encrypted password
//********************************************************************
string PasswordManager::getEncryptedPassword()
{
    return encryptedPass;
}

//*******************************************************************
// setNewPassword: Takes a string (proposed password) and passes it to
//                 verifyPassowrd, if the criteria is met the password
//                 is sent to be encrypted and stored if not nothing is done
//
// newPassword: A string (proposed password) entered by the user
// returns: True when the encrypted password is stored in the member variable
//          False when the proposed password did not pass the criteria check
//********************************************************************
bool PasswordManager::setNewPassword(string newPassword)
{
    bool criteriaCheck; //flag varibale assigned true or false from
                        //verifyPassword
    string ePass; //string that holds proposed password and then the
                 //encrypted password
    
    criteriaCheck = verifyPassword(newPassword);
    
    if (criteriaCheck == true)
    {
        ePass = encrypt(newPassword);
        setEncryptedPassword(ePass);
        return true;
    }
    else
        return false;
}

//*******************************************************************
// validatePassword: takes a string (a password) and checks for its
//                   validity when the user choses option B
//
// existPass: A password entered by the user that is to be validated
// returns: True if the password matches the encrypted password
//          False if the password and the encrypted password differ
//********************************************************************
bool PasswordManager::validatePassword(string existPass)
{
    string tempPass; //string that temporarily holds a encrypted password
    string tempPass2;//string that temporarily holds the encryted password
    tempPass = encrypt(existPass);
    tempPass2 = getEncryptedPassword();
    if (tempPass == tempPass2)
        return true;
    else
        return false;
}







