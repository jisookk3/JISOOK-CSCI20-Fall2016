
// Program #1 Variables
// Created by: Jisook Kim
// Created on: Sep 12 2016  // My algorithm is already approved by my instructor, April.

/* Calculate a person’s weekly wages based on hourly salary and hours. 
Determine how much they would get paid if they paid 17% in taxes.  
Create a wage slip with name, hours, rate, gross pay, and net pay. */

#include <iostream>
#include <string>       // "string" data type - library
using namespace std;

int main()
{
    // 1. define variables: name, hours, rate(hourly salary), gross pay, net pay, tax
    string nameOne;
    int hoursWork = 0;
    double hourlySalary, grossPay, netPay, tax = 0.0;
    
    // 2. input: name, hourly salary, hours
    cout << "Enter an employee name: " << endl;
    getline(cin, nameOne);      // get input all text until a user press ENTER
    cout << "Enter hourly salary($): " << endl;
    cin >> hourlySalary;
    cout << "Enter work hours: " << endl;
    cin >> hoursWork;
    
    // 3. gross pay = hourly salary * hours * 5 (assume 5 days work per week)
    grossPay = hourlySalary * hoursWork * 5;
    
    // 4. 17% tax = gross pay * 0.17
    tax = grossPay * 0.17;
    
    // 5. net pay = gross pay - tax
    netPay = grossPay - tax;
    
    // 6. print out a wage slip
    cout.precision(2);  // display two-place decimal
    cout << endl << " [ Wage Slip (Weekly) ]" << endl;
    cout << "Name: " << nameOne << fixed << " || Rate: $" << hourlySalary << " || Hours: " << hoursWork;
    cout << " || Gross Pay: $" << grossPay << " || Net Pay(deducting 17% taxes): $" << netPay;
    
    return 0;
}