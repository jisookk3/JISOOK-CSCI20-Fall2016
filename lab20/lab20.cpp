/* Created by: Jisook Kim
 * Created on: 11/21/2016
 * 5.1 Lab - Pointers
 *  comment it to demonstrate that you understand what it is doing.
 */
 
#include <iostream>
#include <cstring>  // strlen() defined
using namespace std;

int main()
{
    char firststr[10];  // the array that can store less than 10 letter word (0-9)
    int firstname = 0;  // to store length of input 
    char *head = firststr;  // the pointer head pointing to the array firststr
    char *tail = firststr;  // the pointer tail pointing to the array firststr as well
    cout << "Please enter a 10 letter word or less" << endl; // prompt a user
    cin >> firststr;    // storing user input to firststr
    strlen(firststr);   // get the length of user input string
    firstname = strlen(firststr);   // move the length of string to variable firstname
    cout << "Your word is " << firststr << endl;    // showing the user input
    
    // print out the input word until the end of word
    if (firstname<10)   // if firstname(length of word) is less than 10 characters, (it's safe to store)
    {
        while (*head != '\0')   // keep the loop as long as (dereference array firststr) the value of firststr[] is not a null character
        {
            cout << *head;  // print the value of firststr[0] // dereference firststr[0]
            head++; // jump to the next character, fiststr[0] -> firststr[1] // changing where the pointer is pointing to by incresing one
        } // print each character until the end of it
    }
    else    // if the length of input is more than or equal to 10 characters,
    {
        cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;    // warning that too big size words entered
    }
    cout << endl;
    
    tail = &firststr[strlen(firststr) - 1]; // pointer tail contains the memory address of last character location of firststr[]
                                            // In other words, tail is pointing to the last character of user input
                                        // ex) if the length of firststr[10] is 5, the last element is in firststr[5-1] because array index starts 0.
    
    if (firstname < 10) // if the letter is less than 10 characters // make sure the right length for the array
    {
        while (*tail>0) // keep the loop as long as the value tail is pointing to is more than 0
        {
            cout << *tail;  // print the character the pointer tail is pointing to // print the last character in the array
            tail--; // move on the location of array element backwards by decreasing one // ex) firststr[5] -> firststr[4] 
        } // while loop: print the letter backwards // ex) apple(input) -> elppa
    }
    cout << endl;
    
    head = firststr;    // the pointer head is pointing to array firststr // storing the address of array firststr
    tail = &firststr[strlen(firststr) - 1]; // same as above (line38) // pointing to the last character of firststr[]
    head++; // the pointer head moving on the next character forward // ex) firststr[0] -> firststr[1]
    tail--; // the pointer tail moving on the next character backwards // ex) firststr[5] -> firststr[4]
 
    if (*head == *tail) // if the second letter is equal to the letter of second to last
    {                   // ex) if the length of letter is 5, there are 5 elements in the array like from firststr[0] to firststr[4]
                        // Hence, if (*head == *tail) means if (firststr[1] == firststr[3])
        cout << "It is an palindrome!" << endl;
    }
 
    else
    {
        cout << "It is not an palindrome" << endl;
    }
 
    return 0;
}

// Actually, this program doesn't find the real palindrome. Because they are comparing only the second character with second to last.
// It should be checking each character  ex) if(array[0] == array[4])   if(array[1] == array[3]).....