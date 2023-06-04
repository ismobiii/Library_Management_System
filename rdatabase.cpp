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
Reader* RDatabase::query(int readerid) {//�ж϶����Ƿ����rdatabase�ϣ��Ƿ��ض���read���ָ�룬�񷵻ؿ�ָ��
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	return NULL;
}
int RDatabase::addreader(int n, char* na) {//n��readerid, na�Ƕ�������,��Ӷ���
	Reader* p = query(n);//�ж϶����Ƿ����
	if (p == NULL) {
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;//���ʧ��
}
void RDatabase::list() {
	if (top == -1) {
		cout << "û�ж������ݴ洢�ڿ�" << endl;
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
	int impor = 0;//�ж��ܲ���ɾ������
	char readername[20];
	int readerid;
	Reader* r;
	while (choice != 0) {
		cout << "------------------------------------------------------" << endl;
		cout << "����ά����" << endl;
		cout << "------------------------------------------------------" << endl;
		//cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 7���鿴����ͼ��Ⱥ���д��� 0���˳�" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 0:break;
		case 1://����
			cout << "������߱��:";
			cin >> readerid;
			cout << "�����������:";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2://����
			cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (!r) {
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			cout << "�����µ�����:";
			cin >> readername;
			r->setname(readername);
			break;
		case 3://ɾ��
			cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ�ɾ��ʧ��" << endl;
				break;
			}
			if (r->getbook()) {
				cout << "�ö��߽���δ����ɾ��ʧ��" << endl;
				break;
			}
			r->delreader();
			//top--;
			break;
		case 4://����
			cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "�ö��߲�����" << endl;
				break;
			}
			r->list();
			break;
		case 5://��ʾ������Ϣ
			list();
			break;
		case 6://ȫɾ
			clear();
			break;
		/*case 7:
			cout << "������߱��" << endl;
			cin >> readerid;
			break;*/
		default:
			cout << "������󣬷���ѡ��ҳ��" << endl;
			break;
		}
	}
}