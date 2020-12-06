#pragma once
#include"do_hoa.h"
#include<fstream>

typedef struct toado {
	int x;
	int y;
}Toa_Do;
typedef struct thanran {
	Toa_Do toadoxy;
	thanran* next;
}Than_Ran;
typedef struct toa_do_tuong {
	Toa_Do p_dau{};
	Toa_Do p_cuoi{};
} Toa_Do_Tuong;

class Con_Ran {
private:
	Than_Ran* than_ran;
	int chieu_dai_than_ran;
	int huong_dang_di_chuyen;		//1 - len ,  2 -  xuong ,  3 - phai ,  4 - trai
	int toc_do;
public:
	Con_Ran();

	void set_huong_di_chuyen(int);
	void set_toc_do(int);
	void ran_di_chuyen(const int&, const Toa_Do_Tuong&, const vector<Toa_Do>&);
	void ran_an_moi();

	Than_Ran* con_ran();

	bool ran_die(const Toa_Do_Tuong&, const vector<Toa_Do>&, const int&);
	int get_toc_do() const;
	int get_chieu_dai_ran() const;
	int get_huong_di_chuyen() const;

	~Con_Ran();
};

Toa_Do node_duoi_ran(Than_Ran* rangoc) {
	Than_Ran* ran = rangoc;
	while (ran->next != NULL)
		ran = ran->next;
	return ran->toadoxy;
}
void them_node(Than_Ran*& con_ran, const Toa_Do& toadomoi) {
	if (con_ran == NULL) {
		con_ran = new Than_Ran;
		con_ran->toadoxy.x = toadomoi.x;
		con_ran->toadoxy.y = toadomoi.y;
		con_ran->next = NULL;
	}
	else them_node(con_ran->next, toadomoi);
}
void di_chuyen_than_ran(Than_Ran* ran, const Toa_Do& toadocu) {
	if (ran == NULL) return;
	Toa_Do toa_do_node_than_ran_trc_khi_di_chuyen = ran->toadoxy;
	toa_do_node_than_ran_trc_khi_di_chuyen.x = ran->toadoxy.x;
	toa_do_node_than_ran_trc_khi_di_chuyen.y = ran->toadoxy.y;

	ran->toadoxy.x = toadocu.x;		ran->toadoxy.y = toadocu.y;
	di_chuyen_than_ran(ran->next, toa_do_node_than_ran_trc_khi_di_chuyen);
}

Con_Ran::Con_Ran() {
	than_ran = new Than_Ran;
	than_ran->toadoxy.x = 148;		than_ran->toadoxy.y = 15;
	than_ran->next = NULL;
	chieu_dai_than_ran = 1;
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
	Toa_Do toa_do_node_than_ran_trc_khi_di_chuyen = than_ran->toadoxy;
	//di chuyen phan dau
	switch (huong_dang_di_chuyen) {
	case 1: than_ran->toadoxy.y -= 1;	//len
		break;
	case 2: than_ran->toadoxy.y += 1;	//xuong
		break;
	case 3: than_ran->toadoxy.x += 1;	//phai
		break;
	case 4: than_ran->toadoxy.x -= 1;	//trai
		break;
	}
	//di chuyen phan than
	di_chuyen_than_ran(than_ran->next, toa_do_node_than_ran_trc_khi_di_chuyen);
	//dich chuyen vi tri ran
	if (cdo == 2) {
		if (than_ran->toadoxy.x == vach_tuong.p_dau.x) than_ran->toadoxy.x = vach_tuong.p_cuoi.x - 1;
		if (than_ran->toadoxy.x == vach_tuong.p_cuoi.x) than_ran->toadoxy.x = vach_tuong.p_dau.x + 1;
		if (than_ran->toadoxy.y == vach_tuong.p_dau.y) than_ran->toadoxy.y = vach_tuong.p_cuoi.y - 1;
		if (than_ran->toadoxy.y == vach_tuong.p_cuoi.y) than_ran->toadoxy.y = vach_tuong.p_dau.y + 1;
	}
	else if (cdo == 3) {
		if ((than_ran->toadoxy.x >= 68 && than_ran->toadoxy.x <= 73) && than_ran->toadoxy.y == 33) {
			than_ran->toadoxy.y = than_ran->toadoxy.x - 55;
			than_ran->toadoxy.x = 148;
			huong_dang_di_chuyen = 4;
		}
		if ((than_ran->toadoxy.y >= 13 && than_ran->toadoxy.y <= 18) && than_ran->toadoxy.x == 149) {
			than_ran->toadoxy.x = than_ran->toadoxy.y + 55;
			than_ran->toadoxy.y = 32;
			huong_dang_di_chuyen = 1;
		}
	}
	else return;

}
void Con_Ran::ran_an_moi() {
	chieu_dai_than_ran++;
	Toa_Do toa_do_moi = node_duoi_ran(than_ran);
	them_node(than_ran, toa_do_moi);
}

bool Con_Ran::ran_die(const Toa_Do_Tuong& toadotuong, const vector<Toa_Do>& vatcan, const int& cdo) {
	Than_Ran dau_ran = *than_ran;
	Than_Ran* than_bung_ran = dau_ran.next;
	//ran tu can minh
	while (than_bung_ran != NULL) {
		if (dau_ran.toadoxy.x == than_bung_ran->toadoxy.x && dau_ran.toadoxy.y == than_bung_ran->toadoxy.y) return true;
		than_bung_ran = than_bung_ran->next;
	}
	//ran dung vach tuong
	if (dau_ran.toadoxy.x == toadotuong.p_dau.x || dau_ran.toadoxy.x == toadotuong.p_cuoi.x ||
		dau_ran.toadoxy.y == toadotuong.p_dau.y || dau_ran.toadoxy.y == toadotuong.p_cuoi.y) return true;
	for (size_t i = 0; i < vatcan.size(); i++)
		if (dau_ran.toadoxy.x == vatcan.at(i).x && dau_ran.toadoxy.y == vatcan.at(i).y) return true;
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
Than_Ran* Con_Ran::con_ran() {
	return this-> than_ran;
}

Con_Ran::~Con_Ran() {}