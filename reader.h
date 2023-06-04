#pragma once
#ifndef _reader_h_
#define _reader_h_
//#include"bdatabase.h"
const int Maxbor = 5;//��������
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
	int getbook();//�ж��Ƿ��н���
	void list();
	void showrankoreder(int bid);
private:
	int note;//ɾ�����߱�ǣ�1��ɾ��0δɾ
	int number;//���߱��
	char name[10];//��������
	int borbook[Maxbor];//����ͼ��
	int rankorder[Maxbor][2];//�ȴ�����ı�źʹ���
};
#endif // !_reader_h_