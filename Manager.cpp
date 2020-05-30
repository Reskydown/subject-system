#include "Manager.h"
#include "Teacher.h"
#include <iomanip>
//构造函数
Manager::Manager() {
	if (getFileSize("course.data") > 0) {
		ifstream is("course.data", ios_base::in);
		Course tempCourse;
		while (!is.eof())
		{
			is >> tempCourse;
			course.insert(map<string, Course>::value_type(tempCourse.getNum(), tempCourse));
		}
		is.close();
	}
	if (getFileSize("teacher.data") > 0) {
		ifstream is("teacher.data", ios_base::in);
		Teacher tempTeacher;
		while (!is.eof())
		{
			is >> tempTeacher;
			teacher.insert(map<string, Teacher>::value_type(tempTeacher.getNum(), tempTeacher));
		}
		is.close();
	}
	if (getFileSize("student.data") > 0) {
		ifstream isStudent("student.data", ios_base::in);
		Student tempStudent;
		while (!isStudent.eof())
		{
			isStudent >> tempStudent;
			student.insert(map<string, Student>::value_type(tempStudent.getNum(), tempStudent));
		}
		isStudent.close();
	}
}
//增加学生
void Manager::addStudent() {
	cout << "请输入以下信息：" << endl;
	cout << "学号  姓名  班级  性别  年龄" << endl;
	string num, name, hisClass,gender;
	int age;
	cin >> num >> name >> hisClass >> gender >> age;
	Student s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	s.setGender(gender);
	s.setAge(age);
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		student.insert(map<string, Student>::value_type(s.getNum(), s));
		cout << "添加成功" << endl;
	}
	else {
		cout << "该学生已存在" << endl;
	}
	pauseScreen();

}
//删除学生
void Manager::deleteStudent() {
	string num;
	cout << "请输入删除学生的学号" << endl;
	cin >> num;
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		cout << "该学生不存在" << endl;
	}
	else {
		student.erase(it);
		cout << "删除成功！" << endl;
	}
	pauseScreen();
}
//增加课程
void Manager::addCourse() {
	cout << "请输入以下信息：" << endl;
	cout << "课程编号" << " " << "课程名称" << " " << "授课老师" << " " << "课程学分" << " " << "课程学时" << endl;
	string num, name, teacher;
	double credit;
	int times;
	cin >> num >> name >> teacher >> credit >> times;
	Course c;
	c.setNum(num);
	c.setName(name);
	c.setTeacher(teacher);
	c.setCredit(credit);
	c.setTimes(times);
	c.setScore(-1);
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		course.insert(map<string, Course>::value_type(c.getNum(), c));
		cout << "添加成功" << endl;
	}
	else {
		cout << "该课程已存在" << endl;
	}
	pauseScreen();

}
//删除课程
void Manager::deleteCourse() {
	string num;
	cout << "请输入删除课程的编号" << endl;
	cin >> num;
	map<string, Course>::iterator it = course.find(num);
	if (it == course.end()) {
		cout << "该课程不存在" << endl;
	}
	else {
		course.erase(it);
		cout << "删除成功！" << endl;
	}
	pauseScreen();
}
//查看学生
void Manager::viewStudent() {

	if (student.size() == 0) {
		cout << "目前没有学生！" << endl;
	}
	else {
		cout << "学号\t姓名\t班级\t\t性别\t年龄\t" << endl;
		
		for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
			cout << (it->second).getNum() << "\t" << (it->second).getName() << "\t" << (it->second).getHisClass() << "\t" << (it->second).getGender() << "\t" << (it->second).getAge() << endl;
		}
	}
	pauseScreen();
}
//查看课程
void Manager::viewCourse() {
	if (course.size() == 0) {
		cout << "目前没有课程！" << endl;
	}
	else {
		cout << "课程编号" << '\t' << "课程名称" << '\t' << "授课老师" << '\t' << "课程学分" << '\t' << "课程学时" << endl;
		for (map<string, Course>::iterator it = course.begin(); it != course.end(); ++it) {
			cout << (it->second).getNum() << "\t\t" << (it->second).getName() << '\t' << (it->second).getTeacher() << "\t\t" << (it->second).getCredit() << "\t\t" << (it->second).getTimes() << endl;
		}
	}
	pauseScreen();
}
void Manager::modifyStudent() {
	cout << "请输入需要修改信息或者登记成绩的学生编号:";
	string num;
	cin >> num;
	map<string, Student>::iterator it = student.find(num);
	if (it == student.end()) {
		cout << "该学生不存在" << endl;
	}
	else{
		cout << "修改个人信息请输入1,登记成绩请输入2:";
		int temp;
		cin >> temp;
		if (temp == 1) {
			string n1, n2, n3;
			int n4;
			cout << "请输入该学生姓名 班级 性别 年龄" << endl;
			cin >> n1 >> n2 >> n3 >> n4;
			(it->second).setName(n1);
			(it->second).setHisClass(n2);
			(it->second).setGender(n3);
			(it->second).setAge(n4);
			cout << "修改完成" << endl;
		}
		else{
			Student stu = it->second;
			cout << "请输入要输入成绩的课程编号:";
			string x;
			cin >> x;
			stu.setScore(x);
			
		}
	}
	pauseScreen();
}
void Manager::addTeacher() {
	cout << "请输入以下信息：" << endl;
	cout << "工号  姓名  院系  性别" << endl;
	string num, name, hisClass, gender;
	int age;
	cin >> num >> name >> hisClass >> gender;
	Teacher s;
	s.setNum(num);
	s.setName(name);
	s.setHisClass(hisClass);
	s.setGender(gender);
	map<string, Teacher>::iterator it = teacher.find(num);
	if (it == teacher.end()) {
		teacher.insert(map<string, Teacher>::value_type(s.getNum(), s));
		cout << "添加成功" << endl;
	}
	else {
		cout << "该学生已存在" << endl;
	}
	pauseScreen();
}
//写入文件
void Manager::writeStudent() {
	remove("student.data");
	ofstream os("student.data", ios_base::app);
	for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
		if (it == student.begin()) {
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " "<< (it->second).getGender() << " " << (it->second).getAge();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender() << " " << (it->second).getAge();
		}

	}
}
//写入文件
void Manager::writeCourse() {
	remove("course.data");
	ofstream os("course.data", ios_base::app);
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
//写入文件
void Manager::writeUser() {
	remove("user.data");
	ofstream os("user.data", ios_base::app);
	for (map<string, Student>::iterator it = student.begin(); it != student.end(); ++it) {
		if (it == student.begin()) {
			os << (it->second).getNum() << " " << (it->second).getNum();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getNum();
		}

	}
}
void Manager::writeAdmin() {
	remove("admin.data");
	ofstream os("admin.data", ios_base::app);
	for (map<string, Teacher>::iterator it = teacher.begin(); it != teacher.end(); ++it) {
		if (it == teacher.begin()) {
			os << (it->second).getNum() << " " << (it->second).getNum();
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getNum();
		}

	}
}
void Manager::writeTeacher() {
	remove("teacher.data");
	ofstream os("teacher.data", ios_base::app);
	for (map<string, Teacher>::iterator it = teacher.begin(); it != teacher.end(); ++it) {
		if (it == teacher.begin()) {
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender() ;
		}
		else {
			os << endl;
			os << (it->second).getNum() << " " << (it->second).getName() << " " << (it->second).getHisClass() << " " << (it->second).getGender();
		}

	}
}