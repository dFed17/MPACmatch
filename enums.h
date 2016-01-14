
//
//  enums.h
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#ifndef MPACmatch_enums_h
#define MPACmatch_enums_h

static const std::string classMajorStrings[] {"BCN", "Biochemistry", "Biology", "Microbiology", "Neuroscience", "Psychology", "CMB", "BBA", "Spanish", "MovementScience", "Anthropology", "Biophysics", "EcoEvo", "BME", "ChemE",  "English", "BMS", "Chemistry", "Computer Science", "Mechanical Engineering", "I HAVE NO CLUE", "Other"};

enum classMajor {
    BCN=0,
    Biochemistry,
    Biology,
    Microbiology,
    Neuroscience,
    Psychology,
    CMB,
    BBA,
    Spanish,
    Movement_Science,
    Anthropology,
    Biophysics,
    EcoEvo,
    BME,
    ChemE,
    English,
    BMS,
    Chemistry,
    CompSci,
    MechE,
    Undecided,
    Other,
    NUM_MAJORS = 22
    
    
    
    
};

enum contactMethod {
    phone = 0,
    mail
};

enum meetingMethod {
    individual =0,
    group
};

static const std::string yearStandingStrings[] {"Freshman", "Sophomore", "Junior", "Senior"};
enum yearStanding {
    Freshman = 0,
    Sophomore,
    Junior,
    Senior,
    NUM_YEARS = 4
};

#endif
