/* Created by: Jisook Kim
 * Created on: 10/12/2016 
 * lab #13 - Looping
 * [overview]: create a program that will print every minute between two values.
 */
 
#include <iostream>
#include <string>
using namespace std;
 
 int main()
 {
    int hour = 0;
    int min = 0;
  
    int hour1 = 0;
    int hour2 = 0;  
    int minute = 0;
    
    //Create a program that will print every minute between two values.
    //First, start by programming 
    //every minute between 1:00 pm and 2:59 pm using one or more loops
    string a;
    
    hour = 1;
    
    while( (hour >= 1) && (hour <= 2) ) // 1:00pm - 2:59pm
    {
        if(min < 10)    // 0 - 9 minutes
        cout << hour << ":0" << min << "pm" << endl;
        
        else    // 10-59 minutes
        cout << hour << ":" << min << "pm" << endl;
        
        min = min + 1;
        
        if(min == 60)
        {
            min = 0;
            hour = hour + 1;
        }
    }

    //Second, accept user input for a start hour and ending hour.  
    //Print every 15 minute interval between these two times.
    cout << endl << "Enter a start hour(0-24): ";
    cin >> hour1;
    
    cout << "Enter a ending hour(0-24): ";
    cin >> hour2;
    
    hour = hour1;
    
    while((hour >= hour1) && (hour < hour2))
    {
        if(minute == 60)
        {
            minute = 0;
            hour = hour + 1;
        }
        
        if(minute < 10)   // 0 - 9 minutes
        {
            cout << hour << ":0" << a << minute << endl;
        }
        
        else    // 10 - 59 minutes
        {
            cout << hour << ":" << a << minute << endl;
        }
       
        minute = minute + 15;

    }
     
        
    return 0;
 }