//
//  student.cpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#include "student.hpp"

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) this->daysInClass[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
    
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInClass[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->daysInClass[i] = daysInClass[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student(){
    
}


//getters
string Student::getID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
const int* Student::getDays() {return this->daysInClass;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

//setters
void Student::setID(string ID) {this->studentID = ID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setEmail(string email) {this->email = email;}
void Student::setAge(int age) {this->age = age;}
void Student::setDays(const int days[])
{
    for(int i = 0; i < daysArraySize; i++){ this->daysInClass[i] = daysInClass[i];}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

//program

void Student::printHeader(){
    cout << "Student ID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "Days in Course";
    cout << "Degree Program";
    cout << endl;
}


void Student::print(){
    cout << this->studentID << '\t';
    cout << this->firstName << '\t';
    cout << this->lastName << '\t';
    cout << this->email << '\t';
    cout << this->age << '\t';
    cout << this->daysInClass[0] << '\t';
    cout << this->daysInClass[1] << '\t';
    cout << this->daysInClass[2] << '\t';
    cout << degreeProgramStrings[(int)this->degreeProgram] << '\t';
    cout << endl;
}
