/* Created by: Jisook Kim
 * Created on: 9/27/2016 
 * 2.4 Lab - Functions and Classes
 */
 
#include <iostream>
 using namespace std;

// declaration class TemperatureConverter
class TemperatureConverter {
    
    private:
        double kelvin_;
    
    public:
        TemperatureConverter();     // default constructor
        TemperatureConverter(double kelvinT); // overloading
        
        void SetTempFromKelvin(double kelvinT);  //mutator
        void SetTempFromCelsius(double celsiusT);   //mutator
        void SetTempFromFahrenheit(double fahrenT); //mutator
        
        void PrintTemperatures() const;  //accesor
        
        double GetTempFromKelvin() const;   //accessor
        double GetTempAsCelcius() const;    //accessor
        double GetTempAsFahrenheit() const; //accessor
};

TemperatureConverter::TemperatureConverter(double kelvinT){  // overloading
    kelvin_ = kelvinT;
}

TemperatureConverter::TemperatureConverter(){   // Default constructor
    kelvin_ = 0.0;
}



void TemperatureConverter::SetTempFromCelsius(double celsiusT) {
    kelvin_ = celsiusT + 273.15;    // k = c + 273.15
}

void TemperatureConverter::SetTempFromFahrenheit(double fahrenT) {
    kelvin_ = (5.00 * (fahrenT - 32.00) / 9.00) + 273.15;
            // k = ( 5 * ( f - 32) / 9 ) + 273.15   
}

void TemperatureConverter::SetTempFromKelvin(double kelvinT) {
   kelvin_ = kelvinT; 
}


double TemperatureConverter::GetTempFromKelvin() const {
    return kelvin_;
}

double TemperatureConverter::GetTempAsCelcius() const {
    return kelvin_ - 273.15;
    // c = k - 273.15   // return celsius
}

double TemperatureConverter::GetTempAsFahrenheit() const{
    return (((kelvin_ - 273.15) * 9) / 5 + 32);
    // ((c*9)/5 + 32) //return fahrenheit
}


void TemperatureConverter::PrintTemperatures() const {
     cout << "kelvin value: " << GetTempFromKelvin() << 
     "   Celsius value: " << GetTempAsCelcius() <<
     "   Fahrenheit value: " << GetTempAsFahrenheit() << endl << endl;   // print K, C, F  value
}

 