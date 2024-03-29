// Course.h
#include <iostream>

using namespace std;
struct Course {

enum dayOfWeek {MON, TUE, WED, THUR, FRI, SAT, SUN};
static char getCharByDay(dayOfWeek);
static dayOfWeek getDayByChar(char);
char getDayChar() const;
Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);
Course (const Course & m);

void swap(Course & crs1, Course & crs2) const;
Course & operator = (const Course & m);
bool operator < (const Course & m) const;
bool operator == (const Course & m) const;
string title; // Name of Course
dayOfWeek day; // Day of Course
unsigned int start_time; // Course start time in HHMM format
unsigned int finish_time; // Course finish time in HHMM format
};

// Helper operator for output
ostream &operator << (ostream &os, const Course & m);


struct Conflict{
    Course first;
    Course second;
    Conflict(Course c1, Course c2) : first(c1), second(c2){}
};
ostream &operator << (ostream &os, const Conflict & c);
