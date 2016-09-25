// 2.3 Lab - Return Values
// Created by: Jisook Kim
// Created on: Sep 24 2016 
/* Problem Statement: Create a program that converts pounds to kilograms and kilograms to pounds.  
User should first enter Kilograms and then pounds.*/

#include <iostream>
#include <string>       
using namespace std;

// definition of global variables and constant variables
// global variables' scope extends after the definition to the file's end, and reaches into functions. (scope all functions)
const double KG_PER_POUND = 0.453592;   // 1pound = 0.453592 kg
const double POUND_PER_KG = 2.20462;    // 1kg = 2.20462 pound

// function declaration: enables calls to the function before the function definition.
double ToKilo(double poundUser);    
double ToPounds(double kgUser);     

int main()
{
    double kg = 0.0;        // scope limited inside main function (line22-31)
    double pound = 0.0;     // scope limited inside main function (line23-37)
    double kgResult = 0.0;      // scope limited inside main function (line24-31)
    double poundResult = 0.0;   // scope limited inside main function (line25-37)
    
    cout << "Enter kilograms: ";
    cin >> kg;
    
    kgResult = ToPounds(kg);
    cout << kg << " kilograms is converted to "<< kgResult << " pound" << endl;
    
    cout << "Enter pounds: ";
    cin >> pound;
    
    poundResult = ToKilo(pound);
    cout << pound << " pounds is converted to " << poundResult << " kg" << endl;
    
    return 0;
}


// function converted pound to kg
double ToKilo(double poundUser)     // poundUser's scope limited inside the function (line44-47)
{
    double kilo = 0.0;      // varialbes(kilo and poundUser) scope limited inside the "ToKilo" function (line46-48)
    kilo = poundUser * KG_PER_POUND;    
    return kilo;        
}

// function convertd kg to pound
double ToPounds(double kgUser)      // kgUser's scope limited inside the function (line52-55)
{
    double pound = 0.0;     // varialbes(pound and kgUser) scope limited inside the "ToPounds" function (line54-56)
    pound = kgUser * POUND_PER_KG;   
    return pound;
}