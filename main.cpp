
//
//  main.cpp
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#include <iostream>
#include "SortMachine.h"



int main(/*int argc, const char * argv[]*/) {
    // insert code here...
    SortMachine danielsMagnificentMatcher;
    
    danielsMagnificentMatcher.importStudents("/Users/danielfedor/Desktop/MPAC/excelInfo/menteeApp.csv");
    danielsMagnificentMatcher.importMentors("/Users/danielfedor/Desktop/MPAC/excelInfo/mentorSurvey.csv");
    danielsMagnificentMatcher.importMentorMajors("/Users/danielfedor/Desktop/MPAC/excelInfo/mentorMajors.csv");
    danielsMagnificentMatcher.sortStudentsByNumMajors();
    danielsMagnificentMatcher.makeMatches();
    danielsMagnificentMatcher.printMentors();
    
    
    return 0;
}
