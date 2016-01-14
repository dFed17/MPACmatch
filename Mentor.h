//
//  Mentor.h
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#ifndef __MPACmatch__Mentor__
#define __MPACmatch__Mentor__

#include <stdio.h>
#include <iostream>
#include <vector>


#include "Student.h"


using namespace std;


class Mentor{
private:
    std::string email;
    std::vector<classMajor> majors;
    yearStanding year;

    int capacity;
    std::vector<Student> mentees;
    
public:
    Mentor() {}
    
    Mentor(string const& mail, int const& cap);
    
    string getEmail() {
        return email;
    }

    void addMentee(Student mentee) {
        mentees.push_back(mentee);
    }
    void clearMentees() {
        mentees.clear();
    }
    void setCapacity(int cap) {
        capacity = cap;
    }
    
    yearStanding getYear() {
        return year;
    }

    bool atCapacity() {
        if (mentees.size() < capacity) {
            return false;
        }
        return true;
    }
    
    void setYear(yearStanding grade) {
        year = grade;
    }
    
    vector<Student> getMentees() {
        return mentees;
    }
    
    vector<classMajor> getMajorVect() {
        return majors;
        
    }
    
    void addMajor(classMajor major);
    
    bool operator<(const Mentor& other) const;

    
    
    
};

#endif /* defined(__MPACmatch__Mentor__) */
