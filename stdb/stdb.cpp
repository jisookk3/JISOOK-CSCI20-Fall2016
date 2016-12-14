
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "Database.h"
using namespace std;

void edit(Database student[], int stID, int personN);
int search(Database student[], int personN);
void sort(Database student[], int personN);
void fileout(Database student[], int personN, double average);
void firstline();
void pressAny();


/////// MAIN /////////
int main()
{
    ifstream inF;
    stringstream ss;	// for the conversion string to int
    string filename = ""; 
	string data = "";

	char input = '\0';	//selection for a menu
	int person = 0; // how many students entered
	int i = 0;
	int searchID = 0;
	int tempNum = 0;
	string tempName ="";
	double att, qz, hw, fn;
	double average = 0.0;
	
	Database student3; // constructor
	Database student[30]; // max 30 students

	cout << "\nEnter filename to open student grade input: ";	
	cin >> filename;
	inF.open(filename.c_str());

	// make sure file exists
	if (!inF.is_open()) {
		cout << "Could not open file" << filename << endl;
		return 1;
	}

	// read input textfile and store each item to Class Database student[30]
	// extract data from grade.txt and store them to student[]
	while (!inF.eof())
	{
		getline(inF, data, ' ');
		tempName = data;
		getline(inF, data, ' ');
		tempName = tempName + " " + data;
		student[i].SetName(tempName);	// save name

		getline(inF, data, ' ');
		ss.str(data);
		ss >> tempNum;	// convert string to int
		
		// tempNum = stoi(data.c_str());	// save student ID 
		student[i].SetStnum(tempNum);
		ss.clear();	// clear buffer for the next execution

		getline(inF, data, ' ');	// atof() used because stod() does NOT work in C9 for some reason
		att = atof(data.c_str());		// attendance

		getline(inF, data, ' ');
		qz = atof(data.c_str());	// quiz

		getline(inF, data, ' ');
		hw = atof(data.c_str());	// assignment

		getline(inF, data);
		fn = atof(data.c_str());	// final exam

		student[i].totalGrade(att, qz, hw, fn);

		i++;
	}
	person = i; // store how many students
	
	// Done with file, close it
	inF.close();

	// get average of the class
	for (int i = 0; i < person; i++) {
		average += student[i].GetSumgrade();
	}
	average = average / person;

	cout.precision(2); // 2 decimals representation
	cout << fixed;

// print data from a textfile
/*	firstline();
	for (int i = 0; i < person; i++) {
		student[i].print();
	}
	cout << "\n Total: " << person << " students\n";
	cout << " Average: " << average << endl << endl;
*/

////// MAIN MENU OPTION ///////
	while (input != 'q')
	{
		cout << "\n === Student Grade Management ===\n";
		cout << " 1. Edit \n";
		cout << " 2. Search (by ID)\n"; 
		cout << " 3. Sort (by ID or Grade)\n";
		cout << " 4. Print\n";
		cout << " 5. Export to txt file\n";
		cout << " (Press 'q' to end the program)\n";
		cout << "==================================\n\n";
		cout << " Your choice (1-5): ";
		cin >> input;
	
		// Select menu number
		switch (input)
		{
		case '1':	// 1. Edit
			system("clear");
			cout << "\n\n [ EDIT Student Info ]\n\n";
			searchID = search(student, person);
			edit(student, searchID, person);
			break;

		case '2':	// 2. Search (by ID)
			system("clear");
			cout << "\n\n [ SEARCH Student Info ]\n\n";			
			search(student, person);
			pressAny();
			break;

		case '3': // 3. Sort
			system("clear");		
			cout << "\n\n [ SORT Student Info ]\n\n";			
			sort(student, person);
			pressAny();
			break;

		case '4':	// 4. Print
			firstline();
			for (int i = 0; i < person; i++) {
				student[i].print();
			}
			cout << "\n Total: " << person << " students\n";
			cout << " Average: " << average << endl << endl;
			pressAny();
			break;

		case '5': // 5. Output to txt file
			cout << "\nWriting a \"gradeResult.txt\"... \n";
			cout << " . . . ";
			fileout(student, person, average);
			cout << "\nDone! Open the file \"gradeResult.txt\"" << endl;
			pressAny();
			break;

		case 'q':
		case 'Q':
			cout << "\n     End of program! Bye! \n\n";
			input = 'q';
			break;

		default:
			system("clear");
			cout << "\n Error, invalid input! \n";
			break;
		} // end switch
	}// end while until quit...


	return 0;
}


// 1. EDIT student ID or grade
void edit(Database student[], int stID, int personN)
{
	int choice = 0;
	int id = 0;
	int check = 0;
	double att_, qz_, hw_, fn_;

	// select what to edit
	cout << "\n 1.ID  2.Grade \n";
	cout << "Select what you want to change(1-2): ";
	cin >> choice;

	// 1. Edit ID
	if (choice == 1) 
	{
		cout << "\n Let's edit a student ID! \n";
	
		// check the same ID
		while (check == 0)
		{
			cout << "Enter new ID to change: ";
			cin >> id;

			for (int i = 0; i < personN; i++)
			{	// max 30 students
				if (student[i].GetStnum() == id) // if found the same ID, re-enter. Go back to Enter ID
				{
					check = 0;
					cout << "There exists the same ID. Re-";
					break;
				}
				check = 1; // if not found the same ID, get out of Enter ID
			}// end for
		} // end while // end checking the same ID

		student[stID].SetStnum(id); // store entered ID
	} // end Edit ID
	
	// 2. Edit grade
	else if (choice == 2) 
	{
		cout << "\n Let's edit the grade! \n";
		cout << "\n [Grade Percentage]";
		cout << "\n Attendance(10%), Quiz(20%), Assignment(50%), Final exam(20%) \n\n";

		cout << "Enter Attendance(0-100%): ";
		cin >> att_;
		cout << "Enter Quiz(0-100%): ";
		cin >> qz_;
		cout << "Enter Assignment(0-100%): ";
		cin >> hw_;
		cout << "Enter Final exam(0-100%): ";
		cin >> fn_;

		student[stID].totalGrade(att_, qz_, hw_, fn_); // store entered grade
	}
	
	else
		cout << "\nYou entered wrong number!\n";

	// updated info output after change
	cout << "\n::::: Updated Info :::::";
	firstline();
	student[stID].print();

	pressAny();
}


// 2. SEARCH a student by ID
int search(Database student[], int personN)
{
	int i, stPosition;
	int check = 0;
	int id;

	while (check == 0)
	{
		cout << "Enter student ID(starts 3000): ";
		cin >> id;

		for (i = 0; i < personN; i++)
		{	// max 30 students
			if (student[i].GetStnum() == id)
			{
				stPosition = i;
				check = 1;
				break;
			}
		}
		if (check == 0) cout << "Not found. Re-";
	} // end while

	cout << "\n\n::::: Current Student Info :::::";
	firstline();
	student[stPosition].print();

	return stPosition; //return the position(ID) a use is searching for
}


// 3. SORT by GRADE or ID
void sort(Database student[], int personN)
{
	int choiceS;
	int i, j = 0;
	double average = 0.0;
	
	Database studentTemp[1];

	// select what to sort
	cout << "\nSORT BY\n";
	cout << "1.ID    2.Grade \n\n";
	cout << "Your choice (1-2): ";
	cin >> choiceS;

	if (choiceS == 1)
	{
		cout << " \n========= Sort by ID =========\n";
		for (i = 0; i < personN; i++)
		{
			for (j = i + 1; j < personN; j++)
			{
				if (student[i].GetStnum() > student[j].GetStnum())
				{	// if found smaller number, switch. The smallest one goes to the front.
					studentTemp[0] = student[j];
					student[j] = student[i];
					student[i] = studentTemp[0];
				}
			}
		}
	} // end SORT by ID

	else if (choiceS == 2)
	{
		cout << " \n========= Sort by Grade =========\n";
		for (i = 0; i < personN; i++)
		{
			for (j = i + 1; j < personN; j++)
			{
				if (student[i].GetSumgrade() < student[j].GetSumgrade())
				{	// if found larger number, switch. The largest one goes to the front.
					studentTemp[0] = student[j];
					student[j] = student[i];
					student[i] = studentTemp[0];
				}
			}
		}
	} // end SORT by grade

	// result after sort
	cout.precision(2);
	firstline();
	for (i = 0; i < personN; i++) {
		student[i].print();
		average += student[i].GetSumgrade();
	}
	cout << "\n Total: " << personN << " students\n";
	cout << fixed << " Average: " << average/personN << endl << endl;
}


// 4. WRITE to TXT FILE
void fileout(Database student[], int personN, double average)
{
	ofstream outF;
	outF.open("gradeResult.txt");

	// first line for item names
	outF << "\n\n   [ Student Grade Result ] \n"
		<< " _________________________________________________" << endl
		<< " " << setw(3) << "No." << "| " 
		<< setw(18) << left << "Name" << "| "
		<< setw(7) << left << "ID" << "| "
		<< setw(7) << left << "Total" << "| "
		<< setw(2) << left << "Grade" << endl
		<< " _________________________________________________" << endl;

	outF.precision(2); // 2 decimals representation
	outF << fixed;

	// write info to file
	for (int i = 0; i < personN; i++) 
	{
		outF << " " << setw(3) << i+1 << "| ";
		outF << setw(18) << left << student[i].GetName() << "| "
			<< setw(7) << left << student[i].GetStnum() << "| "
			<< setw(7) << left << student[i].GetSumgrade() << "| "
			<< setw(2) << left << student[i].GetGrade() << endl;
	}
	outF << " _______________________________________________" << endl;

	outF << "\n Total: " << personN << " students\n";
	outF << " Grade Average: " << average << endl << endl;

	outF.close();

	return;
}

// item names of the grade table
void firstline()
{
	cout << "\n   [ Student Grade DataBase ] \n";
	cout << " " << setw(18) << left << "Name" << "| "
		<< setw(7) << left << "ID" << "| "
		<< setw(7) << left << "Total" << "| "
		<< setw(7) << left << "Grade" << endl
		<< " -------------------------------------------\n";
}

// hang on until pressing any key
void pressAny()
{
	char anykey = '\0';
	cout << "\n\n     Press ANY KEY to continue  ";
	cin >> anykey;
	system("clear");
}



