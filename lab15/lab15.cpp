/* Created by: Jisook Kim
 * Created on: 10/24/2016 
 * 4.1 Lab - Single Dimensional Arrays
 * Your menu must have 10 different items for the user to choose from. 
 * The program should allow the user to choose an item until they say they are done.
 */
 
 // Requirements: Use an array to hold how many of each item a user requests.
 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userIn[99]; // able to 99 quantities for each item

    int menuNum = 0;
    int count = 0;

    string menu[10]; 
    menu [0] = {"Cappuccino"};
    menu [1] = {"Espresso"};
    menu [2] = {"Cafe Mocha"}; 
    menu [3] = {"Cafe Latte"};                  
    menu [4] = {"Hot Chocolate"};                    
    menu [5] = {"Muffin"};                      
    menu [6] = {"Frappuccino"};                     
    menu [7] = {"Orange Juice"};                        
    menu [8] = {"Herbal tea"};                       
    menu [9] = {"Croissant"};                    
    
    // display 10 items in the menu
    for(int i=0; i < 10; i++)
        cout << i+1 << ": " << menu[i] << endl;

    // let a user choose the menu number
    cout << endl << "What would like to eat?(1-10) (Enter negative number to end the order)." << endl;
    cin >> menuNum;
    
    while(menuNum > 0)
    {
        cout << "How many?" << endl;
        cin >> count;

        for(int i=0; i < count; i++)
        {
            userIn[i] = menu[menuNum-1]; // store items in the user's array
            cout << userIn[i] << endl;  // display item based on how many items a user request
        }
        
        cout << endl << "What would like to eat?(1-10) (Enter negative number to end)." << endl;
        cin >> menuNum;
    }


    return 0;
}