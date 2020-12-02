#pragma once
#include"do_hoa.h"
typedef struct toado {
	int x;
	int y;
}Toa_Do;
typedef struct thanran {
	Toa_Do toadoxy;
	thanran* next;
}Than_Ran;
typedef struct toa_do_tuong {
	Toa_Do p_dau;
	Toa_Do p_cuoi;
	vector<Toa_Do> vat_can;
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
	void ran_di_chuyen();
	void ran_an_moi();

	Than_Ran* con_ran();

	bool ran_die(const Toa_Do_Tuong&);
	int get_toc_do();
	int get_chieu_dai_ran();
	int get_huong_di_chuyen();

	~Con_Ran();
};


Con_Ran::Con_Ran() {
	than_ran = new Than_Ran;
	than_ran->toadoxy.x = 80;		than_ran->toadoxy.y = 10;
	than_ran->next = NULL;
	chieu_dai_than_ran = 1;
	toc_do = 10;
	huong_dang_di_chuyen = 3;
}

void Con_Ran::set_huong_di_chuyen(int hdc) {
	if ((get_huong_di_chuyen() == 1 || get_huong_di_chuyen() == 2)
		&& (hdc == 3 || hdc == 4))	huong_dang_di_chuyen = hdc;
	else if ((get_huong_di_chuyen() == 3 || get_huong_di_chuyen() == 4)
		&& (hdc == 1 || hdc == 2))	huong_dang_di_chuyen = hdc;
}

void Con_Ran::set_toc_do(int td) {
	toc_do = td;
}

void di_chuyen_than(Than_Ran*& ran, Than_Ran node) {
	if (ran == NULL) return;
	Than_Ran node_;
	node_.toadoxy.x = ran->toadoxy.x;	node_.toadoxy.y = ran->toadoxy.y;
	ran->toadoxy.x = node.toadoxy.x;		ran->toadoxy.y = node.toadoxy.y;
	di_chuyen_than(ran->next, node_);
}
void Con_Ran::ran_di_chuyen() {
	Than_Ran node = *than_ran;
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
	di_chuyen_than(than_ran->next, node);
	/*	di chuyen phan than
	Than_Ran node_;
	node_ = than_ran;
	while (than_ran->next != NULL) {
		than_ran = than_ran->next;
		node_ = *than_ran;
		than_ran->x = node.x;
		than_ran->y = node.y;
		node = node_;
	}*/
}

void them_node(Than_Ran*& ran, Than_Ran node) {
	if (ran == NULL) {
		Than_Ran* nw = new Than_Ran;
		nw->toadoxy.x = node.toadoxy.x;	nw->toadoxy.y = node.toadoxy.y;	nw->next = NULL;
		ran = nw;
	}
	else {
		node = *ran;
		them_node(ran->next, node);
	}
}
void Con_Ran::ran_an_moi() {
	chieu_dai_than_ran++;
	Than_Ran node = *than_ran;
	them_node(than_ran->next, node);
}

bool Con_Ran::ran_die(const Toa_Do_Tuong& toadotuong) {
	//ran tu can minh
	Than_Ran dau_ran = *than_ran;
	Than_Ran* ran = than_ran;
	ran = ran->next;
	while (ran != NULL) {
		if (dau_ran.toadoxy.x == ran->toadoxy.x && dau_ran.toadoxy.y == ran->toadoxy.y) return true;
		ran = ran->next;
	}
	//ran dung vach tuong
	if (dau_ran.toadoxy.x == toadotuong.p_dau.x || dau_ran.toadoxy.x == toadotuong.p_cuoi.x ||
		dau_ran.toadoxy.y == toadotuong.p_dau.y || dau_ran.toadoxy.y == toadotuong.p_cuoi.y) return true;
	for (int i = 0; i < toadotuong.vat_can.size(); i++)
		if (dau_ran.toadoxy.x == toadotuong.vat_can.at(i).x && dau_ran.toadoxy.y == toadotuong.vat_can.at(i).y) return true;
	return false;
}

int Con_Ran::get_toc_do() {
	return toc_do;
}

int Con_Ran::get_chieu_dai_ran() {
	return chieu_dai_than_ran;
}

int Con_Ran::get_huong_di_chuyen() {
	return huong_dang_di_chuyen;
}

Than_Ran* Con_Ran::con_ran() {
	//Than_Ran* thanran_copy;
	//memcpy(thanran_copy, this->than_ran, this->chieu_dai_than_ran);
	//return thanran_copy;
	return this-> than_ran;
}

Con_Ran::~Con_Ran() {}