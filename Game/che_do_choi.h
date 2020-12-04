#pragma once
#include"do_hoa.h"
#include"con_ran.h"

class Che_Do_Choi {
private:
	vector <Toa_Do> vat_can;
	string che_do;
public:
	Che_Do_Choi();

	void che_do_choi_de();
	void che_do_choi_trung_binh();
	void che_do_choi_kho();
	void set_che_do(int);
	string get_che_do();
	const vector<Toa_Do>& get_vatcan();

	~Che_Do_Choi();
};


Che_Do_Choi::Che_Do_Choi() {
	che_do = "De";
}
Che_Do_Choi::~Che_Do_Choi() {}

void Che_Do_Choi::set_che_do(int a) {
	switch (a) {
	case 1: che_do = "De";
		che_do_choi_de();
		break;
	case 2: che_do = "Trung binh";
		che_do_choi_trung_binh();
		break;
	case 3: che_do = "Kho";
		che_do_choi_kho();
		break;
	}
}
string Che_Do_Choi::get_che_do() {
	return che_do;
}
const vector<Toa_Do>& Che_Do_Choi::get_vatcan() {
	return vat_can;
}

void Che_Do_Choi::che_do_choi_de() {
	// No thing
}
void Che_Do_Choi::che_do_choi_trung_binh() {
	//
}
void Che_Do_Choi::che_do_choi_kho() {
	//
}
