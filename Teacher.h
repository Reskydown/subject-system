#pragma once
#include<string>
using namespace std;
class Teacher {
public:
	friend ifstream & operator>> (ifstream &in, Teacher &c);
	friend ofstream & operator<< (ofstream &out,Teacher &c);
	void setName(string);
	void setNum(string);
	void setHisClass(string);
	void setGender(string);
	string getName();
	string getNum();
	string getHisClass();
	string getGender();
private:
	string name;
	string num;
	string hisClass;
	string gender;
};