#pragma once
#ifndef _book_h_
#define _book_h_
#include<iostream>
using namespace std;
class Book {
public:
	Book();
	Book(const Book& b);
	Book(int n, int num, char ming[], int on, int booknum1, int bnum);
	~Book() {};
	char* getname();//获得书名
	int getnote();//获得删除标记
	int getnumber();//获得图书编号
	int getonshelf();//获得图书上架标记
	int getbooknum();//获得图书藏书数量
	int getranknum();//获得排队借该图书的人数
	void setname(char na[]);//设置书名
	void setbookid(int id);
	void setonshelf(int i);
	void setbooknum(int i);
	void delbook();//删除图书
	void addbook(int n, char* na, int num);//添加图书
	void borrowbook();//借书操作，onshelf>0为在架，=0为被借走了
	void retbook();//还书操作
	void list();//输出图书
	int showbooknum();//输出图书藏书数量
	void onshelfjia() { onshelf++; }
	void onshelfjian() { onshelf--; }
	//void setbooknum(int num);//设置图书藏书数量
private:
	int note;//删除标记，1为已删，0为未删
	int number;//图书编号
	char name[10];//书名
	int onshelf;//上架标志, 改为书籍数量
	int booknum;//藏书数量
	int ranknum;//该书排队借书人数
};
#endif // !_book_h_