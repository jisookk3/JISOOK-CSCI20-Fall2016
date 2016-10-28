/* Created by: Jisook Kim
 * Created on: 10/24/2016 
 * 4.1 Lab - Single Dimensional Arrays
 * Your menu must have 10 different items for the user to choose from. 
 * The program should allow the user to choose an item until they say they are done.
 * Requirements: Use an array to hold how many of each item a user requests.
 */
 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string menu[10];    // 10 items
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
    string cart[99];    // for a user's array
    int num = 0;    // item a user request
    int count = 0;  // how many of each item

    // display 10 items in the menu
    for(int i=0; i<10; i++)
        cout << i << ":" << menu[i] << endl;
        
    // let a user choose the menu number
    cout << endl << "Choose the item(0-9)  [Enter -1 to end the order]: ";
    cin >> num;
    
    while(num >= 0)
    {
        cart[count] = menu[num];    // store the item a user requests into the user's array 
        count++;    // for the next item order
        cout << "Choose the item(0-9)  [Enter -1 to end the order]: ";
        cin >> num;
    }
    
    // print all items a user ordered    
    cout << endl << "Your have ordered " << endl;
    
    for(int k=0; k<count; k++)
        cout<< cart[k] << endl;
        
    return 0;
}