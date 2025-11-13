#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include "misc.hpp"

// ------- Structures ------- //

struct taskInfo {
    string taskName;
    string deadline;
};

struct schedInfo {
    int day;
    string dayName;
    vector<taskInfo> tasks;
};

// ------- Function Prototypes ------- //
bool isLeapYear(int year);
int getDaysInMonth(int month);
string getDayName(int dayOfWeek);
int getStartDay(int month);
void createCalendar(schedInfo calendar[12][6][7]);  //Formats calendar
void printCalendar(schedInfo toBePrinted[12][6][7]); //Print calendar in a formatted manner
bool validDate(int m, int d);
schedInfo* searchCalendarDate(schedInfo calendar[12][6][7], string message); //returns the index on the array based on the inputted date
void setTask(schedInfo calendar[12][6][7]);
void showTasks(schedInfo calendar[12][6][7]);
void clearTasks(schedInfo calendar[12][6][7]);

#endif


