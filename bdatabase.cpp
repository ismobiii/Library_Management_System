#include"stdafx.h"
#include"bdatabase.h"
#include<iostream>
#include<fstream>
using namespace std;
BDatabase::BDatabase() {
	Book s;
	top = -1;
	fstream file;
	file.open("book.txt", ios::in | ios::binary);
	/*if (!file.is_open()) {
		cout << "�ļ�������" << endl;
		top = -1;
		file.close();
		return;
	}*/
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear() {
	top = -1;
}
Book* BDatabase::query(int bookid) {
	for (int i = 0; i <= top; i++) {
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	}
	return NULL;
}
Book* BDatabase::queryname(char* na) {
	for (int i = 0; i <= top; i++) {
		if (book[i].getname() == na && book[i].getnote() == 0)
			return &book[i];
	}
	return NULL;
}
int BDatabase::addbook(int n, char *na, int bnum) {
	Book* p = query(n);
	if (p == NULL) {
		top++;
		book[top].addbook(n, na, bnum);
		return 1;
	}
	return 0;
}
void BDatabase::list() {
	if (top == -1) {
		cout << "ͼ���û�д洢ͼ��" << endl;
		return;
	}
	for (int i = 0; i <= top; i++) {
	    book[i].list();
	}
}
BDatabase::~BDatabase() {
	fstream file;
	file.open("book.txt", ios::out | ios::binary);
	for (int i = 0; i <= top; i++) {
		if (book[i].getnote() == 0)
			file.write((char*) & book[i], sizeof(book[i]));
	}
	file.close();
}
void BDatabase::showranknum(int bid) {
	for (int i = 0; i < Maxb; i++) {
		if (book[i].getranknum() == bid) {
			cout << "��ͼ���Ŷӵȴ�������" << book[i].getranknum() << "��" << endl;
			return;
		}
	}
	cout << "û���ҵ�����ѯͼ��" << endl;
}
void BDatabase::bookdata() {
	int choice = 1;
	char bookname[20];
	int bookid;
	int booknum1;
	Book* b;
	while (choice != 0) {
		cout << "----------------------------------------------------------" << endl;
		cout << "ͼ��ά����" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 7���鿴ͼ������ 0���˳�" << endl;
		//cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 0:break;
		case 1://����
			cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "����ͼ������";
				cin >> bookname;
				cout << "����ͼ��������";
				int num;
				cin >> num;
				addbook(bookid, bookname, num);
			}
			else {
				cout << "����ͼ��������";
				int num;
				cin >> num;
				b->setbooknum(num + b->getbooknum());
				b->setonshelf(num + b->getonshelf());
			}
			break;
		case 2://����
			cout << "��ѡ����Ҫ�޸ĵĵط�" << endl;
			cout << "---1��ͼ���� 2��ͼ������ 3��ͼ���ڼ����� 4��ͼ���ܹ����� 0���˳�---" << endl;
			cin >> choice;
			switch (choice) {
			case 0:
				cout << "�˳���ҳ��" << endl;
				break;
			case 1:
				cout << "����ͼ�����֣�";
				cin >> bookname;
				b = queryname(bookname);
				if (b == NULL) {
					cout << "�Ҳ�����ͼ�飬�������" << endl;
					break;
				}
				cout << "�����ͼ���ţ�";
				cin >> bookid;
				b->setbookid(bookid);
				cout << "���ĳɹ�" << endl;
				break;
			case 2:
				cout << "����ͼ���ţ�";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "�Ҳ�����ͼ�飬�������" << endl;
					break;
				}
				cout << "�����ͼ������" << endl;
				cin >> bookname;
				b->setname(bookname);
				cout << "���ĳɹ�" << endl;
				break;
			case 3:
				cout << "����ͼ���ţ�";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "�Ҳ�����ͼ�飬�������" << endl;
					break;
				}
				cout << "�����ͼ���ڼ�������";
				cin >> booknum1;
				b->setonshelf(booknum1);
				cout << "�޸ĳɹ�" << endl;
				break;
			case 4:
				cout << "����ͼ���ţ�";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "�Ҳ�����ͼ�飬�������" << endl;
					break;
				}
				cout << "�����ͼ�����������";
				cin >> booknum1;
				b->setbooknum(booknum1);
				break;
			default:
				cout << "��������˳���ҳ��" << endl;
				break;
			}// end switch
			break;
		case 3://ɾ��
			cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) cout << "��ͼ�鲻���ڣ�" << endl;
			else if (b != NULL) {
				if (b->getonshelf() < b->getbooknum()) {
					cout << "���鱻���߽����ˣ�ɾ��ʧ��" << endl;
					break;
				}
				b->delbook();
			}
			break;
		case 4://����
			cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻����" << endl;
				break;
			}
			b->list();
			break;
		case 5://��ʾ
			list(); break;
		case 6://ȫɾ
			clear();
			break;
		//case 7://���Ŷӽ�������
		//	cout << "�����ѯͼ��ı��";
		//	cin >> bookid;
		//	b = query(bookid);
		//	if (b == NULL) {
		//		cout << "��ͼ�鲻����" << endl;
		//		break;
		//	}
		//	showranknum(bookid);
		//	break;
		case 7:
			cout << "�����ѯͼ��ı�ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻����" << endl;
				break;
			}
			cout << "��ͼ���ܹ�������" << b->showbooknum() << "�����ֽ��ڼܵ�ͼ�黹��" 
				<< b->getonshelf() << "��" << endl;
			break;
		default:
			cout << "������󣬷���ѡ��ҳ��" << endl;
			break;
		}//end switch
		cout << endl;
	}//end while
}//end batabase()