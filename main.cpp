#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"
using namespace std;


int main() {

	system("color 1e");


	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jane,Smith,esdcat@yahoo.com,31,15,30,45,SOFTWARE"
	};

	int allStudents = 5;

	Roster* classRoster = new Roster(allStudents);


	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "Program compiled in C++" << endl;
	cout << "Student ID: 01234567" << endl;
	cout << "Student Name: Student Name" << endl;
	cout << endl;

	for (int i = 0; i < allStudents; i++) {
		classRoster->parseAndAdd(studentData[i]);
	}

	cout << "Student Roster:" << endl;
	classRoster->printAll();
	cout << endl;


	cout << "Invalid Emails:" << endl;
	classRoster->printInvalidEmails();
	cout << endl;


	cout << "Average number of days to complete courses:" << endl;
	for (int i = 0; i < allStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}
	cout << endl;


	cout << "Students currently earning a software degree: " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;


	classRoster->remove("A3");
	cout << endl;


	classRoster->printAll();
	cout << endl;


	classRoster->remove("A3");
	cout << endl;


	system("pause");

	return 0;
}