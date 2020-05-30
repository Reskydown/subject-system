#pragma once
#include "Course.h"
#include "Utils.h"
#include "Role.h"
#include <string>
#include <fstream>
#include <map>
using namespace std;
class Student :public Role, public Utils {
public:
	friend ifstream & operator>> (ifstream &in, Student &c);
	friend ofstream & operator<< (ofstream &out, Student &c);
	Student();
	void selectCourse();
	void cancelCourse();
	void viewCourse();
	void allCourse();
	void printInformation();
	string getName();
	string getNum();
	string getHisClass();
	string getGender();
	map<string, Course> getCourse();
	int getAge();
	void setName(string);
	void setNum(string);
	void setHisClass(string);
	void setGender(string);
	void setAge(int);
	void setScore(string);
	void writeCourse();
private:
	string name;
	string num;
	string hisClass;
	string gender;
	int age;
	map<string, Course> course, all;
};