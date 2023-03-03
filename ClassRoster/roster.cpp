//
//  roster.cpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#include "roster.hpp"
#include <regex>



void Roster::parse1(string row)
{
    std::regex regex("\\,");
    std::vector<string> splitter(
        std::sregex_token_iterator(row.begin(), row.end(), regex, -1), std::sregex_token_iterator());
    DegreeProgram dp = DegreeProgram::SECURITY;
    if (splitter.at(6).back() == 'K') dp = DegreeProgram::NETWORK;
    if (splitter.at(6).back() == 'E') dp = DegreeProgram::SOFTWARE;
    add(splitter.at(0), splitter.at(1), splitter.at(2), splitter.at(3), stod(splitter.at(4)), stod(splitter.at(5)), stod(splitter.at(6)), stod(splitter.at(7)), dp);
    
}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram dp){
    int daysInClassArray[3] = { daysInClass1, daysInClass2, daysInClass3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInClassArray, dp);
    cout << "Student added to roster at row " << lastIndex + 1 << endl;
}

void Roster::printAll(){
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}
    
//pass in degree program

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
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
        if (classRosterArray[i]->getID() == studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3.0 << endl;
        }
    }
}

//remove by student ID
void Roster::removeID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
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
        cout << "Destructor called for " << classRosterArray[i]->getID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}


