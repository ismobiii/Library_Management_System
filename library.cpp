#include"stdafx.h"
#include"reader.h"
#include"rdatabase.h"
#include"book.h"
#include"bdatabase.h"
#include<iostream>
using namespace std;
int main()
{
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;
	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;
	cout << "---------------------------------------" << endl;
	while (choice != 0) {
		cout << "---------------------------------------" << endl;
		cout << "1������ 2������ 3��ͼ��ά�� 4������ά�� 0���뿪" << endl;
		cin >> choice;
		cout << endl;
		cout << "\n";
		switch (choice) {
		case 0:break;
		case 1:
			cout << "���������߱�ţ�";
			cin >> readerid;
            r = ReaderDB.query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ����ܽ���" << endl;
				break;
			}
			cout << "������߽��ͼ���ţ�";
			cin >> bookid;
			b = BookDB.query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ����ܽ���" << endl;
				break;
			}
			if (b->getonshelf() == 0) {
				cout << "��ͼ����ȫ����������ܽ���" << endl;
				break;
			}
			r->borrowbook(b->getnumber());
			b->onshelfjian();
			//b->setonshelf(0);
			break;
		case 2:
			cout << "���뻹����߱��";
			cin >> readerid;
			cout << "����ͼ����";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ����ܽ��" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ����ܽ��" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getnumber());
			//b->onshelfjia();��63��һ��������
			break;
		case 3:
			BookDB.bookdata();
			break;
		case 4:
			ReaderDB.readerdata();
			break;
		default:
			cout << "������󣬷���ѡ��ҳ��" << endl;
			break;
		}//end switch
		cout << endl;
	}//end while
	return 0;
}