#include "Login.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "Menu.h"
//构造函数
Login::Login(char* username, char* password) {
	this->password = new char[strlen(username) + 1];
	this->username = new char[strlen(password) + 1];
	errorNum = 1;
	strcpy(this->username, username);
	strcpy(this->password, password);
}
//析构函数
Login::~Login() {
	delete[] username;
	delete[] password;
}
//是否登陆成功
bool Login::isLogin(char *str1, char *str2) {
	if (strcmp(str1, username) == 0 && strcmp(str2, password) == 0) {
		return true;
	}
	if (errorNum == 3)
	{
		std::cout << std::endl;
		std::cout << "你已经试了3次,程序自动退出." << std::endl;
		exit(0);
	}
	errorNum++;
	return false;
}
