#include "StudentMenu.h"
#include <iostream>
using namespace std;
//显示菜单
void StudentMenu::showStudentMenu() {
	cout << "        ---------------------学生选课管理系统(学生端)-------------------" << endl;
	cout << "        --                                                            --" << endl;
	cout << "        --                 1. 选择课程  2. 退选课程                   --" << endl;
	cout << "        --                 3. 已选课程  4. 查看所有课程               --" << endl;
	cout << "        --                 5. 信息输出  6. 退出系统                   --" << endl;
	cout << "        --                                                            --" << endl;
	cout << "        ----------------------------------------------------------------" << endl;
	cout << "                           请输入要操作的编号:" << endl;
}
//处理编号
void StudentMenu::handleNum(int h, Student &s) {
	clearScreen();
	switch (h)
	{
	case 1:
		s.selectCourse();
		break;
	case 2:
		s.cancelCourse();
		break;
	case 3:
		s.viewCourse();
		break;
	case 4:
		s.allCourse();
		break;
	case 5:
		s.printInformation();
		break;
	case 6:
		s.writeCourse();
		s.exitSystem();
		break;
	default:
		cout << "输入错误，正在准备退出" << endl;
		s.exitSystem();
		break;
	}
}