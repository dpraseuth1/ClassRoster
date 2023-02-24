//
//  roster.hpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#ifndef roster_hpp
#define roster_hpp

#include <iostream>
#include <stdio.h>
#pragma once
#include <vector>
#include <string.h>
#include <cstring>
#include <sstream>
#include <regex>
#include "student.hpp"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* students[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    
public:
    Roster();
    Student** getStudents();
    void parse1(string row);
    
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram dp);
    
    void printAll();
    
    void printByDegreeProgram(DegreeProgram dp);
    
    void printInvalidEmails();
    
    void printAverageDaysInClass(string studentID);
    
    void remove(string studentID);
    
};
    

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
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) //checking if email has an '@' and '.' and doesn't contain a ' '
            cout << email << "is invalid" << endl; 
    }
}


#endif /* roster_hpp */
