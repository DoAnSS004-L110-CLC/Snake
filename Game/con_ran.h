#pragma once
#include"do_hoa.h"
#include<fstream>

typedef struct toado {
	int x;
	int y;
}Toa_Do;
typedef struct toa_do_tuong {
	Toa_Do p_dau{};
	Toa_Do p_cuoi{};
} Toa_Do_Tuong;


class Con_Ran {
private:
	vector<Toa_Do> than_ran;
	int chieu_dai_than_ran;
	int huong_dang_di_chuyen;		//1 - len ,  2 -  xuong ,  3 - phai ,  4 - trai
	int toc_do;
public:
	Con_Ran();

	void set_huong_di_chuyen(int);
	void set_toc_do(int);
	void ran_di_chuyen(const int&, const Toa_Do_Tuong&, const vector<Toa_Do>&);
	void ran_an_moi();

	const vector<Toa_Do>& con_ran();

	bool ran_die(const Toa_Do_Tuong&, const vector<Toa_Do>&, const int&);
	int get_toc_do() const;
	int get_chieu_dai_ran() const;
	int get_huong_di_chuyen() const;

	~Con_Ran();
};


void di_chuyen_than_ran(vector<Toa_Do>& ran, Toa_Do toadothanmoi) {
	Toa_Do toadothancu;
	for (size_t i = 1; i < ran.size(); i++) {
		toadothancu = ran.at(i);
		ran.at(i) = toadothanmoi;
		toadothanmoi = toadothancu;
	}
}

Con_Ran::Con_Ran() {
	Toa_Do point;
	if (than_ran.size() != 0) than_ran.clear();
	chieu_dai_than_ran = 1;
	point.x = 148;	point.y = 15;
	than_ran.push_back(point);
	toc_do = 10;
	huong_dang_di_chuyen = 4;
}

void Con_Ran::set_huong_di_chuyen(int hdc) {
	if ((get_huong_di_chuyen() == 1 || get_huong_di_chuyen() == 2) && (hdc == 3 || hdc == 4))
		huong_dang_di_chuyen = hdc;
	else if ((get_huong_di_chuyen() == 3 || get_huong_di_chuyen() == 4) && (hdc == 1 || hdc == 2))
		huong_dang_di_chuyen = hdc;
}
void Con_Ran::set_toc_do(int td) {
	toc_do = td;
}

void Con_Ran::ran_di_chuyen(const int&cdo, const Toa_Do_Tuong& vach_tuong, const vector<Toa_Do>& dich_chuyen) {
	Toa_Do toa_do_node_dau_ran_trc_khi_di_chuyen = than_ran.at(0);
	//di chuyen phan dau
	switch (huong_dang_di_chuyen) {
	case 1: than_ran.at(0).y -= 1;	//len
		break;
	case 2: than_ran.at(0).y += 1;	//xuong
		break;
	case 3: than_ran.at(0).x += 1;	//phai
		break;
	case 4: than_ran.at(0).x -= 1;	//trai
		break;
	}
	if (cdo == 2) {
		if (than_ran.at(0).x == vach_tuong.p_dau.x) than_ran.at(0).x = vach_tuong.p_cuoi.x - 1;
		if (than_ran.at(0).x == vach_tuong.p_cuoi.x) than_ran.at(0).x = vach_tuong.p_dau.x + 1;
		if (than_ran.at(0).y == vach_tuong.p_dau.y) than_ran.at(0).y = vach_tuong.p_cuoi.y - 1;
		if (than_ran.at(0).y == vach_tuong.p_cuoi.y) than_ran.at(0).y = vach_tuong.p_dau.y + 1;
	}
	else if (cdo == 3) {
		if ((than_ran.at(0).x >= 68 && than_ran.at(0).x <= 73) && than_ran.at(0).y == 33) {
			than_ran.at(0).y = than_ran.at(0).x - 55;
			than_ran.at(0).x = 148;
			huong_dang_di_chuyen = 4;
		}
		if ((than_ran.at(0).y >= 13 && than_ran.at(0).y <= 18) && than_ran.at(0).x == 149) {
			than_ran.at(0).x = than_ran.at(0).y + 55;
			than_ran.at(0).y = 32;
			huong_dang_di_chuyen = 1;
		}
	}
	//di chuyen phan than
	di_chuyen_than_ran(than_ran, toa_do_node_dau_ran_trc_khi_di_chuyen);
	return;
}
void Con_Ran::ran_an_moi() {
	Toa_Do add_node = than_ran.at(chieu_dai_than_ran - 1);
	than_ran.push_back(add_node);
	chieu_dai_than_ran = than_ran.size();
}

bool Con_Ran::ran_die(const Toa_Do_Tuong& toadotuong, const vector<Toa_Do>& vatcan, const int& cdo) {
	//ran tu can minh
	for (int i = 1; i < chieu_dai_than_ran; i++)
		if (than_ran.at(0).x == than_ran.at(i).x && than_ran.at(0).y == than_ran.at(i).y) return true;
	
	//ran dung vach tuong
	if (than_ran.at(0).x == toadotuong.p_dau.x || than_ran.at(0).x == toadotuong.p_cuoi.x ||
		than_ran.at(0).y == toadotuong.p_dau.y || than_ran.at(0).y == toadotuong.p_cuoi.y) return true;
	for (size_t i = 0; i < vatcan.size(); i++)
		if (than_ran.at(0).x == vatcan.at(i).x && than_ran.at(0).y == vatcan.at(i).y) return true;
	return false;
}
int Con_Ran::get_toc_do() const  {
	return toc_do;
}
int Con_Ran::get_chieu_dai_ran() const  {
	return chieu_dai_than_ran;
}
int Con_Ran::get_huong_di_chuyen() const  {
	return huong_dang_di_chuyen;
}
const vector<Toa_Do>& Con_Ran::con_ran() {
	return than_ran;
}

Con_Ran::~Con_Ran() {}
