#pragma once
#include<iostream>
#include<string>
using namespace std;

class Doggo //добавить породы-наследники
{
private:
	//ƒобавить полей
	string name;
	string color;
	string size;

public:
	Doggo() : name(""), color(""), size("") {}
	virtual ~Doggo() {}

	virtual void modify(int ch, string inf);
	
	virtual void set_inf();
	virtual void show_inf();
	virtual void write_inf(int cnt, string file);
	virtual void read_inf(int cnt);

	
	virtual void breed() = 0;


	void SetNam(string nam) { name = nam; }
	void SetCol(string col) { color = col; }
	void SetSz(string sz) { size = sz; }

	string GetNam() { return name; }
	string GetCol() { return color; }
	string GetSz() { return size; }

};