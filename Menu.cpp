#include "ManagerMenu.h"
#include "StudentMenu.h"
#include "Menu.h"
#include "Login.h"
#include <fstream>
//获取成员变量ManagerMenu
ManagerMenu Menu::getManagerMenu() {
	return m;
}
//获取成员变量StudentMenu
StudentMenu Menu::getStudentMenu() {
	return s;
}
//显示菜单
void Menu::showMainMenu() {
	cout << "                    -----------学生选课管理系统-----------" << endl;
	cout << "                    --                                  --" << endl;
	cout << "                    --            1.管理员登陆          --" << endl;
	cout << "                    --            2.学生端登陆          --" << endl;
	cout << "                    --            3.退出系统            --" << endl;
	cout << "                    --                                  --" << endl;
	cout << "                    --------------------------------------" << endl;
	cout << "                              请输入要操作的编号:" << endl;
}
//显示登陆界面
void Menu::showLogin() {
	cout << "                         ┌─────┬──────────┐" << endl;
	cout << "                         │  账号:   │                    │" << endl;
	cout << "                         ├─────┼──────────┤" << endl;
	cout << "                         │  密码:   │                    │" << endl;
	cout << "                         └─────┴──────────┘" << endl;
}