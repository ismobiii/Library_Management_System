#include"stdafx.h"
#include"rdatabase.h"
#include<fstream>
#include<iostream>
using namespace std;
RDatabase::RDatabase() {
	Reader s;
	int id = 0;
	top = -1;
	ifstream file;
	file.open("reader.txt", ios::in | ios::binary);
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear() {
	top = -1;
}
Reader* RDatabase::query(int readerid) {//判断读者是否存在rdatabase上，是返回读者read类的指针，否返回空指针
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	return NULL;
}
int RDatabase::addreader(int n, char* na) {//n是readerid, na是读者名字,添加读者
	Reader* p = query(n);//判断读者是否存在
	if (p == NULL) {
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;//添加失败
}
void RDatabase::list() {
	if (top == -1) {
		cout << "没有读者数据存储在库" << endl;
		return;
	}
	for (int i = 0; i <= top; i++)
		read[i].list();
}
RDatabase::~RDatabase() {
	fstream file;
	file.open("reader.txt", ios::out | ios::binary);
	for (int i = 0; i < top + 1; i++)
		if (read[i].getnote() == 0)
			file.write((char*)&read[i], sizeof(read[i]));
	file.close();
}
void RDatabase::readerdata() {
	int choice = 1;
	int impor = 0;//判断能不能删除读者
	char readername[20];
	int readerid;
	Reader* r;
	while (choice != 0) {
		cout << "------------------------------------------------------" << endl;
		cout << "读者维护：" << endl;
		cout << "------------------------------------------------------" << endl;
		//cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 7、查看读者图书等候队列次序 0：退出" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 0:break;
		case 1://新增
			cout << "输入读者编号:";
			cin >> readerid;
			cout << "输入读者姓名:";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2://更改
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (!r) {
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "输入新的姓名:";
			cin >> readername;
			r->setname(readername);
			break;
		case 3://删除
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "该读者不存在，删除失败" << endl;
				break;
			}
			if (r->getbook()) {
				cout << "该读者借书未还，删除失败" << endl;
				break;
			}
			r->delreader();
			//top--;
			break;
		case 4://查找
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "该读者不存在" << endl;
				break;
			}
			r->list();
			break;
		case 5://显示所有信息
			list();
			break;
		case 6://全删
			clear();
			break;
		/*case 7:
			cout << "输入读者编号" << endl;
			cin >> readerid;
			break;*/
		default:
			cout << "输入错误，返回选择页面" << endl;
			break;
		}
	}
}