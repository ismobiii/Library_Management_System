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
		cout << "文件不存在" << endl;
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
		cout << "图书库没有存储图书" << endl;
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
			cout << "该图书排队等待借书有" << book[i].getranknum() << "人" << endl;
			return;
		}
	}
	cout << "没有找到所查询图书" << endl;
}
void BDatabase::bookdata() {
	int choice = 1;
	char bookname[20];
	int bookid;
	int booknum1;
	Book* b;
	while (choice != 0) {
		cout << "----------------------------------------------------------" << endl;
		cout << "图书维护：" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 7、查看图书数量 0：退出" << endl;
		//cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 0:break;
		case 1://新增
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "输入图书名：";
				cin >> bookname;
				cout << "输入图书数量：";
				int num;
				cin >> num;
				addbook(bookid, bookname, num);
			}
			else {
				cout << "输入图书数量：";
				int num;
				cin >> num;
				b->setbooknum(num + b->getbooknum());
				b->setonshelf(num + b->getonshelf());
			}
			break;
		case 2://更改
			cout << "请选择需要修改的地方" << endl;
			cout << "---1、图书编号 2、图书名字 3、图书在架数量 4、图书总共藏量 0、退出---" << endl;
			cin >> choice;
			switch (choice) {
			case 0:
				cout << "退出此页面" << endl;
				break;
			case 1:
				cout << "输入图书名字：";
				cin >> bookname;
				b = queryname(bookname);
				if (b == NULL) {
					cout << "找不到该图书，输入错误" << endl;
					break;
				}
				cout << "请更改图书编号：";
				cin >> bookid;
				b->setbookid(bookid);
				cout << "更改成功" << endl;
				break;
			case 2:
				cout << "输入图书编号：";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "找不到该图书，输入错误" << endl;
					break;
				}
				cout << "请更改图书名字" << endl;
				cin >> bookname;
				b->setname(bookname);
				cout << "更改成功" << endl;
				break;
			case 3:
				cout << "输入图书编号：";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "找不到该图书，输入错误" << endl;
					break;
				}
				cout << "请更改图书在架数量：";
				cin >> booknum1;
				b->setonshelf(booknum1);
				cout << "修改成功" << endl;
				break;
			case 4:
				cout << "输入图书编号：";
				cin >> bookid;
				b = query(bookid);
				if (b == NULL) {
					cout << "找不到该图书，输入错误" << endl;
					break;
				}
				cout << "请更改图书藏书数量：";
				cin >> booknum1;
				b->setbooknum(booknum1);
				break;
			default:
				cout << "输入错误，退出此页面" << endl;
				break;
			}// end switch
			break;
		case 3://删除
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) cout << "该图书不存在！" << endl;
			else if (b != NULL) {
				if (b->getonshelf() < b->getbooknum()) {
					cout << "该书被读者借走了，删除失败" << endl;
					break;
				}
				b->delbook();
			}
			break;
		case 4://查找
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "该图书不存在" << endl;
				break;
			}
			b->list();
			break;
		case 5://显示
			list(); break;
		case 6://全删
			clear();
			break;
		//case 7://查排队借书人数
		//	cout << "输入查询图书的编号";
		//	cin >> bookid;
		//	b = query(bookid);
		//	if (b == NULL) {
		//		cout << "该图书不存在" << endl;
		//		break;
		//	}
		//	showranknum(bookid);
		//	break;
		case 7:
			cout << "输入查询图书的编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "该图书不存在" << endl;
				break;
			}
			cout << "该图书总共藏书有" << b->showbooknum() << "本，现今在架的图书还有" 
				<< b->getonshelf() << "本" << endl;
			break;
		default:
			cout << "输入错误，返回选择页面" << endl;
			break;
		}//end switch
		cout << endl;
	}//end while
}//end batabase()