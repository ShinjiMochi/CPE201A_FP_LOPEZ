#ifndef MENUGUI_HPP
#define MENUGUI_HPP

#include "calendar.hpp"
#include "credentials.hpp"
#include "misc.hpp"

extern schedInfo mainCalendar[12][6][7];

const int teachMENU_ITEMS = 5;
const int studentMENU_ITEMS = 3;

const int showTaskTime = 5;

const string teachMenu[teachMENU_ITEMS] = {
	"Add Task",
    "View Tasks",
    "Delete Tasks",
    "View Calendar",
    "Logout"
};

const string studentMenu[studentMENU_ITEMS] = {
    "View Tasks",
    "View Calendar",
    "Logout"
};


void printTMenu();
void teachMain();
void printSMenu();
void studentMain();

#endif


