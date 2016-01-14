//
//  Student.cpp
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#include "Student.h"


Student::Student(string const& mail, string const& nameString, contactMethod const& cM, meetingMethod const& mM,  yearStanding const& y) :  email(mail), name(nameString), cMeth(cM), mMeth(mM), year(y), bestMentIdx(-1), commonMajors(-1) {}

void Student::addMajor(classMajor major) {
    majors.push_back(major);
}

void Student::clearMajors() {
    majors.clear();
}

bool Student::operator ==(Student& other) {
    if (email.compare(other.email) == 0 ) {
        return true;
    } else
        return false;
    
}

bool Student::operator<(const Student& other) const {
    if (this->majors.size() < other.majors.size() ) return true;
    return false;
}

