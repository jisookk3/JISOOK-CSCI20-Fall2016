/* Created by: Jisook Kim
 * Created on: 10/17/2016 
 * 3.5 Lab - Debugging
 * [overview]:  submit your fixed program and a write up on how you went about debugging the program.  
 * In this write up you will discuss what techniques you used to find the bugs and how you debugged them.
 */
 
// Grade Average
// Read in a series of grades, terminated by a -1.// 
// Then output the average and minimum of those grades.

// Correct output
// 97 92 86 91 -1
// Average was 91.5
// Minimum was 86

// *** My techniques: run and see the result -> fix one error(wrong result) -> run and check the result -> fix the next error....
// My techique of debugging is progressive to fix the error.
//First I ran the program and see the result. There is no out put so I looked for cout near cin.
// I added cout and then found 
// I found the wrong average value without the decimal point. I took a look at the part of summing grades and output the sum. 
// Debugging sum output and run it again. Found the wrong minimum value. Looked up minimum condition and fixed it.


/* Below: each specific process to debug */

// no cout, so unable to get input -> It seems to run program with no issue but doesn't move on the next code
// so I added   cout << "Enter grade (enter -1 to exit): " << endl;
// And before while loop, 
// when grade = -1 -> need to change condition in while loop

// In order to fix decimal value for the average, declaring variable and assigning variables should be separate
// I added     double average = 0.0;

// I set the comparison value before compare two values to find minimum in while loop
// I added      minimum = grade;

#include <iostream> 
using namespace std; 

int main() 
{        
    // Declare variables        
    int count=0;        
    double total=0.0;        
    double minimum=0.0;        
    double grade=0.0;  
    double average = 0.0;   // I added to declare a double variable
    
    cout << "Enter grade (enter -1 to exit): " << endl;
    cin >> grade; 
    
    minimum = grade;    // set the comparison value before compare in while loop
    
    // Read numbers in until we see the -1        
    // Sum up grades as we do, and look for minimum        
    while (grade != -1) 
    {         
        total = total + grade;     // sum grades          
        count = count + 1;   

        if (grade < minimum) {                      
            minimum = grade;               
            }   
        cout << "Enter grade (enter -1 to exit): " << endl;
        cin >> grade; 
    }   
    
    // Output results        
    average = total / count;        
    cout << "Average was " << average << endl;       
    cout << "Minimum was " << minimum << endl;         
    
    return 0;
}

/* original program
int main() 
{        
    // Declare variables        
    int count=0;        
    int total=0;        
    int minimum=0;        
    int grade=0;       
    
    // Read numbers in until we see the -1        
    // Sum up grades as we do, and look for minimum        
    while (grade != -1) {               
    cin >> grade;               
    total = total + grade;     // sum grades          
    count = count + 1;                
    if (grade < minimum) {                      
         minimum = grade;               
        }        
    }   
    
    // Output results        
    double average = total / count;        
    cout << "Average was " << average << endl;       
    cout << "Minimum was " << minimum << endl;         
    
    return 0;
}
*/