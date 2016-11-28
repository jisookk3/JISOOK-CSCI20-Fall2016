#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "MyClass.h"
#include "lab21.h"

/*
 *  This class is a dummy class to help show how to
 *  break our class into an interface and implementation
 *  file. It will set a member variable to 1 on initialization
 *  and output it using the Output() function.
 */

int randomNumber(){
   srand(time(0));
   return (rand()% 10 + 1);
}

// Program starts here
int main() {
  // Create a MyClass Object
  MyClass object;
  // Call the output member function
  object.Output();
  // This ends our program
  return 0;
}

/*  Take the code below and break it up into the appropriate separate files for compilation. 
    You may create a makefile for 1 point extra credit or just compile by command line.

To run your program you need to following commands in order:

1. Open a terminal from your folder (right click on your folder and open new terminal window)
2. g++ -Wall -g -c lab21.cpp     
    This compiles the file with the main function. 
    If you named it differently, you should change the name from lab21 to your file name
    This should create a file called lab21.o
3. g++ -Wall -g -c MyClass.cpp
    This compiles the class. If you named it differently, you should change the name from MyClass.cpp to your file name
    This should create a file called MyClass.o
4. g++ -Wall -g -o lab21exe lab21.o MyClass.o
    This compiles the two object files into an executable named lab21exe.
5. ./lab21exe
    run this to test that your program works.

*/