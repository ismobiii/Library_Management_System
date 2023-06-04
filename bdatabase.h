#pragma once
#ifndef _bdatabase_h_
#define _bdatabase_h_
#include"book.h"
#include<iostream>
using namespace std;
const int Maxb = 100;
class BDatabase {
public:
	BDatabase();
	void clear();
	int addbook(int n, char* na, int bnum);
	Book* query(int bookid);
	Book* queryname(char* na);
	void list();
	void bookdata();
	~BDatabase();
	void showranknum(int bid);
	//void showbookdata();
	//void save();
	//void initbook();
	//int getbooknum();
private:
	int top;//图书记录指针
	Book book[Maxb];//图书记录
};
#endif // !_bdatabase_h_
