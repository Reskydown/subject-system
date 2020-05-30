#include"Teacher.h"
#include <string>
#include <fstream>
ifstream & operator>> (ifstream &in, Teacher &s) {
	string num, name, cl, gender;
	in >> num >> name >> cl >> gender;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(cl);
	s.setGender(gender);
	return in;
}
ofstream & operator<< (ofstream &out, Teacher &s) {
	out << s.getNum() << " " << s.getName() << " " << s.getHisClass() << "" << s.getGender() << endl;
	return out;
}
void Teacher::setName(string n) {
	this->name = n;
}
void Teacher::setNum(string n) {
	this->num = n;
}
void Teacher::setHisClass(string c) {
	this->hisClass = c;
}
void Teacher::setGender(string gender) {
	this->gender = gender;
}
string Teacher::getName() {
	return name;
}
string Teacher::getNum() {
	return num;
}
string Teacher::getHisClass() {
	return hisClass;
}
string Teacher::getGender() {
	return this->gender;
}