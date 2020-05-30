#pragma once
#include "Role.h"
#include "Student.h"
#include "Course.h"
#include "Utils.h"
#include "Teacher.h"
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Manager :public Role, public Utils {
public:
	Manager();
	void addStudent();
	void deleteStudent();
	void addCourse();
	void deleteCourse();
	void viewStudent();
	void viewCourse();
	void writeStudent();
	void writeCourse();
	void writeUser();
	void writeTeacher();
	void writeAdmin();
	void modifyStudent();
	void addTeacher();
private:
	map<string, Course> course;
	map<string, Student> student;
	map<string, Teacher> teacher;
};