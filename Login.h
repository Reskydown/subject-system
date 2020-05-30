#pragma once
#include"Menu.h"
class Login
{
public:
	Login(char*, char*);
	~Login();
	bool isLogin(char*, char*);
private:
	char* username;
	char* password;
	int  errorNum;
};