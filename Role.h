#pragma once
#include <string>
using namespace std;
class Role {
public:
	void setUsername(string);
	void setPassword(string);
	string getUsername();
private:
	string username;
	string password;
};