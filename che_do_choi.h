#pragma once
#include"do_hoa.h"

class Che_Do_Choi {
private:
	string che_do;
public:
	Che_Do_Choi();

	void set_che_do(int);
	string get_che_do();

	~Che_Do_Choi();
};

Che_Do_Choi::Che_Do_Choi() {
	che_do = 1;
}

Che_Do_Choi::~Che_Do_Choi() {}

void Che_Do_Choi::set_che_do(int a) {
	switch (a)
	{
	case 1: che_do = "De";
		break;
	case 2: che_do = "Trung binh";
		break;
	case 3: che_do = "Kho";
		break;
	}
}
string Che_Do_Choi::get_che_do() {
	return che_do;
}