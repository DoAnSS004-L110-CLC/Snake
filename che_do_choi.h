#pragma once
#include"do_hoa.h"
#include"con_ran.h"

class Che_Do_Choi {
private:
	vector <Toa_Do> vat_can;
	int che_do;
public:
	Che_Do_Choi();

	void che_do_choi_I();
	void che_do_choi_II();
	void che_do_choi_III();
	void set_che_do(int);
	int get_che_do() const;
	string get_che_do_choi_lama() const;
	const vector<Toa_Do>& get_vatcan() const;

	~Che_Do_Choi();
};

string che_do_choi_lama(int c_do) {
	string chedo;
	switch (c_do) {
	case 1: chedo = "I  ";
		break;
	case 2: chedo = "II ";
		break;
	case 3: chedo = "III";
		break;
	default: chedo = "";
	}
	return chedo;
}

Che_Do_Choi::Che_Do_Choi() {
	set_che_do(1);
}
Che_Do_Choi::~Che_Do_Choi() {}

void Che_Do_Choi::set_che_do(int a) {
	switch (a) {
	case 1: che_do = 1;
		che_do_choi_I();
		break;
	case 2: che_do = 2;
		che_do_choi_II();
		break;
	case 3: che_do = 3;
		che_do_choi_III();
		break;
	}
}
int Che_Do_Choi::get_che_do() const{
	return che_do;
}
string Che_Do_Choi::get_che_do_choi_lama() const  {
	return che_do_choi_lama(che_do);
}
const vector<Toa_Do>& Che_Do_Choi::get_vatcan() const  {
	return vat_can;
}

void Che_Do_Choi::che_do_choi_I() {
	if (vat_can.size() > 0) vat_can.clear();
}
void Che_Do_Choi::che_do_choi_II() {
	if (vat_can.size() > 0) vat_can.clear();
	ifstream doc_file_toado("toa_do_vach_tuong_II.txt");
	if (!doc_file_toado) return;
	Toa_Do toado;
	while (!doc_file_toado.eof()) {
		doc_file_toado >> toado.x;
		doc_file_toado >> toado.y;
		vat_can.push_back(toado);
	}
	doc_file_toado.close();
}
void Che_Do_Choi::che_do_choi_III() {
	if (vat_can.size() > 0) vat_can.clear();
	ifstream doc_file_toado("toa_do_vach_tuong_III.txt");
	if (!doc_file_toado) return;
	Toa_Do toado;
	while (!doc_file_toado.eof()) {
		doc_file_toado >> toado.x;
		doc_file_toado >> toado.y;
		vat_can.push_back(toado);
	}
	doc_file_toado.close();
}