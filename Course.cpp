#include "Course.h"
//���������>>
ifstream & operator>> (ifstream &in, Course &c) {
	string num, name, teacher,location;
	double credit;
	int times,score;
	in >> num >> name >> teacher >>credit >> times >> score ;
	c.setNum(num);
	c.setName(name);
	c.setTeacher(teacher);
	c.setCredit(credit);
	c.setTimes(times);
	c.setScore(score);
	return in;
}
//���������<<
ofstream & operator<< (ofstream &out, Course &c) {
	out << c.getNum() << " " << c.getName() << " " << c.getTeacher() << " " << c.getCredit() << " " << c.getTimes() << " " << c.getScore();
	return out;
}
//��ȡ�γ̱��
string Course::getNum() {
	return classNum;
}
//��ȡ�γ�����
string Course::getName() {
	return className;
}//��ȡ�ڿ���ʦ
string Course::getTeacher() {
	return teacher;
}
//��ȡѧ��
double Course::getCredit() {
	return credit;
}
//��ȡѧʱ
int Course::getTimes() {
	return times;
}
int Course::getScore() {
	return score;
}

//���ÿγ̱��
void Course::setNum(string classNum) {
	this->classNum = classNum;
}
//���ÿγ�����
void Course::setName(string className) {
	this->className = className;
}
//���ÿγ�ѧ��
void Course::setCredit(double credit) {
	this->credit = credit;
}
//���ÿγ�ѧʱ
void Course::setTimes(int times) {
	this->times = times;
}
//�����ڿ���ʦ
void Course::setTeacher(string teacher) {
	this->teacher = teacher;
}
void Course::setScore(int score) {
	this->score = score;
}