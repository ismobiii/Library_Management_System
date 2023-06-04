#include"stdafx.h"
#include<iomanip>
#include"reader.h"
#include<iostream>
using namespace std;
Reader::Reader() {
	note = 1;
	number = 0;
	name[0] = '\0';
	for (int i = 0; i < Maxbor; i++)
		borbook[i] = 0;
	for (int i = 0; i < Maxbor; i++)
		for (int j = 0; j < 2; j++)
			rankorder[i][j] = 0;
}
Reader::Reader(int n, int num, char na[], int b[], int r[][2]) {
	note = n;
	number = num;
	strcpy_s(name, strlen(na) + 1, na);
	for (int i = 0; i < Maxbor; i++) {
		borbook[i] = b[i];
		for (int j = 0; j < 2; j++)rankorder[i][j] = r[i][j];
	}
}
Reader::Reader(const Reader& r) {
	note = r.note;
	number = r.number;
	strcpy_s(name, strlen(r.name) + 1, r.name);
	for (int i = 0; i < Maxbor; i++) {
		borbook[i] = r.borbook[i];
		for (int j = 0; j < 2; j++)rankorder[i][j] = r.rankorder[i][j];
	}
}
char* Reader::getname() {
	return name;
}
int Reader::getnote() {
	return note;
}
int Reader::getnumber() {
	return number;
}
int Reader::getbook() {//判断是否有借书
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] != 0)return 1;
	}
	return 0;
}
void Reader::setname(char na[]) {
	strcpy_s(name, strlen(na) + 1, na);
}
void Reader::delreader() {//删除读者信息
	this->note = 1;
}
void Reader::addreader(int n, char* na) {
	note = 0;
	number = n;
	strcpy_s(name, strlen(na) + 1, na);
	for (int i = 0; i < Maxbor; i++) {
		borbook[i] = 0;
		for (int j = 0; j < 2; j++)rankorder[i][j] = 0;
	}
}
int Reader::borrowbook(int bookid) {
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == 0) {
			borbook[i] = bookid;
			
			return 1;
		}
	}
	return 0;//成功了返回1，失败了返回0
}
int Reader::retbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) {
			borbook[i] = 0;
			return 1;
		}
	}
	return 0;//找不到书就返回0，成功还书本返回1
}
void Reader::list() {//输出读者信息
	if (note == 1)return;
	else if (note == 0) {
		cout << setw(5) << number << setw(10) << name << "借书编号：[";
		for (int i = 0; i < Maxbor; i++) {
			if (borbook[i] != 0)
				cout << borbook[i] << ' ';
		}
		cout << "]\n";
		/*cout << endl << "等待借书的编号的次序：" << endl;
		for (int i = 0; i < Maxbor; i++)
			if (rankorder[i][1] != 0)cout << "[图书编号：" << rankorder[i][0] 
				<< " 次序：" << rankorder[i][1] << "]\n";*/
	}
}
void Reader::showrankoreder(int bid) {
	for (int i = 0; i < Maxbor; i++) {
		for (int j = 0; j < 2; j++) {
			if (rankorder[i][0] == bid)cout << "读者在编号为" << rankorder[i][0]
				<< "的图书中等待借书队列次序为" << rankorder[i][1] << endl;
			return;
		}
	}
	cout << "读者没有在这本书的等候队列中" << endl;
}