#include "Role.h"
#include<iostream>
using namespace std;
//设置用户名
void Role::setUsername(string n) {
	cout << "OK";
	this->username = n;
	
}
//设置密码
void Role::setPassword(string p) {
	this->password = p;
}
//获取用户名
string Role::getUsername() {
	return username;
}