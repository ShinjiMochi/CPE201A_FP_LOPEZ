#include "misc.hpp"

int currRow = 0;

// ------- Wait Function ------- //

void wait(int time) {
	this_thread::sleep_for(chrono::seconds(time));
	//remove key inputs made while waiting
	while (kbhit()){
		getch();
	}

}

// ------- Header Format ------- //

void printHeader(const string &title) {
    cout << "\n====================================\n";
    cout << setw(19) << title << "\n";
    cout << "====================================\n";
}

// ------- Error Function ------- //

void isNumInRange(string dialogue, int &input , int minVal, int maxVal){
	bool invalid = true;
	do {
		cout << dialogue;
		cin >> input;
		invalid = (input  > maxVal || input < minVal);
		if (invalid){
			cout << "Error, Number Out of Range\n";
		}
	}while (invalid);
	cin.ignore();
}

// ------- Navigation Function ------- //

void printMenu(const string &menuName,const string menuItems[],int numItems){
	system("CLS");
    cout << "===== "<< menuName << " =====\n\n";
    for (int i = 0; i < numItems; i++) {
        if (i == currRow){
        	cout << " " << char(249) << " " << menuItems[i] << endl;
		}
        else{
        	cout << "   " << menuItems[i] << endl;
		}    
    }
    cout << "\nUse UP/DOWN arrows to navigate. Press ENTER to select.\n\n";
}

int selection(int menuItems,void (*printFunc)()){
	int returnedRow;
	while (true) {
		//Gets keyboard input
        if (_kbhit()) {
            int ch = _getch(); //Gets the character
            if (ch == 0 || ch == 224) {
                ch = _getch();//Interprets the character
                switch (ch) {
                    case 72: currRow--; if (currRow < 0) currRow = menuItems - 1; break;//User pressed down key
                    case 80: currRow++; if (currRow >= menuItems) currRow = 0; break; //User pressed up key
                }
                printFunc(); //reprints the menu used as parameter
            } else if (ch == 13) {
            	returnedRow = currRow;//store the current row value
            	currRow = 0; //Reset back to zero
            	return returnedRow;
            }
        }
    }
}

void exitProg(){
	system("CLS");
	cout << "Exited Program";
	exit(0);
}
	
