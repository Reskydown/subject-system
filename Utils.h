#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
class Utils {
public:
	void position(int, int);
	void clearScreen();
	void pauseScreen();
	void exitSystem();
	long getFileSize(string name);
};