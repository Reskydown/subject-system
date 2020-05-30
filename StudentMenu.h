#pragma once
#include "Utils.h"
#include "Student.h"
class StudentMenu :public Utils {
public:
	void showStudentMenu();
	void handleNum(int, Student&);
private:
};