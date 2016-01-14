//
//  Student.h
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#ifndef __MPACmatch__Student__
#define __MPACmatch__Student__

#include <stdio.h>
#include <iostream>
#include <vector>


#include "enums.h"
#include "DataFile.h"


using namespace std;

class Student {
protected:
    std::string email;
    std::string name;
    std::vector<classMajor> majors;
    
    yearStanding year;
    contactMethod cMeth;
    meetingMethod mMeth;
    
    int commonMajors;
    int bestMentIdx;
    
public:
    Student() {}
    
    Student(string const& mail, string const& nameString, contactMethod const& cM, meetingMethod const& mM, yearStanding const& y);
    
    void setEmail(std::string address) {
        email = address;
    }
    
    string getEmail() {
        return email;
    }
    
    int getCommonMajors() {
        return commonMajors;
    }
    
    void setCommonMajors(int x) {
        commonMajors = x;
    }
    
    void setBestMatch(int x) {
        bestMentIdx = x;
    }

    int getBestMatch() {
        return bestMentIdx;
    }

    void setName(std::string tempName) {
        name = tempName;
    }
    
    void setString(std::string address) {
        email = address;
    }
    
    void setYear(yearStanding grade) {
        year = grade;
    }
    
    yearStanding getYear() {
        return year;
    }
    
    vector<classMajor> getMajorVect() {
        return majors;
        
    }
    
    void addMajor(classMajor major);
    void clearMajors();
    
    bool operator ==(Student& other);
    bool operator<(const Student& other) const;
    
};







#endif /* defined(__MPACmatch__Student__) */
