/* Created by: Jisook Kim
 * Created on: 10/31/2016 
 * 4.2 Lab - Parallel Arrays
 * Include prices for your items and an inventory
 * As the user purchases an item, add the price to the total and subtract 1 from the inventory. Output a total cost when they are done shopping.
 */
 
#include <iostream>
#include <string>
using namespace std;

int main()
{   
    // price for 10 items
    float price[10] = {2.75, 2.25, 3.25, 3.05, 3.15, 2.50, 4.15, 3.10, 2.10, 2.99};
    int inventory[10];  // inventory array for 10 items
    int inven = 20;  // 20 identical inventory for each item
    
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
    float total = 0.0;  // total cost
    
    cout.precision(2);
    // display 10 items in the menu
    for(int i=0; i<10; i++)
        cout << i+1 << ": " << menu[i] << fixed << "  $" << price[i] << endl;
        
    // inventory created
    for(int j=0; j<10; j++)
        inventory[j] = inven;   // inventory: identical inventory for each item
    
    /* output inventory 
    cout << "Inventory" << endl;
    for(int i=0; i<10; i++)
        cout << i+1 << ": " << inventory[i] << endl;    
   */     
    // let a user choose the menu number
    cout << endl << "Choose the item(1-10)  [Enter 0 to end the order]: ";
    cin >> num;
    
    while(num != 0)
    {
        cart[count] = menu[num-1];    // store the item a user requests into the user's array 
        count++;    // for the next item order
       
        cout << menu[num-1] << fixed << "  $" << price[num-1] << "   Inventory: " << inventory[num-1] << endl;
        inventory[num-1] -= 1;  // subtract 1 from the inventory
        total += price[num-1];  // calculate total cost
        
        cout << endl << "Choose the item(1-10)  [Enter 0 to end the order]: ";
        cin >> num;
    }
    
    // print all items a user ordered    
    cout << endl << "Your have ordered " << endl;
    
    for(int k=0; k<count; k++)
        cout<< cart[k] << endl;
        
    // output the total cost
    cout << "Total cost: $" << fixed << total;
        
        
    return 0;
}