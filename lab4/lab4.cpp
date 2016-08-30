// 1.3 Lab - Mad Libs
// Created by: Jisook Kim
// Created on: Aug 29 2016

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Random_num, Favorite_num;
    float Decimal;
    char Alphabet;
    string Adjective, Noun, Plural_noun, Verb_ED, Place;
    
    cout << endl << " This is about An Old Woman Mad Lib." << endl << endl;
    
    cout << "1. Please enter the number: ";
    cin >> Random_num;
    cout << "2. What is your favorite number?: ";
    cin >> Favorite_num;
    
    cout << "3. Please enter the decimal number: ";
    cin >> Decimal;
    
    cout << "4. What English alphabet do you like the most?: ";
    cin >> Alphabet;
    
    cout << "5. Please enter an adjective you want: ";
    cin >> Adjective;
    cout << "6. Please enter the noun: ";
    cin >> Noun;
    cout << "7. Please enter the plural noun: ";
    cin >> Plural_noun;
    cout << "8. Please enter verb ending in “ED”: ";
    cin >> Verb_ED;
    cout << "9. Please enter the place: ";
    cin >> Place;
    
    cout << endl <<" Here is the Mad lib for you!" << endl << endl;
    
    cout << " There was a " << Adjective << " woman who lived in a " << Place << "." << endl;
    cout << " She spent $" << Random_num << " on purchasing " << Favorite_num << " " << Plural_noun <<" but she didn`t know what to do." << endl;
    cout << " She gave them " << Decimal << " amount of broth she cooked without any " << Noun << "." << endl;
    cout << " Suddenly, she said a magic word" << " '" << Alphabet <<"' " << "in front of them." << endl;
    cout << " In the end, she " << Verb_ED << " them all soundly and put them to bed." << endl;

// Here is the Mad lib for you!

// There was a nice woman who lived in a cave.
// She spent $3 on purchasing 4 bowls but she didn`t know what to do.
// She gave them 3.4 amount of broth she cooked without any book.
// Suddenly, she said a magic word 'A' in front of them.
// In the end, she opened them all soundly and put them to bed.
    
    return 0;
}

