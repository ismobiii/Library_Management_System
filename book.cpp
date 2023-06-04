#include"stdafx.h"
#include"book.h"
#include<iomanip>
Book::Book()
{
	note = 1;
	number = 0;
	name[0] = '\0';
	onshelf = 0;
	booknum = 0;
	ranknum = 0;
}
Book::Book(const Book& b)
{
	this->note = b.note;
	this->number = b.number;
	strcpy_s(name, strlen(b.name) + 1, b.name);
	this->onshelf = b.onshelf;
	this->booknum = b.booknum;
	this->ranknum = b.ranknum;
}
Book::Book(int n, int num, char ming[], int on, int booknum1, int bnum) {
	note = n;
	number = num;
	strcpy_s(name, strlen(ming) + 1, ming);
	onshelf = on;
	booknum = booknum1;
	ranknum = bnum;
}
char* Book::getname() {
	return name;
}
int Book::getnote()
{
	return note;
}
int Book::getnumber() {
	return number;
}
int Book::getonshelf() {
	return onshelf;
}
int Book::getranknum() {
	return ranknum;
}
int Book::getbooknum() {
	return booknum;
}
void Book::setname(char na[]) {
	strcpy_s(name, strlen(na) + 1, na);
}
void Book::setbookid(int id) {
	this->booknum = id;
}
void Book::setonshelf(int i) {
	onshelf = i;
}
void Book::setbooknum(int i) {
	booknum = i;
}
void Book::delbook() {
	note = 1;
}
void Book::addbook(int n, char* na, int num) {
	note = 0;
	number = n;
	strcpy_s(name, strlen(na) + 1, na);
	onshelf = num;
	booknum = num;
	ranknum = 0;
}
void Book::borrowbook() {
	onshelf--;
	//return onshelf;
}
void Book::retbook() {
	onshelf++;
	//ranknum--;
}
void Book::list() {
	if (note == 1)return;
	else if (note == 0)
		cout << setw(5) << "图书编号:" << number
		<< setw(10) << "书名：" << name
		<< setw(20) << "图书在架数量：" << onshelf
		<< setw(20) << "图书藏书数量：" << booknum << endl;
		//<< setw(20) << "排队人数：" << ranknum << endl;
}
int Book::showbooknum() {
	return booknum;
}
//void Book::setbooknum(int num) {
//	booknum = num;
//}