#pragma once
#ifndef _reader_h_
#define _reader_h_
//#include"bdatabase.h"
const int Maxbor = 5;//最大借阅量
class Reader {
public:
	Reader();
	Reader(int n, int num, char na[], int b[], int r[][2]);
	Reader(const Reader& r);
	~Reader() {};
	char* getname();
	int getnote();
	int getnumber();
	void setname(char na[]);
	void delreader();
	void addreader(int n, char* na);
	int borrowbook(int bookid);
	int retbook(int bookid);
	int getbook();//判断是否有借书
	void list();
	void showrankoreder(int bid);
private:
	int note;//删除读者标记，1已删，0未删
	int number;//读者编号
	char name[10];//读者姓名
	int borbook[Maxbor];//所借图书
	int rankorder[Maxbor][2];//等待借书的编号和次序
};
#endif // !_reader_h_