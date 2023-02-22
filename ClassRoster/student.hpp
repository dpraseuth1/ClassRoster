//
//  student.hpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "degree.hpp"
#include <iomanip>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    double daysInClass[daysArraySize];
    DegreeProgram degreeProgram;
public:
    //constructors
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, double daysInClass[], DegreeProgram degreeProgram);
    ~Student();
    
    //getters
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    const double* getDays();
    DegreeProgram getDegreeProgram();
    
    //setters
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(const double days[]);
    void setDegreeProgram(DegreeProgram dp);
    
    static void printHeader();
    void print();
    
};


#endif /* student_hpp */
