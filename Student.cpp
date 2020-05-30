#include "Student.h"
#include <iomanip>
//重载运算符>>
ifstream & operator>> (ifstream &in, Student &s) {
	string num, name, cl,gender;
	int age;
	in >> num >> name >> cl >> gender >> age;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(cl);
	s.setGender(gender);
	s.setAge(age);
	return in;
}
//重载运算符<<
ofstream & operator<< (ofstream &out, Student &s) {
	out << s.getNum() << " " << s.getName() << " " << s.getHisClass() << "" << s.getGender() << "" << s.getAge() << endl;
	return out;
}
//构造函数
Student::Student() {
	string tu;
	string tp;
	Course tempCourse;
	if (getFileSize("course.data") > 0) {
		ifstream is("course.data", ios_base::in);
		while (!is.eof())
		{
			is >> tempCourse;
			all.insert(map<string, Course>::value_type(tempCourse.getNum(), tempCourse));
		}
		is.close();
	}

	if (getFileSize("current.data") > 0) {
		ifstream ru("current.data", ios_base::in);
		ru >> tu >> tp;
		ru.close();
	}
	num = tu;
	string file = ".\\data\\" + tu + ".txt";
	if (getFileSize(file.c_str()) > 0) {
		ifstream is2(file.c_str(), ios_base::in);
		Course tempCourse1;
		while (!is2.eof())
		{
			is2 >> tempCourse1;
			course.insert(map<string, Course>::value_type(tempCourse1.getNum(), tempCourse1));
		}
		is2.close();
	}

}
//选课
void Student::selectCourse() {
	string num;
	cout << "请输入要选择的课程编号" << endl;
	cin >> num;
	map<string, Course>::iterator it = all.find(num);
	if (it == all.end()) {
		cout << "该课程不存在，不能选择" << endl;
	}
	else {
		course.insert(map<string, Course>::value_type((it->second).getNum(), (it->second)));
		cout << "你已成功选择该课程！" << endl;
	}
	pauseScreen();
}
//退课
void Student::cancelCourse() {
	string num;
	cout << "请输入要取消选择的课程编号" << endl;
	cin >> num;
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		cout << "你没有选择该课程！" << endl;
	}
	else {
		course.erase(it);
		cout << "你已成功取消选择该课程！" << endl;
	}
	pauseScreen();
}
//查看已选课程
void Student::viewCourse() {
	if (course.size() == 0) {
		cout << "没有选择任何课程" << endl;
	}
	else {
		cout << "您已选择的课程如下:" << endl;
		cout << "课程编号" << '\t' << "课程名称" << '\t' << "授课老师" << '\t'<< "课程学分" << '\t' << "课程学时"  << '\t' << "课程分数"<< endl;
		for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << "\t\t" << (it->second).getScore() << endl;
		}
	}
	pauseScreen();
}
//查看所有课程
void Student::allCourse() {
	if (all.size() == 0) {
		cout << "没有课程可选！" << endl;
	}
	else
	{
		cout << "所有可选的课程如下:" << endl;
		cout << "课程编号" << '\t' << "课程名称" << '\t' << "授课老师" << '\t' << "课程学分" << '\t' << "课程学时" << endl;
		for (map<string, Course>::iterator it = all.begin(); it != all.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << endl;
		}
		
	}
	pauseScreen();
}
void Student::setScore(string x) {
	string file = ".\\data\\" + getNum() + ".txt";
	if (getFileSize(file.c_str()) > 0) {
		ifstream is2(file.c_str(), ios_base::in);
		Course tempCourse1;
		while (!is2.eof())
		{
			is2 >> tempCourse1;
			course.insert(map<string, Course>::value_type(tempCourse1.getNum(), tempCourse1));
		}
		is2.close();
	}
	map<string, Course>::iterator it = course.find(x);
	if (it == course.end()) {
		cout << "该学生没有选择该课程" << endl;
	}
	else {
		cout << "请输入你要设置的分数" << endl;
		int x;
		cin >> x;
		(it->second).setScore(x);
		cout << "修改完成" << endl;
	}
	writeCourse();
}
//打印信息
void Student::printInformation() {
	cout << "您的信息如下:" << endl;
	ifstream isStudent("student.data", ios_base::in);
	string n1, n2, n3,n4;
	int n5;
	while (!isStudent.eof())
	{
		isStudent >> n1 >> n2 >> n3 >> n4 >> n5;
		if (n1 == num) {
			cout << "学号\t姓名\t班级\t\t性别\t年龄\t" << endl;
			cout << n1 << '\t' << n2 << '\t' << n3 << '\t' << n4 << '\t' << n5 <<endl;
			break;
		}
	}
	isStudent.close();
	viewCourse();
	double cnt = 0, _max = -1000;
	for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
		cnt += (it->second).getScore();
		_max = max(_max, (it->second).getScore());
	}
	int temp = 0;
	cout << "您要查看你的最高分与平均分吗(确认查看请输入1,退出请按0):";
	cin >> temp;
	if (temp == 1) {
		cout << "你的最高分为:" << _max << endl << "平均分为:" << cnt / course.size() << endl;
		pauseScreen();
	}
}
//写入文件
void Student::writeCourse() {
	remove("current.data");
	string file = ".\\data\\" + getNum() + ".txt";
	remove(file.c_str());
	ofstream os(file.c_str(), ios_base::app);
	for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
		if (it == course.begin()) {
			os << (it->second);
		}
		else {
			os << endl;
			os << (it->second);
		}
	}
}
//获取姓名
string Student::getName() {
	return name;
}
//获取学号
string Student::getNum() {
	return num;
}
//获取班级
string Student::getHisClass() {
	return hisClass;
}
string Student::getGender() {
	return this->gender;
}
int Student::getAge() {
	return this->age;
}
map<string, Course> Student::getCourse() {
	return course;
}
//设置姓名
void Student::setName(string n) {
	this->name = n;
}
//设置学号
void Student::setNum(string n) {
	this->num = n;
}
//设置班级
void Student::setHisClass(string c) {
	this->hisClass = c;
}
void Student::setGender(string gender) {
	this->gender = gender;
}
void Student::setAge(int age) {
	this->age = age;
}
