/* Created by: Jisook Kim
 * Created on: 10/19/2016 
 * Program 3 - Program Flow: Number Guessing Game
 * Overview: The computer will choose a random number between two numbers chosen by the user. 
 * The user enters a number and is told “higher”, “lower”, or “winner” based on their guess and the computer’s number.  
 * The game should continue until the user guesses the correct number.  
 * The program should score the game based on how many guesses it takes to get the number.
 *
 * My algorithm was approved on 10/19.
 */
 
#include <iostream>
#include <cstdlib> //enable use of rand()
#include <ctime> //enable use of time()
using namespace std;

// class declaration
class GuessNumber
{
private:
	int random;
	int userIn;

public:
	GuessNumber();	// default constructor
	GuessNumber(int testNum);
	int RandomGenerator();
	void SetNum(int user);
	int GetNum();
};

GuessNumber::GuessNumber()
{
	userIn = 0;
}

GuessNumber::GuessNumber(int testNum)
{
	userIn = testNum;	
	// ADD: initialize all private variables
}

void GuessNumber::SetNum(int user)
{
	userIn = user;
}

int GuessNumber::GetNum()
{
	return userIn;
}

int GuessNumber::RandomGenerator()
{
	int min, max;
	cout << "Enter MINIMUM value to generate a random value:";
	cin >> min;
	cout << "Enter MAXIMUM value to generate a random value:";
	cin >> max;

	srand(time(0));

	random = (rand() % max) + min;	//range min - max for the random value
	return random;
}


int main()
{
	int score = 0;
	int chance = 0;
	int randomVal = 0;
	int userVal = 0;
	
    GuessNumber game1;	// default constructor
    cout << game1.GetNum() << endl;
    
	GuessNumber test(33);	//contructor overloaded
	cout << test.GetNum() << endl;

	game1.SetNum(1);
	cout << game1.GetNum() << endl;

	randomVal = game1.RandomGenerator();	// random generator based on min/max from a user
	//cout << "Random value: "<< randomVal << endl; // checking random value
	
	// Begin the game - number guessing
	score = 100;    //set the score
	cout << endl <<  "You have 10 tries to guess the number. The score starts at 100." << endl;
    
    // 10 tries to guess the number
	for (chance = 1; chance <= 10; chance++) {
		cout << endl << "You are on guess " << chance << " of 10" << endl;

		cout << "Enter the number you guess:";
		cin >> userVal;
		game1.SetNum(userVal);
		cout << "You entered " << game1.GetNum() << endl;

		if (userVal == randomVal)
		{
			cout << "You WIN! Your score: " << score << endl;
			break;
		}

		else if (userVal > randomVal)
		{
			cout << "Higher!" << endl;
			score = score - 10;
		}

		else
		{
			cout << "Lower!" << endl;
			score = score - 10;
		}	
	} // end for
	
    if(chance == 11)    // after the for loop, it means losing the game. so chance is 11 
	cout << endl << "You LOST! The correct number was " << randomVal << endl;
	
}
 
 /*
 0. set the score = 100
 1. input two numbers from a user input (range of min and max)
 2. generate a random number based on the range of the user input
 3. give the user 10 chances to guess the number (count variable needed)
 4. use a for loop to count 10 tries
 5. if(random number < user number) then print "higher" and score-10
 6. if(random > user ) then print "lower" and score-10
 7. count++ every time the user tries
 8. in a for loop, if (random number == user number) then print out "winner" and score and then break the (for) loop
 9. if(count > 10 tries) then print "you have lost the game" and show the correct number
 */
 