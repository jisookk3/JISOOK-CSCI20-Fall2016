/* Created by: Jisook Kim
 * Created on: 10/3/2016 
 * 3.1 Lab - Relational and Conditional 
 * overview: Boolean and logical operators   9 problems
 */
 
 #include <iostream>
using namespace std;

int main()
{
    int suzyAge = 25;
    int johnAge = 21;
    
    int x = 7;
    int y = 7;
    
    int a = 1;
    int b = 9;
    
    int limit = 20;
    int count = 10;
    
    int t = -4;
    int z = 0;
    
    int variable = -5;
    int c = 16;
    
    int d = -2;
    int f = 5;
    
    int j = -2;
    int k = 5;
    int l = 4;
    
    cout << endl << "1.suzyAge = 25; johnAge = 21; suzyAge  < johnAge; " << endl;
    cout << "The output is " << (suzyAge < johnAge) << " FALSE" << endl << endl;
    
    cout << "2. x = 7; y = 7; x >= y; " << endl;
    cout << "The output is " << (x >= y) << " TRUE" << endl << endl;
    
    cout << "3. a = 1; b = 9; a == b; " << endl;
    cout << "The output is " << (a == b) << " FALSE" << endl << endl;
    
    cout << "4. limit = 20; count = 10; ((limit * count)/2 > 0);" << endl;
    cout << "The output is " << ((limit*count)/2 > 0) << " TRUE" << endl << endl;
    
    cout << "5. t = -4; z = 0; (t > 5 || z < 2);" << endl;
    cout << "The output is " << (t>5 || z<2) << " TRUE" << endl << endl;
    
    cout << "6. variable = -5; (!(variable > 0));" << endl;
    cout << "The output is " << (!(variable > 0)) << " TRUE" << endl << endl;
    
    cout << "7. c = 16; (c/4 < 8 && c >=4);" << endl;
    cout << "The output is " << (c/4 < 8 && c >=4) << " TRUE" << endl << endl;  
    
    cout << "8. d = -2; f = 5; (d*f < 10 || f*z < 10);" << endl;
    cout << "The output is " << (d*f < 10 || f*z < 10) << " TRUE" << endl << endl;  
    
    cout << "9. j = -2; k = 5; l = 4; (!(j*l<10) || y/x * 4 < y * 2);" << endl;
    cout << "The output is " << (!(j*l<10) || y/x * 4 < y * 2) << " TRUE" << endl << endl;  

    return 0;
}


