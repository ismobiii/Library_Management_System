#pragma once
#ifndef _rdatabase_h_
#define _rdatabase_h_
#include"stdafx.h"
#include"reader.h"
#include"book.h"
#include<iostream>
using namespace std;
const int Maxr = 100;
struct borbookrank
{
	int bookid;//�������ı��
	int num;//��ͼ�����ж��������Ŷӵȴ�����
};
class RDatabase {
public:
	RDatabase();
	void clear();
	int addreader(int n, char* na);
	Reader* query(int readerid);
	void list();
	void readerdata();
	~RDatabase();
private:
	int top;
	Reader read[Maxr];
};
#endif // !_rdatabase_h_
