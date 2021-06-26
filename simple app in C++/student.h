#pragma once

#include <iostream>

using namespace std;


class student
{
	friend ostream& operator<<(ostream& o, const student& s);
public:
	int number;
	char name[30];
	char surname[50];


	float average;
	char dateAdd[50];
	char dateEdit[50];


	void now(char* inscription);


public:
	void newS() { now(dateAdd); }
	void editS() { now(dateEdit); }

	student()
	{
		number = 0;
		strcpy_s(name, "");
		strcpy_s(surname, "");
		strcpy_s(dateAdd, "");
		strcpy_s(dateEdit, "");

	}

	static void head(ostream& o);

};

