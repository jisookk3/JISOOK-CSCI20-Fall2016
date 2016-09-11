// 1.5 Lab - Monster Objects
// Created by: Jisook Kim
// Created on: Sep 10 2016

#include <iostream>
#include <string>       // "string" data type - library
using namespace std;

// Create a MonsterStruct struct and 4 monster objects.

struct MonsterStruct
{	
	string head;    // subitems for a monster
	string eyes;
	string ears;
	string nose;
	string mouth;
};

int main()
{
	MonsterStruct monsterOne;	// 4 Monster objects - variables
	MonsterStruct monsterTwo;
	MonsterStruct monsterThree;
	MonsterStruct monsterFour;
	
	cout << endl << "1. Choose the Monster's head (Zombus, Spritem, Vegitas, Wackus): " << endl;    // input subitems of Monster One from a user
	cin >> monsterOne.head;
	cout << "2. Choose the Monster's eyes (Zombus, Spritem, Vegitas, Wackus): " << endl;
	cin >> monsterOne.eyes;
	cout << "3. Choose the Monster's ears (Zombus, Spritem, Vegitas, Wackus): " << endl;
	cin >> monsterOne.ears;
	cout << "4. Choose the Monster's nose (Zombus, Spritem, Vegitas, Wackus, None): " << endl;
	cin >> monsterOne.nose;
	cout << "5. Choose the Monster's mouth (Zombus, Spritem, Vegitas, Wackus): " << endl;
	cin >> monsterOne.mouth;

	monsterTwo.head = "Spritem";	// Monster Two
	monsterTwo.eyes = "Vegitas";
	monsterTwo.ears = "Wackus";
	monsterTwo.nose = "Wackus";
	monsterTwo.mouth = "Zombus";

	monsterThree.head = "Zombus";	// Monster Three
	monsterThree.eyes = "Vegitas";
	monsterThree.ears = "Vegitas";
	monsterThree.nose = "None";
	monsterThree.mouth = "Wackus";

	monsterFour.head = "Vegitas";	// Monster Four
	monsterFour.eyes = "Wackus";
	monsterFour.ears = "Spritem";
	monsterFour.nose = "Vegitas";
	monsterFour.mouth = "Wackus";
	
	cout << endl;
	cout << "MonsterOne: " << monsterOne.head << ", " << monsterOne.eyes << ", ";	    // Monster One output
	cout << monsterOne.ears << ", " << monsterOne.nose << ", " << monsterOne.mouth << endl << endl;

	cout << "MonsterTwo: " << monsterTwo.head << ", " << monsterTwo.eyes << ", ";	    // Monster Two output
	cout << monsterTwo.ears << ", " << monsterTwo.nose << ", " << monsterTwo.mouth << endl << endl;

	cout << "MonsterThree: " << monsterThree.head << ", " << monsterThree.eyes << ", ";	    // Monster Three output
	cout << monsterThree.ears << ", " << monsterThree.nose << ", " << monsterThree.mouth << endl << endl;

	cout << "MonsterFour: " << monsterFour.head << ", " << monsterFour.eyes << ", ";    	// Monster Four output
	cout << monsterFour.ears << ", " << monsterFour.nose << ", " << monsterFour.mouth << endl << endl;

	return 0;
}
