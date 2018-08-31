// File Name: PasswordDriver.cpp
//
// Author: Jayce Jones
// Date: 3/17/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instruc1tor: Jill Seaman
//
//Allow the user to test the PasswordManager

#include <iostream>
#include <fstream>
#include <cctype>
#include "PasswordManager.h"

using namespace std;

int main()
{
    char menuChoice;    //users menu choice (A,B, or C)
    string newPassword; //proposed password user enters when chosing option A
    string existPassword; //user entered password when chosing option B
    string ePass; //encrypted password to be saved to a file
    string tempPass; //temporary password before creating or finding an
                    //encrypted password
    bool resultA;   //bool flag that signifies wheter the password has been
                    //changed when option A is chosen
    bool resultB;   //bool flag that signifies wheter the password in valid or
                    //invalid when option B is chosen
    PasswordManager pw; //for accessing the PasswordManager class
    
    //File and password check
    ifstream fin;
    fin.open("password.txt");
    if (!fin)
    {
        tempPass = pw.getEncryptedPassword();
        tempPass = "abc123@@@";
        pw.setEncryptedPassword(tempPass);
        cout << "The file was not found, default password set" << endl;
    }
    else
    {
        fin >> tempPass;
        tempPass = pw.setEncryptedPassword(tempPass);
    }
    fin.close();
    
    do
    {
    //Menu
    cout << endl;
    cout << "Password Utilities" << endl;
    cout << "A. Change Password" << endl;
    cout << "B. Validate Password" << endl;
    cout << "C. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> menuChoice;
    cout << endl;
        
        while ((toupper(menuChoice)!= 'A') && (toupper(menuChoice) != 'B') &&
               (toupper(menuChoice) != 'C'))
        {
            cout << "Please enter a valid menu choice: ";
            cin >> menuChoice;
            cout << endl;
        }
        
        //Option A changes password
        if (toupper(menuChoice)=='A')
        {
            cout << "Option A: Change Password" << endl;
            cout << "Your password must be at least 8 characters long and "
                 << "contain three of" << endl;
            cout << "the following:" << endl;
            cout << "Uppercase letters" << endl;
            cout << "Lowercase letters" << endl;
            cout << "Symbols" << endl;
            cout << "Numbers" << endl;
            cout << "Enter the new password: ";
            cin >> newPassword;
            resultA = pw.setNewPassword(newPassword);
            
            if (resultA == true)
            {
                cout << "The password has been successfully changed" << endl;
            }
            if (resultA == false)
            {
                cout << "The password did not meet the criteria" << endl;
            }
        }
        
        //Option B validates password
        if (toupper(menuChoice)=='B')
        {
           cout << "Option B: Validate Password" << endl;
           cout << "Enter the existing password: ";
           cin >> existPassword;
           resultB = pw.validatePassword(existPassword);
           if (resultB == true)
           {
               cout << "Valid password" << endl;
           }
           if (resultB == false)
           {
               cout << "Invalid password" << endl;

           }
        }
        
    }while(toupper(menuChoice) != 'C');
    
    //Option C saves the encrypted password to a file
    if (toupper(menuChoice) == 'C')
    {
        ePass = pw.getEncryptedPassword();
        ofstream fout;
        fout.open("password.txt");
        if(!fout)
        {
            cout << "The file was not found" << endl;
        }
        else
        {
            fout << ePass;
            cout << "Encrypted password written to password.txt" << endl;
        }
        fout.close();
    }
    return 0;

}


