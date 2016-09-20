// 2.2 Lab - Parameters and Arguments
// Created by: Jisook Kim
// Created on: Sep 19 2016 

#include <iostream>
#include <string>       // "string" data type - library
using namespace std;

// Create a program to display a song of your choice that 
// uses functions with parameters and arguments.
// song source:
// http://www.theteachersguide.com/kidsongs/fivelittleducks.htm

void FiveLittleDuck()   // verse part
{
    cout << "Sad mother duck" << endl
        << "Went out one day" << endl
        << "Over the hill and far away" << endl
        << "The sad mother duck said" << endl
        << "\"Quack, quack, quack.\"" << endl
        << "And all of the five little ducks came back." << endl;
}

void chorus(string number1, string number2) // chorus part
{
    cout << number1 << " little ducks" << endl
        << "Went out one day" << endl
        << "Over the hill and far away" << endl
        << "Mother duck said" << endl
        << "\"Quack, quack, quack, quack.\"" << endl
        << "But only " << number2 << " little ducks came back." << endl << endl;
}

int main()
{
    cout << endl << "*** Song: Five Little Ducks ***" << endl << endl;  // song title
    
    chorus("Five", "four");     // 4 times repeat the chorus, two parameters for the chorus  
    chorus("Four", "three");
    chorus("Three", "two");
    chorus("Two", "one");
    FiveLittleDuck();       // verse
    
    return 0;
}