

#include <iostream>
//#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H


class Database
{
public:
	Database(); // constructor

	void SetName(string n);
	void SetStnum(int num);
	void SetGrade();
	void print();

	double totalGrade(double attendance, double quiz, double assignment, double finalExam);

	string GetName();
	int GetStnum();
	double GetSumgrade();
	char GetGrade(); 


private:
	string name;
	int stnum;
	double sumgrade; // 아마 필요하지 않을껄?!
	char grade; // A,B,C,D,F  // 너도 아마 필요하지 않을껄?!
};

#endif