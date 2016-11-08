/* Created by: Jisook Kim
 * Created on: 11/5/2016 
 * 4.4 Lab - String Class
 * Requirements: Use ONLY string tools
 * This program is responsible for creating user names for a new website you have created.  
 * It should accept a first name of up to 10 characters and a last name of up to 20 characters.  
 * It should tell the user if the name is larger than the max size.  
 * It should also determine if the names are the same and output a warning.  
 * After checking these things, it should create three different user name options 
 * (for example: apbrowne; aprilbrowne; abrowne).
 */
 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// check string size whether it is larger than max size 
bool checkSize(string name, int size)
{
    if(name.size() > size)
    {
        cout << "The name is larger than the max size!" << endl;
        return false;
    }
    else    return true;
}


int main()
{
    string firstName = ""; // first name up to 10 characters
    string lastName = "";  // last name up to 20 characters
    
    string firstName1 = "";
    string firstName2 = "";
    
    bool enterAgain1, enterAgain2 = false;  // for checking the right size of string

    // make sure appropriate size to store names and not the same names
    do{
        while(!enterAgain1)  // make sure up to 10 chars 
        {
            cout << "Enter your first name (<=10 chars): ";
            cin >> firstName;
            enterAgain1 = checkSize(firstName, 10);   // check the size of string if it is the max size
        }
        
        while(!enterAgain2)  // make sure up to 20 chars
        {
            cout << "Enter your last name (<=20 chars): ";
            cin >> lastName;
            enterAgain2 = checkSize(lastName, 20);
        }
        
        if(firstName == lastName)   // if they are the same names
        {
            cout << "The names are the same. Please make sure to enter different names." << endl;
            enterAgain1 = false;    // have the loop of entering names do again
            enterAgain2 = false;
        }
        
    }while(firstName == lastName); // run the do while loop until first name and last name are correct input
       
    cout << endl << "Name: " << firstName << " " << lastName << endl;   
    
    // create three different user name options - 3 display
    
    // change the first letter to lowercase
    firstName.at(0) = tolower(firstName.at(0));
    lastName.at(0) = tolower(lastName.at(0));
    
    cout << "Which of the three user names would you like: " << endl;
    
    firstName1 = firstName;
    firstName1.resize(2);
    cout << "1) " << firstName1 << lastName << endl;    
    
//    firstName1 = firstName1 + firstName1.at(1);
//    cout << " first name 1: "<< firstName1 << endl;
    
    firstName.append(lastName);
    cout << "2) " << firstName << endl;
    
    firstName2 = firstName.at(0);
    firstName2.append(lastName);
    cout << "3) " << firstName2 << endl;   

    return 0;
}