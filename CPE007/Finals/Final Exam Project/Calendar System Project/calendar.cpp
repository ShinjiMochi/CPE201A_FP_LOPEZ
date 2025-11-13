#include "calendar.hpp"

/*
=================================
Calendar creation essentials
================================
*/

const int year = 2025;

// Check for leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get number of days in a given month
int getDaysInMonth(int month) {
    const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // February
    if (month == 1 && isLeapYear(year)){
    	return 29;
	} 
    return daysInMonth[month];
}

string getDayName(int dayOfWeek){
	switch (dayOfWeek){		
		case 0:
			return "Sunday";
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";

	}
	return " ";
}

// Compute which weekday the month starts on (0 = Sunday, 6 = Saturday)
int getStartDay(int month) {
    // Zeller's congruence from online
    int m = month + 1;
    int y = year;
    if (m < 3) { m += 12; y--; }
    int q = 1;
    int k = y % 100;
    int j = y / 100;
    int h = (q + (13*(m + 1))/5 + k + (k/4) + (j/4) + (5*j)) % 7;
    return (h + 6) % 7; // 0 is sunday ,6 is saturday
}

void createCalendar(schedInfo calendar[12][6][7]){
	// 12 months, 6 weeks ,7 days

    for (int month = 0; month < 12; month++) {
        int startDay = getStartDay(month);
        int days = getDaysInMonth(month);

        int week = 0;
        int dayOfWeek = startDay;
        
        for (int day = 1; day <= days; day++) {
        	schedInfo *currentDay = &calendar[month][week][dayOfWeek];
            currentDay -> day = day;
            currentDay -> dayName = getDayName(dayOfWeek);
            
            dayOfWeek++;
            
            if (dayOfWeek > 6) { 
                dayOfWeek = 0;
                week++;// move to next week
            }
        }
    }
}

/*
===========================================================
Calendar utilization
==========================================================
*/

void printCalendar(schedInfo toBePrinted[12][6][7]) {
    for (int month = 0; month < 12; ++month) {
        cout << "Month " << month + 1 << ":\n";
        cout << "Su  Mo  Tu  We  Th  Fr  Sa\n";

        for (int week = 0; week < 6; week++) {
            bool emptyWeek = true;
            for (int day = 0; day < 7; day++) {
                if (toBePrinted[month][week][day].day != 0){
                	emptyWeek = false; 
				}   
            }
            
            if (emptyWeek) break; // skip empty weeks at end

            for (int day = 0; day < 7; day++) {
                if (toBePrinted[month][week][day].day == 0){
					cout << setw(4) << " ";  // keep spacing consistent	
				}   
                else{
                	if (toBePrinted[month][week][day].tasks.empty()){
                		cout << setw(4) << toBePrinted[month][week][day].day;//bold
					}
					else {
						cout << setw(4) << "[" + to_string(toBePrinted[month][week][day].day) + "]" ;
					}
					
				}
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

bool validDate(int m,int d){
	if ((m > 12 || m <= 0) || (d > getDaysInMonth(m-1) || d <= 0)){
		return false;
	}
	return true;
}

schedInfo* searchCalendarDate(schedInfo calendar[12][6][7],string message){
	int m,d;
	bool isDateValid;
	do {
		cout << message;
		cout << "Month:";
		cin >> m;
		cout << "Day: ";
		cin >> d;
		isDateValid = validDate(m,d);
		if (!isDateValid){
			cout << "Invalid date\n";
		}
		cin.ignore();//Remove endline in the buffer
	}while(!isDateValid);
	
	for (int i = 0; i < 6; i++){//week
		for (int j = 0; j < 7;j++){//day
			if (calendar[m-1][i][j].day == d){
				return &calendar[m-1][i][j];
			}
		}
	}
	return nullptr;
}

/*
==============================================================
CRUD utility
==================================================================
*/

void setTask(schedInfo calendar[12][6][7]){
	int countTasks;
	
	schedInfo* chosenDate = searchCalendarDate(calendar,"Select month and day for deadline:\n");
	isNumInRange("Enter task amount: ", countTasks , 1, 10);
	
	for (int i = 1; i <= countTasks;i++){
		cout << endl;
		string taskName;
		cout << "Enter task name: ";
		getline(cin,taskName);
		string deadlineTime;
		cout << "Enter deadline time: ";
		getline(cin,deadlineTime);
		chosenDate -> tasks.push_back({taskName,deadlineTime});
		cout << endl;
	}
	cout << "\n=================== Task Sucessfully Added =====================\n";
}

void showTasks(schedInfo calendar[12][6][7]){
	schedInfo* chosenDate = searchCalendarDate(calendar,"Show tasks from the date...\n");
	cout << "Available Task " <<" (" << chosenDate->dayName << "):\n";
    if (chosenDate->tasks.empty()) {
        cout << "  No tasks scheduled.\n";
    } else {
        for (const auto &task : chosenDate->tasks) { //Loops through the vector of the tasks
            cout << "  - " << task.taskName << " (Deadline time: " << task.deadline << ")\n";
        }
    }
}

void clearTasks(schedInfo calendar[12][6][7]) {
    schedInfo* chosenDate = searchCalendarDate(calendar, "Select task to be deleted\n");
    if (chosenDate->tasks.empty()) {
        cout << "  No tasks scheduled.\n";
        return;
    }
    for (size_t i = 0; i < chosenDate->tasks.size(); i++)
        cout << "(" << i + 1 << ") " << chosenDate->tasks[i].taskName << " (Deadline: " << chosenDate->tasks[i].deadline << ")\n";

    cout << "\n To be deleted(if multiple, seperate each with comma(,) and no spaces.Example :1,2) : ";
    string tbDeleted;
	getline(cin, tbDeleted);//get raw string
    stringstream ss(tbDeleted);
    string temp;
    vector<int> toDelete;//storage of the collected index
    while (getline(ss, temp, ',')) { //filters the string, using ',' as a separator
        int idx = stoi(temp);//turn string to int
        if (idx >= 1 && idx <= (int)chosenDate->tasks.size()){
        	toDelete.push_back(idx - 1);//collect the index
		}
    }
    
    // delete in reverse order
    for (int i = toDelete.size() - 1; i >= 0; i--){
    	chosenDate->tasks.erase(chosenDate->tasks.begin() + toDelete[i]);
	}
    cout << "Deleted selected tasks.\n";
}
