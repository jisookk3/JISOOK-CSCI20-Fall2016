// 1.4 Lab - Math Expressions
// Created by: Jisook Kim
// Created on: Sep 04 2016

#include <iostream>
using namespace std;

int main()
{
    int amountToCents = 0;  // user input: number of cents
    int numQuarters = 0;
    int numDimes = 0;
    int numNickels = 0;
    int numPennies = 0;
    
    double totalDollar = 0.0;   // dollar value
    double fee = 0.0;   // fee the machine charges a user
    
    cout << "Enter amount of cents you have: ";
    cin >> amountToCents;
    cout << "You have entered " << amountToCents << " cents." << endl;
    
    totalDollar = amountToCents / 100.0;    // switch cents to dollars
    fee = totalDollar * 0.109;    // 10.9% fee of the user input
    
    numQuarters = amountToCents / 25;   // number of quarters
    numDimes = ( amountToCents % 25 ) / 10;     //number of dimes
    numNickels = ( ( amountToCents % 25 ) % 10 ) / 5;   // number of nickels
    numPennies = ( ( amountToCents % 25 ) % 10 ) % 5;   // number of pennies
    
    cout << "That was " << numQuarters << " quarters, " << numDimes << " dimes, " << numNickels << " nickels and " << numPennies << " pennies." << endl;

    cout.precision(2);      // display two digits after decimal
//  cout << fixed << totalDollar;      // fixed decimal points

    cout << "The total is $" << fixed << totalDollar << "." << endl;    // two decimal points displayed
    cout << "After the fee you get $" << fixed << totalDollar - fee << " in cash." << endl;
    
    return 0;
}
