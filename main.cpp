#include "Login.h"
#include "Menu.h"
#include "Manager.h"
#include "Console.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Console console;
	console.menu.showMainMenu();
	int handle;
	cin >> handle;
	console.operatorNum(handle);
	return 0;
}
