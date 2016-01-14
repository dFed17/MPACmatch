//
//  SortMachine.cpp
//  MPACmatch
//
//  Created by Daniel Fedor on 9/16/15.
//  Copyright (c) 2015 Daniel Fedor. All rights reserved.
//

#include "SortMachine.h"
#include "Student.h"
#include <sstream>
#include <algorithm>


using namespace std;


void SortMachine::importStudents(std::string pathName) {
    CDataFile studentData;
    studentData.SetDelimiter(";");
    studentData.ReadFile(pathName.c_str(), DF::RF_READ_AS_STRING);
    
    int numStudents = studentData.GetNumberOfSamples(0);
    
    //Student tempStudent;
    string email, username, myMajors, meth, y;
    contactMethod cMethTemp;
    meetingMethod mMethTemp;
    yearStanding tYear;

    
    for (int i = 0; i<numStudents-1; i++) {
        studentData.GetData(1, i, email);
        studentData.GetData(2, i, username);
        
        studentData.GetData(4, i,y);
        if (y.at(0)=='F') {
            tYear = Freshman;
        } else if (y.at(0)=='S') {
            tYear = Sophomore;
        } else if (y.at(0)=='J') {
            tYear = Junior;
        } else {
            tYear = Senior;
        }
        
        
        studentData.GetData(5, i, myMajors);

        
        studentData.GetData(6, i, meth);
        if (meth.at(0)=='M') {
            mMethTemp = individual;
        } else {
            mMethTemp = group;
        }
        
        studentData.GetData(7, i,meth);
        if (meth.at(0)=='P') {
            cMethTemp = phone;
        } else {
            cMethTemp = mail;
        }
        
        Student tempStudent(email, username, cMethTemp, mMethTemp, tYear);
        this->decideMajors(tempStudent, myMajors);
        //std::sort(tempStudent.getMajorVect().begin(), tempStudent.getMajorVect().end());

        
        studentList.push_back(tempStudent);
        
        
        
    }
    
    
}


void SortMachine::importMentors(std::string pathName) {
    CDataFile studentData;
    studentData.SetDelimiter(";");
    studentData.ReadFile(pathName.c_str(), DF::RF_READ_AS_STRING);
    
    int numStudents = studentData.GetNumberOfSamples(0);
    
    //Student tempStudent;
    string email, capacity;
    
    for (int i = 0; i<numStudents-1; i++) {
        studentData.GetData(0, i, capacity);
        
        studentData.GetData(1, i, email);
        
        Mentor temp = Mentor(email, stoi(capacity));
        mentorList.push_back(temp);
        
    }

    return;
}

void SortMachine::importMentorMajors(std::string pathName) {
    
    CDataFile studentData;
    studentData.SetDelimiter(";");
    studentData.ReadFile(pathName.c_str(), DF::RF_READ_AS_STRING);
    
    int numStudents = studentData.GetNumberOfSamples(0);
    
    //Student tempStudent;
    string email, myMajors, y;

    yearStanding tYear;
    
    
    for (int i = 0; i<numStudents-1; i++) {
        studentData.GetData(0, i, email);
        
        studentData.GetData(1, i, myMajors);
        studentData.GetData(2, i, y);
        
        if (y.at(0)=='F') {
            tYear = Freshman;
        } else if (y.at(0)=='S') {
            tYear = Sophomore;
        } else if (y.at(0)=='J') {
            tYear = Junior;
        } else {
            tYear = Senior;
        }
        
        int mIdx = getMentorIndex(email);
        if (mIdx != -1) {
            mentorList[mIdx].setYear(tYear);
            decideMajorsMentors(mentorList[mIdx], myMajors);
            //std::sort(mentorList[mIdx].getMajorVect().begin(), mentorList[mIdx].getMajorVect().end());
        }
        
    }
    
    
    
    return;
    
    
}

//returns -1 if a mentor who did the survey interest didnt do the application
int SortMachine::getMentorIndex(std::string email) {
    for (int i = 0; i<mentorList.size(); i++) {
        if (email == mentorList[i].getEmail()) {
            return i;
        }
    }
    return -1;
    
}


void SortMachine::decideMajors(Student& person, std::string majorsString) {
    stringstream ss(majorsString);
    vector<string> parsedMajors;
    
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        parsedMajors.push_back(substr);
    }

    
    for( int i = 0; i < parsedMajors.size(); i++) {
        string test = parsedMajors[i];
        
        
        test.erase(remove(test.begin(), test.end(), ' '), test.end());
        for (int j = 0; j<NUM_MAJORS; j++) {
            string test2(classMajorStrings[j]);
            test2.erase(remove(test2.begin(), test2.end(), ' '), test2.end());
            if (test2.compare(test) == 0) {
                person.addMajor(classMajor(j));
                parsedMajors.erase(parsedMajors.begin()+i);
                i--;
                break;
            }
        }
    }

    int numMajors = 0;
    numMajors = static_cast<int>(parsedMajors.size());

    
    cout << "Individuals selected majors:\n";
    cout << "[ ";
    for (int z=0; z<numMajors; z++) {
        cout << parsedMajors[z] << ", ";
    }
    cout << " ]" << "\n";
    
    
    
    cout << "Enter the numerical index of each major once or 111 to skip one:\n";
    
    int majorIndex = 0;
    for (majorIndex = 0; majorIndex<NUM_MAJORS; majorIndex++) {
        cout << "(" << majorIndex << ")" << classMajorStrings[majorIndex] <<"\n";
        
    }
  
    int studentMajor = 0;
    for (int i = 0; i<numMajors; i++) {
        cout << "Enter next index: ";
        cin >> studentMajor;
        if (studentMajor<(NUM_MAJORS-2)) {
            person.addMajor(classMajor(studentMajor));
        }
    }
    cout << "---------------------------------------\n\n";
    return;
}

void SortMachine::decideMajorsMentors(Mentor& person, std::string majorsString) {
    stringstream ss(majorsString);
    vector<string> parsedMajors;
    
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        parsedMajors.push_back(substr);
    }
    
    
    for( int i = 0; i < parsedMajors.size(); i++) {
        string test = parsedMajors[i];
        
        
        test.erase(remove(test.begin(), test.end(), ' '), test.end());
        for (int j = 0; j<NUM_MAJORS; j++) {
            string test2(classMajorStrings[j]);
            test2.erase(remove(test2.begin(), test2.end(), ' '), test2.end());
            if (test2.compare(test) == 0) {
                person.addMajor(classMajor(j));
                parsedMajors.erase(parsedMajors.begin()+i);
                i--;
                break;
            }
        }
    }
    
    int numMajors = 0;
    numMajors = static_cast<int>(parsedMajors.size());
    
    
    cout << "Individuals selected majors:\n";
    cout << "[ ";
    for (int z=0; z<numMajors; z++) {
        cout << parsedMajors[z] << ", ";
    }
    cout << " ]" << "\n";
    if (!parsedMajors.empty()) {
        cout << "Please enter the number of remaining majors:";
        cin >> numMajors;
        
        
        
        cout << "Enter the numerical index of each major once:\n";
        
        int majorIndex = 0;
        for (majorIndex = 0; majorIndex<NUM_MAJORS; majorIndex++) {
            cout << "(" << majorIndex << ")" << classMajorStrings[majorIndex] <<"\n";
            
        }
        
        int studentMajor = 0;
        for (int i = 0; i<numMajors; i++) {
            cout << "Enter next index: ";
            cin >> studentMajor;
            if (studentMajor<(NUM_MAJORS-2)){
                person.addMajor(classMajor(studentMajor));
            }
        }
    }

    cout << "---------------------------------------\n\n";
    return;
}

void SortMachine::sortStudentsByNumMajors() {
    
    std::sort(studentList.begin(), studentList.end());
    std::sort(mentorList.begin(), mentorList.end());
    return;
}


void SortMachine::makeMatches() {
    bool added = false;
    int numMentors = static_cast<int>(mentorList.size());
    

    
    
    int max = 1;
    
    for (int i = 0; i<studentList.size(); i++) {
        if (i>=numMentors) {
            max = 2;
        }
        added = false;
        for (int j = 0; j<mentorList.size(); j++) {
            

            if ((mentorList[j].getMentees().size() < max) && (mentorList[j].getYear() != studentList[i].getYear()) && !mentorList[j].atCapacity()) {

                int count = getNumCommonMajors(studentList[i].getMajorVect(), mentorList[j].getMajorVect());
                
                
                
                if (count==studentList[i].getMajorVect().size()) {
                    mentorList[j].addMentee(studentList[i]);
                    added = true;
                    break;
                }
                
                if (count>studentList[i].getCommonMajors()) {
                    studentList[i].setCommonMajors(count);
                    studentList[i].setBestMatch(j);
                }

                
            }
            
        }
        
        if (!added) {
            int bestMatch = studentList[i].getBestMatch();
            if (bestMatch != -1) {
                mentorList[bestMatch].addMentee(studentList[i]);
            } else {
                for (int j = 0; j<mentorList.size(); j++) {
                    if (mentorList[j].getMentees().size()<max) {
                        mentorList[j].addMentee(studentList[i]);
                    }
                }
            }
        }
        
    }
    
    return;
}

void SortMachine::printMentors() {
    int mentCount = 1;
    int studCount = 1;
    string menteeString;

    
    CDataFile outfile;
    outfile.CreateVariable("Mentor", "");
    outfile.CreateVariable("Mentees", "");
    
    for (int i = 0; i < mentorList.size(); i++){
        cout << /*mentCount <<" - */"Mentor: " << mentorList[i].getEmail() << "\n";
        mentCount++;
        outfile.AppendData(0, mentorList[i].getEmail().c_str());
        menteeString = "";
        
        for (int j=0; j<mentorList[i].getMentees().size(); j++) {
            menteeString.append(mentorList[i].getMentees()[j].getEmail());
            menteeString.append(", ");
            cout << "\t" /*<< studCount << " - "*/ << mentorList[i].getMentees()[j].getEmail() << "\n";
            studCount++;
            
        }
        outfile.AppendData(1, menteeString.c_str());
        cout << "\n";
    }

    
    outfile.WriteFile("/Users/danielfedor/Desktop/MPAC/excelInfo/allMatches.csv", ";");
    

    
}

int SortMachine::getNumCommonMajors(vector<classMajor> students, vector<classMajor> Mentor) {
    int count = 0;
    for (int i = 0; i<students.size(); i++) {
        for (int j = 0; j<Mentor.size(); j++) {
            if ( Mentor[j] == students[i] ) {
                count++;
            }
        }
    }
                return count;
}










