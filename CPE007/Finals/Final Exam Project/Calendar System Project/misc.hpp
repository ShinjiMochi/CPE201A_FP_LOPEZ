#ifndef MISC_HPP
#define MISC_HPP

#include <iostream> //input output
#include <iomanip> //formatting
#include <vector> //vector
#include <string> //string funcions
#include <sstream> // breaking strings 
#include <conio.h>  // For _kbhit() and _getch()
#include <thread> // for wait function
#include <chrono> // for wait function	

using namespace std;

void wait(int time);
void printHeader(const string &title);
void isNumInRange(string dialogue, int &input , int minVal, int maxVal);
void printMenu(const string &menuName,const string menuItems[],int numItems);
int selection(int menuItems,void (*printFunc)());
void exitProg();

#endif
