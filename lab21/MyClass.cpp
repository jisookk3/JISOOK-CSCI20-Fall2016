
// function definition


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "MyClass.h"



MyClass::MyClass() : num_(0) {}

void MyClass::Output() {
  cout << "My number is: " << num_ << endl;
}


