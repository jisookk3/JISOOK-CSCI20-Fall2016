/* Created by: Jisook Kim
 * Created on: 10/15/2016 
 * 3.4 - For loops
 * [overview]: create a program that will print every minute between two values. Update lab13 to use for loops
 */
 
#include <iostream>
#include <string>
using namespace std;
 
 int main()
 {
    int hour1 = 0;  // for user input variables
    int hour2 = 0;  
    
    //Create a program that will print every minute between two values.
    //First, start by programming 
    //every minute between 1:00 pm and 2:59 pm using one or more loops
    
    for(int hour = 1; hour <= 2; hour ++)
    {
        for(int min = 0; min < 60; min ++)
        {
            if(min < 10)    // 0-9 minutes
                cout << hour << ":0" << min << "pm" << endl;
            else    // 10-59 minutes
            cout << hour << ":" << min << "pm" << endl;
        }
    }
    
    
    //Second, accept user input for a start hour and ending hour.  
    //Print every 15 minute interval between these two times.
   
    cout << endl << "Enter a start hour(0-24): ";
    cin >> hour1;
    
    cout << "Enter an ending hour(0-24): ";
    cin >> hour2;
    
    for(int i = hour1; i < hour2; i ++) // hour
    {
        for(int j = 0; j < 60; j = j+15)    // minutes
        {
            if(j < 10)  // 0-9 minutes
                cout << i << ":0" << j << endl;
            else    // 10-59 minutes
                cout << i << ":" << j << endl;
        }
    }
    
    cout << hour2 << ":00" << endl; // minutes for the ending hour 
    
    return 0;
 }