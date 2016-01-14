//
//  Mentor.cpp
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#include "Mentor.h"


Mentor::Mentor(string const& mail, int const& cap): email(mail), capacity(cap) {}

void Mentor::addMajor(classMajor major) {
    majors.push_back(major);
}


bool Mentor::operator<(const Mentor& other) const {
    if (this->majors.size() < other.majors.size() ) return true;
    return false;
}


