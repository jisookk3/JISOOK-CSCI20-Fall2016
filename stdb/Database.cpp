
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Database.h"
using namespace std;

Database::Database()	// constructor
	: name(""), stnum(0), sumgrade(0.0), grade('\0')
{
}

void Database::SetName(string n) {
	name = n;
}

void Database::SetStnum(int num) {
	stnum = num;
}


void Database::SetGrade() {
	if (sumgrade >= 90 && sumgrade <= 100)
		grade = 'A';
	else if (sumgrade >= 80)
		grade = 'B';
	else if (sumgrade >= 70)
		grade = 'C';
	else if (sumgrade >= 60)
		grade = 'D';
	else
		grade = 'F';
}

void Database::print() {

	cout << " " << setw(18) << left << GetName() << "| "
		<< setw(7) << left << GetStnum() << "| "
		<< setw(7) << left << GetSumgrade() << "| "
		<< setw(7) << left << GetGrade() << endl;

	//cout << "Name: " << GetName() << " | ID: " << GetStnum() << " | Sum_grade: " << GetSumgrade() << " | GPA: " << GetGPA() << endl;
}

double Database::totalGrade(double attendance, double quiz, double assignment, double finalExam) // att 10%, quiz 20%, ass 50%, final 20%
{
	sumgrade = attendance*0.1 + quiz*0.2 + assignment*0.5 + finalExam*0.2;
	SetGrade();
	return sumgrade;
}


string Database::GetName() {
	return name;
}

int Database::GetStnum() {
	return stnum;
}

double Database::GetSumgrade() {
	return sumgrade;
}

char Database::GetGrade() {
	return grade;
}

