// class or fuction declaration

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
 public:
  /*
   * Constructor
   * Initialize our member variable num_ to 0
   */
  MyClass();
  /*
   * Output our member variable using cout
   */
  void Output();
 
 private:
  int num_;

    
};


#endif