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
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "---------------------------------------" << endl;
	while (choice != 0) {
		cout << "---------------------------------------" << endl;
		cout << "1：借书 2：还书 3：图书维护 4：读者维护 0：离开" << endl;
		cin >> choice;
		cout << endl;
		cout << "\n";
		switch (choice) {
		case 0:break;
		case 1:
			cout << "输入借书读者编号：";
			cin >> readerid;
            r = ReaderDB.query(readerid);
			if (r == NULL) {
				cout << "该读者不存在，不能借书" << endl;
				break;
			}
			cout << "输入读者借的图书编号：";
			cin >> bookid;
			b = BookDB.query(bookid);
			if (b == NULL) {
				cout << "该图书不存在，不能借书" << endl;
				break;
			}
			if (b->getonshelf() == 0) {
				cout << "该图书已全被借出，不能借书" << endl;
				break;
			}
			r->borrowbook(b->getnumber());
			b->onshelfjian();
			//b->setonshelf(0);
			break;
		case 2:
			cout << "输入还书读者编号";
			cin >> readerid;
			cout << "输入图书编号";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL) {
				cout << "该读者不存在，不能借出" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL) {
				cout << "该图书不存在，不能借出" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getnumber());
			//b->onshelfjia();与63行一样的作用
			break;
		case 3:
			BookDB.bookdata();
			break;
		case 4:
			ReaderDB.readerdata();
			break;
		default:
			cout << "输入错误，返回选择页面" << endl;
			break;
		}//end switch
		cout << endl;
	}//end while
	return 0;
}