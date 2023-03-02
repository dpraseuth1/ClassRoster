//
//  main.cpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#include <iostream>
#include "roster.hpp"
using namespace std;

int main(){
    
    cout << "--------------------------------------------" << std::endl;
    cout << "Scripting and Programming Applications C867" << std::endl;
    cout << "Created using C++ by" << std::endl;
    cout << "David Praseuth | Student ID: 010343266" << std::endl;
    cout << "--------------------------------------------" << std::endl;


const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,David,Praseuth,davidrpraseuth@gmail.com,27,12,21,50,SOFTWARE"
};

const int numStudents = 5;

Roster roster;

    cout << "Displaying all students:" << endl;
    roster.printAll();

    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by Degree Program:" << degreeProgramStrings[i] << endl;
        roster.printByDegreeProgram((DegreeProgram)i);

    }

    cout << "Displaying invalid emails:" << endl;
    roster.printInvalidEmails();


    cout << "Displaying average days to finish courses: " << endl;
    for (int i = 0; i < numStudents; i++) roster.printAverageDaysInClass(roster.getStudents()[i]->getID());


    cout << "Removing Student ID : A1" << endl;
    roster.removeID("A1");

    cout << "Removing Student ID : A1" << endl;
    roster.removeID("A1");

    cout << "finished." << endl;
    return 0;
}

