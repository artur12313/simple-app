#pragma once

#include "student.h"


#include <iomanip>
#include <Windows.h>

using namespace std;

ostream& operator<<(ostream& o, const student& s)
{
	o << setiosflags(ios::left) << setw(10) << s.number
		<< resetiosflags(ios::left) << setw(10) << s.name
		<< setw(20) << s.surname
		<< resetiosflags(ios::left) << setw(10) << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(2) << s.average
		<< resetiosflags(ios::right) << setw(20) << s.dateAdd
		<< resetiosflags(ios::right) << setw(20) << s.dateEdit
		<< "\n";

	return o;
}

void student::now(char* inscription)
{
	SYSTEMTIME s;
	GetLocalTime(&s);

	char str[10];

	_ultoa_s(s.wYear, str, 10);
	strcpy_s(inscription, 50, str);
	strcat_s(inscription, 50, "-");

	_ultoa_s(s.wMonth, str, 10);
	strcat_s(inscription, 50, str);
	strcat_s(inscription, 50, "-");

	_ultoa_s(s.wDay, str, 10);
	strcat_s(inscription, 50, str);
	strcat_s(inscription, 50, "-");

	_ultoa_s(s.wHour, str, 10);
	strcat_s(inscription, 50, str);
	strcat_s(inscription, 50, ":");

	_ultoa_s(s.wMinute, str, 10);
	strcat_s(inscription, 50, str);
	strcat_s(inscription, 50, ":");

	_ultoa_s(s.wSecond, str, 10);
	strcat_s(inscription, 50, str);

}

void student::head(ostream& o)
{
	o << setiosflags(ios::left) << setw(10) << "Number"
		<< resetiosflags(ios::left) << setw(10) << "Name"
		<< setw(20) << "Surname"
		<< resetiosflags(ios::left) << setw(10) << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(2) << "Average"
		<< resetiosflags(ios::right) << setw(20) << "Date Add"
		<< resetiosflags(ios::right) << setw(20) << "Date Edit"
		<< "\n";

	o << setiosflags(ios::left) << setw(10) << "-------"
		<< resetiosflags(ios::left) << setw(10) << "------"
		<< setw(20) << "----------"
		<< resetiosflags(ios::left) << setw(10) << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(2) << "-------"
		<< resetiosflags(ios::right) << setw(20) << "-------------------"
		<< resetiosflags(ios::right) << setw(20) << "-------------------"
		<< "\n";
}