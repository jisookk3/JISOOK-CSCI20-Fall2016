/* Created by: Jisook Kim
 * Created on: 10/8/2016 
 * Last modified on: 10/10/2016
 * lab #12 - Nested if and switch case
 * [overview]: create a getting to know you flowchart similar to the "What animal are you?" one we did in class.
 * use a nested if and a switch case to recreate the flow chart
 */
 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char answer;
    
    cout << "Do you like the outdoor? (Y/N): " << endl;
    cin >> answer;

    if((answer == 'y') || (answer == 'Y'))
    {
        cout << " Do you like to run? (Y/N): " << endl;
        cin >> answer;
        switch(answer)
        {
            case 'y':
            case 'Y':
                cout << "You are a horse!" << endl;
                break;
            case 'n':
            case 'N':
                cout << "You are a turtle!" << endl;
                break;
            default:
                cout << "Invalid input! Enter 'Y' or 'N' " << endl;
        }   // end switch
    }   // end if
    
    else if((answer=='N')||(answer=='n'))
    {
        cout << "Do you like cheese? (Y/N):" << endl;
        cin >> answer;
        switch(answer)
        {
            case 'y':
            case 'Y':
                cout << "You are a mouse!" << endl;
                break;
            case 'n':
            case 'N':
                cout << "Do you like to swim?" << endl;
                cin >> answer;
                // need more y / n
                if((answer == 'y') || (answer == 'Y'))
                {
                    cout << "You are a fish!" << endl;
                    break;
                }
                else if((answer=='N')||(answer=='n'))
                {
                    cout << "You are a cat!" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid input! Enter 'Y' or 'N' " << endl;
                    break;
                }
                
            default:
                cout << "Invalid input! Enter 'Y' or 'N' " << endl;
        } // end switch
    } // end else if (answer NO)
    
    else
        cout << "Invalid input! Enter 'Y' or 'N' " << endl;

    

    return 0;
}