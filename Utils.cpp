#include "Utils.h"
//控制光标的绝对位置
void Utils::position(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(h, pos);
}
//清屏
void Utils::clearScreen() {
	system("cls");
}
//暂停
void Utils::pauseScreen() {
	cout << "按任意建继续." << endl;
	system("pause");
}
//退出
void Utils::exitSystem() {
	cout << "正在退出..." << endl;
	exit(0);
}
//获取文件大小
long Utils::getFileSize(string name) {
	ifstream in(name.c_str());
	in.seekg(0, ios::end);
	long size = in.tellg();
	in.close();
	return size;
}