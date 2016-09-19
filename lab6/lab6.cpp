// Lab #6: Intro to functions
// Created by: Jisook Kim
// Created on: Sep 17 2016 

#include <iostream>
#include <string>       // "string" data type - library
using namespace std;

void copyrightFunc()    // create a function
{
    string symb1 = " | ===========* * *=========== |";
    char symb2 = '|';
    cout << endl << symb1 << endl;
    cout << symb1 << endl;
    cout << " " << symb2 << "  Copyright Jisook Kim 2016  " << symb2 << endl;
    cout << symb1 << endl;
    cout << symb1 << endl << endl;
    
    return;
}

// one of my previous labs (program #1 variables) // I called a function two times in main()

int main()
{
    // 1. define variables: name, hours, rate(hourly salary), gross pay, net pay, tax
    string nameOne;
    int hoursWork = 0;
    double hourlySalary, grossPay, netPay, tax = 0.0;
    
    // call a copyright function
    copyrightFunc();
        
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
    cout << " || Gross Pay: $" << grossPay << " || Net Pay(17% taxes deducted): $" << netPay << endl;
    
    // call a copyright function
    copyrightFunc();
    
    return 0;
}