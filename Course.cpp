#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

void Course::swap(Course& crs1, Course& crs2) const{
    using std::swap;
    swap(crs1.title, crs2.title);
    swap(crs1.day, crs2.day);
    swap(crs1.start_time, crs2.start_time);
    swap(crs1.finish_time, crs2.finish_time);
}

Course & Course::operator =(const Course & m) {
    Course c{m};
    swap(*this, c);
    return *this;
}
bool Course::operator == (const Course & m) const {
    return title == m.title
            && day == m.day
            && start_time == m.start_time
            && finish_time == m.finish_time;
}

bool Course::operator < (const Course & m) const
{
    if(day != m.day)
        return day < m.day;
    if(start_time != m.start_time)
        return start_time < m.start_time;
    if(title != m.title)
        return title < m.title;
    return finish_time < m.finish_time;
}

char Course::getDayChar() const{
    return getCharByDay(day);
}

char Course::getCharByDay(Course::dayOfWeek d){
    switch (d){
    case dayOfWeek::MON :
        return 'M';
    case dayOfWeek::TUE :
        return 'T';
    case dayOfWeek::WED :
        return 'W';
    case dayOfWeek::THUR :
        return 'R';
    case dayOfWeek::FRI :
        return 'F';
    case dayOfWeek::SAT :
        return 'S';
    case dayOfWeek::SUN :
        return 'U';
    }
    return '\0';
}
Course::dayOfWeek Course::getDayByChar(char c){
    switch(toupper(c)){
        case 'M':
            return Course::dayOfWeek::MON ;
        case 'T' :
            return Course::dayOfWeek::TUE;
        case 'W' :
            return Course::dayOfWeek::WED;
        case 'R' :
            return Course::dayOfWeek::THUR;
        case 'F' :
            return Course::dayOfWeek::FRI;
        case 'S' :
            return Course::dayOfWeek::SAT;
        case 'U':
            return Course::dayOfWeek::SUN ;
        default:
            return Course::dayOfWeek::SUN;
    }
}

ostream & operator << (ostream &os, const Course & m)
{
    os << m.title << " " << m.getDayChar() << " " << m.start_time << " " << m.finish_time;
    return os;
}
ostream & operator << (ostream &os, const Conflict & m)
{
    os << "CONFLICT:" << endl << m.first << endl << m.second << endl;
    return os;
}