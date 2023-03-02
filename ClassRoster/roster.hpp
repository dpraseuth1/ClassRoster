//
//  roster.hpp
//  ClassRoster
//
//  Created by David Praseuth on 2/22/23.
//

#ifndef roster_hpp
#define roster_hpp

#pragma once
#include <vector>
#include <string.h>
#include <cstring>
#include <vector>
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
    Student** getStudents(){
        return students;
    }
    void parse1(string row);
    
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram dp);
    
    void printAll();
    
    void printByDegreeProgram(DegreeProgram dp);
    
    void printInvalidEmails();
    
    void printAverageDaysInClass(string studentID);
    
    void removeID(string studentID);
    
    ~Roster();
};
    


#endif /* roster_hpp */
