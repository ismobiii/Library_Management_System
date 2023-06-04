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
int Reader::getbook() {//�ж��Ƿ��н���
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] != 0)return 1;
	}
	return 0;
}
void Reader::setname(char na[]) {
	strcpy_s(name, strlen(na) + 1, na);
}
void Reader::delreader() {//ɾ��������Ϣ
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
	return 0;//�ɹ��˷���1��ʧ���˷���0
}
int Reader::retbook(int bookid) {
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) {
			borbook[i] = 0;
			return 1;
		}
	}
	return 0;//�Ҳ�����ͷ���0���ɹ����鱾����1
}
void Reader::list() {//���������Ϣ
	if (note == 1)return;
	else if (note == 0) {
		cout << setw(5) << number << setw(10) << name << "�����ţ�[";
		for (int i = 0; i < Maxbor; i++) {
			if (borbook[i] != 0)
				cout << borbook[i] << ' ';
		}
		cout << "]\n";
		/*cout << endl << "�ȴ�����ı�ŵĴ���" << endl;
		for (int i = 0; i < Maxbor; i++)
			if (rankorder[i][1] != 0)cout << "[ͼ���ţ�" << rankorder[i][0] 
				<< " ����" << rankorder[i][1] << "]\n";*/
	}
}
void Reader::showrankoreder(int bid) {
	for (int i = 0; i < Maxbor; i++) {
		for (int j = 0; j < 2; j++) {
			if (rankorder[i][0] == bid)cout << "�����ڱ��Ϊ" << rankorder[i][0]
				<< "��ͼ���еȴ�������д���Ϊ" << rankorder[i][1] << endl;
			return;
		}
	}
	cout << "����û�����Ȿ��ĵȺ������" << endl;
}