#include "credentials.hpp"

// ------- Bring back to homescreen function -------//
void backToHome(string message){
	cout << message;
	wait(3);
	opening();
}

// ------- Credential Search Function ------- //

void searchCreds(string username, string password, int mode) {
	if (username.empty() || password.empty()) { //Check if username is empty
		backToHome("Credentials cannot be empty!");
	}
    bool found = false;
    for (int i = 0; i < credSize; i++) {// Find credential in array
        if (mode == 2) {
            if (studentCreds[i].username == username) {
                found = true;
                if (studentCreds[i].password == password) {
					studentMain();
                } else {
                    backToHome("Incorrect username or password");
                    wait(3);
                    opening();
                }
                break;
            }
        } else {
            if (teachCreds[i].username == username) {
                found = true;
                if (teachCreds[i].password == password) {
                    teachMain();
                } else {
					backToHome("Incorrect username or password");
                }
                break;
            }
        }
    }
    if (!found) {
        backToHome("Account does not exist");
    }
}

// ------- Login Function ------- //

void login() {
    system("CLS");
    printHeader("LOGIN");
    int role;
    string username;
    string password;

    cout << "Log-in\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    isNumInRange("Login as teacher(1) or as a student(2)\n", role, 1, 2);

    searchCreds(username, password, role);
}

// ------- Registration Functions ------- //

void pushToArray(string username, string password, int role) {
	if (username.empty() || password.empty()) {
	backToHome("Credentials cannot be empty!");
	}
    for (int i = 0; i < credSize; i++) {//Find empty index
        if (role == 2) {
            if (studentCreds[i].username == username) {
            	backToHome("username already exists");
            }
            if (studentCreds[i].username.empty()) {
                studentCreds[i].username = username;
                studentCreds[i].password = password;
                return;
            }
        } else {
            if (teachCreds[i].username == username) {
                backToHome("username already exists");
            }
            if (teachCreds[i].username.empty()) {
                teachCreds[i].username = username;
                teachCreds[i].password = password;
                return;
            }
        }
    }
}

void registerCreds() {
    system("CLS");
    printHeader("REGISTER");
    int role = 0;
    string username, password;

    cout << "Register\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    isNumInRange("Register as teacher(1) or as a student(2)\n", role, 1, 2);

    pushToArray(username, password, role);
    backToHome("Registered Sucessfully");
}

// ------- Main selection screen ------- //

void printOpeningMenu() {
    printMenu("School Task Scheduler", openMenuItems, openMenuSize);
}

void opening() {
    int selected = 0;
    printOpeningMenu();
    selected = selection(openMenuSize, printOpeningMenu);
    switch (selected) {
        case 0: registerCreds(); break;
        case 1: login(); break;
        case 2: exitProg(); break;
    }
}
