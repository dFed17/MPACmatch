//
//  SortMachine.h
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#ifndef __MPACmatch__SortMachine__
#define __MPACmatch__SortMachine__

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Student.h"
#include "Mentor.h"
#include "DataFile.h"
#include "enums.h"

class SortMachine {
private:
    
    std::vector<Student> studentList;
    std::vector<Mentor> mentorList;
    
    CDataFile csvStudents;
    CDataFile csvMentors;
    CDataFile csvMentorMajors;
    
public:
    SortMachine() {}
    
    void importStudents(std::string pathName);
    void importMentors(std::string pathName);
    void importMentorMajors(std::string pathName);
    int getMentorIndex(std::string email);
    
    void decideMajors(Student& person, std::string majorsString);
    void decideMajorsMentors(Mentor& person, std::string majorsString);
    void sortStudentsByNumMajors();
    void sortMentorsByNumMajors();
    void makeMatches();
    void printMentors();
    int getNumCommonMajors(vector<classMajor> students, vector<classMajor> Mentor);

    
    template<typename T, typename P>
    T remove_if(T beg, T end, P pred)
    {
        T dest = beg;
        for (T itr = beg;itr != end; ++itr)
            if (!pred(*itr))
                *(dest++) = *itr;
        return dest;
    }
    
};




#endif /* defined(__MPACmatch__SortMachine__) */
