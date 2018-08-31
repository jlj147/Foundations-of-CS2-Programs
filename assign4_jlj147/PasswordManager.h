// File Name: PasswordManager.h
//
// Author: Jayce Jones
// Date: 3/17/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instruc1tor: Jill Seaman
//
//Class declartion for Password Manager

#include <string>
using namespace std;

class PasswordManager
{
private:
    string encryptedPass;
    string encrypt(string);
    bool verifyPassword(string);
    
public:
    bool setEncryptedPassword(string);
    string getEncryptedPassword();
    bool setNewPassword(string);
    bool validatePassword(string);
};

