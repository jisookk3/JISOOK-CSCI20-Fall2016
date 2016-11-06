/* Created by: Jisook Kim
 * Created on: 11/3/2016 
 * 4.3 Lab - C Strings
 * This program is responsible for creating user names for a new website you have created.  
 * It should accept a first name of up to 10 characters and a last name of up to 20 characters.  
 * It should tell the user if the name is larger than the max size.  
 * It should also determine if the names are the same and output a warning.  
 * After checking these things, it should create three different user name options 
 * (for example: apbrowne; aprilbrowne; abrowne).
 */
  
 #include <iostream>
 #include <cstring>
 #include <cctype>
 using namespace std;
 
 // check string size if it is larger than max size 
 bool checkSize(char* name, int size)
 {
     if(strlen(name) > size)
     {
         cout << "The name is larger than the max size!" << endl;
         return false;
     }
     else
         return true;
 }
 
 
 int main()
 {
     char firstName1[30] = "";
     char firstName2[30] = "";
     
     char firstName[30] = ""; // first name up to 10 characters
     char lastName[30] = "";  // last name up to 20 characters
     int a;
     bool enterAgain1, enterAgain2 = false;  // for checking the size of string
 
     // make sure appropriate size to store names and not the same names
     do {
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
         
         a = strcmp(firstName, lastName);  // returns 0 if they are the same
         
         if(a == 0)
         {
             cout << "The names are the same. Please make sure to enter different names." << endl;
             enterAgain1 = false;    // have the loop of entering names do again
             enterAgain2 = false;
         }
      } while(a == 0); 
        
     cout << endl << "Name: " << firstName << " " << lastName << endl;   
     
     // create three different user name options - 3 display
     firstName[0] = tolower(firstName[0]);   // make the whole name lowercase
     lastName[0] = tolower(lastName[0]);    
 
     //firstName1[2] = '\0';
     
     strncpy(firstName1, firstName, 2);  // copy first 2 letters of the first name
     strncpy(firstName2, firstName, 1);  // copy first 1 letters of the first name
     
     cout << "Which of the three user names would you like: " << endl;
     strcat(firstName1, lastName);
     cout << "1) " << firstName1 << endl;
     strcat(firstName, lastName);
     cout << "2) " << firstName << endl;
     strcat(firstName2, lastName);
     cout << "3) " << firstName2 << endl;
 
 
     return 0;
 } 