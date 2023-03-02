//
//  roster.cpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#include "roster.hpp"


void Roster::parse1(string studentData)
{
    DegreeProgram dp = DegreeProgram::SECURITY;
    if(studentData.back() == 'K') dp = DegreeProgram::NETWORK;
    else if(studentData.back() == 'E') dp = DegreeProgram::SOFTWARE;
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",",lhs);
    string email = studentData.substr(lhs , rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    int p[3];
    for (int i = 0; i < 3; i++){
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        p[i] = stoi(studentData.substr(lhs, rhs - lhs));
        
    }
    
    add(studentID, firstName, lastName, email, age, p[0], p[1], p[2], dp);

}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram dp){
    int daysInClassArray[3] = { daysInClass1, daysInClass2, daysInClass3};
    students[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInClassArray, dp);
    cout << "Student added to roster at row " << lastIndex + 1 << endl;
}

void Roster::printAll(){
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++) Roster::students[i]->print();
}
    
//pass in degree program

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
        if (Roster::students[i]->getDegreeProgram() == dp) students[i]->print();
}


//find and display invalid emails

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = Roster::getStudents()[i]->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
            cout << email << " is invalid" << endl;
    }
}

//print student's avg number of days in the 3 courses
void Roster::printAverageDaysInClass(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (students[i]->getID() == studentID)
        {
            cout << studentID << ":";
            cout << (students[i]->getDays()[0] + students[i]->getDays()[1] + students[i]->getDays()[2]) / 3.0 << endl;
        }
    }
}

//remove by student ID
void Roster::removeID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (students[i]->getID() == studentID)
        {
            success = true;
            Student* temp = students[i];
            students[i] = students[numStudents - 1];
            students[numStudents - 1] = temp;
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student ID: " << studentID << "removed." << endl;
        printAll();
    }
    else cout << "Student ID: " << studentID << "not found." << endl;
}

Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destructor called for " << students[i]->getID() << endl;
        delete students[i];
        students[i] = nullptr;
    }
}


