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
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//���ͼ����
	int getonshelf();//���ͼ���ϼܱ��
	int getbooknum();//���ͼ���������
	int getranknum();//����Ŷӽ��ͼ�������
	void setname(char na[]);//��������
	void setbookid(int id);
	void setonshelf(int i);
	void setbooknum(int i);
	void delbook();//ɾ��ͼ��
	void addbook(int n, char* na, int num);//���ͼ��
	void borrowbook();//���������onshelf>0Ϊ�ڼܣ�=0Ϊ��������
	void retbook();//�������
	void list();//���ͼ��
	int showbooknum();//���ͼ���������
	void onshelfjia() { onshelf++; }
	void onshelfjian() { onshelf--; }
	//void setbooknum(int num);//����ͼ���������
private:
	int note;//ɾ����ǣ�1Ϊ��ɾ��0Ϊδɾ
	int number;//ͼ����
	char name[10];//����
	int onshelf;//�ϼܱ�־, ��Ϊ�鼮����
	int booknum;//��������
	int ranknum;//�����Ŷӽ�������
};
#endif // !_book_h_