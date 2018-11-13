#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <list>
#include "Course.cpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(set<Course> courses)
{
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout,"\n"));
}

void printConflicts(list<Conflict> conflicts){
    copy(conflicts.begin(), conflicts.end(), ostream_iterator<Conflict>(cout,"\n"));
}

bool load(const string& fileName, set<Course>& courses);

int main () {
    set<Course> courses;
    list<Conflict> conflicts;
    load("courses.txt", courses);
    for(auto it = courses.begin(); it != courses.end(); ++it){
        for(auto it2 = next(it); it2 != courses.end() && it->day == it2->day && it->finish_time > it2->start_time; ++it2){
            conflicts.insert(conflicts.end(), Conflict(*it, *it2));
        }
    }
    printConflicts(conflicts);
    printSchedule(courses);
    return 0;
}

bool load(const string& fileName, set<Course>& courses){
    ifstream file = ifstream(fileName, ios_base::in);
    if(!file.is_open()) {
        cerr << "Unable to open file to load.";
        return false;
    }
    else {
        string line;
        while(getline(file, line)){
            stringstream lineStream;
            string title;
            stringstream daystream;
            char day;
            unsigned int start_time;
            unsigned int finish_time;
            lineStream << line;
            lineStream >> title;
            lineStream >> day;
            lineStream >> start_time;
            lineStream >> finish_time;
            Course c{title, Course::getDayByChar(day), start_time, finish_time};
            courses.insert(c);
        }
        file.close();
        if(file.is_open()) {
            cerr << "Unable to close file after load.";
            return false;
        }
    }
    return true;
}