#include "menuGUI.hpp"

// ------- Headers ------- //
void printTMenu() {
	printMenu("TEACHER MENU",teachMenu,teachMENU_ITEMS);
}

void printSMenu() {
	printMenu("STUDENT MENU",studentMenu,studentMENU_ITEMS);
}

// ------- Selection Menu ------- //

void teachMain(){
	int selected = 0;
	bool isRunning = true;
	while (isRunning){
		printTMenu();
		int selected = selection(teachMENU_ITEMS,printTMenu);
		switch (selected){
			case 4:
				system("CLS");
				isRunning = false;
				opening();
				break;
		    case 0: 
				setTask(mainCalendar);
				wait(2);
				break;
            case 1: 
				showTasks(mainCalendar); 
				wait(showTaskTime);
				break;
            case 2: 
				clearTasks(mainCalendar); 
				wait(2);
				break;
            case 3: 
				printCalendar(mainCalendar);
				wait(10);
				system("CLS");
				break;
		}
	}
}

void studentMain(){
	int selected = 0;
	bool isRunning = true;
	while (isRunning){
		printSMenu();
		int selected = selection(studentMENU_ITEMS,printSMenu);
		switch (selected){
			case 2:
				system("CLS");
				isRunning = false;
				opening();
				break;
            case 0: 
				showTasks(mainCalendar); 
				wait(showTaskTime);
				break;
            case 1: 
				printCalendar(mainCalendar);
				wait(10);
				break;
		}
	}
}

