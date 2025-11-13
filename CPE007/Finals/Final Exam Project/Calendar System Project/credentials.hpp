#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP

#include "misc.hpp"
#include "menuGUI.hpp"

const int credSize = 100;//Maximum number of storable credentials

const int openMenuSize = 3;

const string openMenuItems[openMenuSize] = {
	"Register",
	"Log-in",
	"Exit"
};

struct Credentials {
    string username;
    string password;
};

extern Credentials studentCreds[credSize];
extern Credentials teachCreds[credSize];

void searchCreds(string username, string password, int mode);
void login();
void pushToArray(string username, string password, int mode);
void registerCreds();
void printOpeningMenu();
void opening();//Handles main menu

#endif


