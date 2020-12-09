#pragma once
#include"che_do_choi.h"
#include"con_ran.h"

class Tro_Choi {
private:
	Con_Ran* con_ran;
	Che_Do_Choi che_do_choi;
	Toa_Do_Tuong vachtuong;
	Toa_Do con_moi;
	int muc_do;			// 1 - de ,  2 - trung binh ,  3 - kho
	int tong_diem;
	int list_diem_cao_nhat[5];
	bool trang_thai;
public:
	Tro_Choi();

	void save_diem(const int&);
	void set_tuong(int, int, int, int);
	void set_muc_do(const int&);
	void set_list_diem_cao_nhat();
	void set_trang_thai(bool);
	void set_che_do_choi(const int&);

	void khoi_tao_ran();
	void tao_con_moi();

	void bat_dau_game();
	void ket_thuc_game();

	void su_kien_ran_an_moi();
	void su_kien_ran_di_chuyen();

	void hien_thi_ran() const;
	void hien_thi_moi() const;

	const Toa_Do_Tuong& get_vachtuong();
	const vector<Toa_Do>& get_vatcan();
	int get_list_diem_cao_nhat(const int&) const;
	int get_tong_diem() const;
	int get_muc_do() const;
	bool get_trang_thai() const;
	string get_che_do_choi_lama();
	int get_che_do_choi();

	~Tro_Choi();
};

//========================================================================================================
//========================================================================================================
void ve_vat_can(const vector<Toa_Do>& vat_can) {
	SetColor(20);
	for (size_t i = 0; i < vat_can.size(); i++) {
		if (vat_can.at(i).x < 0 && vat_can.at(i).y < 0) continue;
		if (vat_can.at(i).x >= 1000 && vat_can.at(i).y >= 1000) {
			gotoXY((vat_can.at(i).x - 1000), (vat_can.at(i).y - 1000));
			SetColor(40);
			cout << " ";
			SetColor(20);
			continue;
		}
		gotoXY(vat_can.at(i).x, vat_can.at(i).y);
		cout << " ";
	}
	SetColor(15);
}
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
int partition(vector<int>& abc, int low, int high) {
	int pivot = abc.at(high);
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && abc.at(left) > pivot) left++;
		while (right >= left && abc.at(right) < pivot) right--;
		if (left >= right) break;
		swap(abc.at(left), abc.at(right));
		left++;
		right--;
	}
	swap(abc.at(left), abc.at(high));
	return left;
}
void quickSort(vector<int>& abc, int low, int high) {
	if (low < high) {
		int pi = partition(abc, low, high);
		quickSort(abc, low, pi - 1);
		quickSort(abc, pi + 1, high);
	}
}
bool nhan_esc(int M_C = 35, int M_R = 152) {
	SetColor(240);
	gotoXY(M_R * 2 / 3 - 25, M_C / 2 - 3);		cout << in_khoang_trang(50);
	gotoXY(M_R * 2 / 3 - 25, M_C / 2 - 2);
	cout << in_khoang_trang(10) << " Ban co muon tiep tuc tro choi?" << in_khoang_trang(9);
	gotoXY(M_R * 2 / 3 - 25, M_C / 2 - 1);		cout << in_khoang_trang(50);
	gotoXY(M_R * 2 / 3 - 25, M_C / 2);				cout << in_khoang_trang(50);
	gotoXY(M_R * 2 / 3 - 15, M_C / 2);				cout << "Thoat";
	gotoXY(M_R * 2 / 3 + 8, M_C / 2);				cout << "Tiep tuc";
	gotoXY(M_R * 2 / 3 - 25, M_C / 2 + 1);		cout << in_khoang_trang(50);
	gotoXY(M_R * 2 / 3 - 15, M_C / 2);
	int a = 0;
	while (true) {
		if (a < 0) a = 9;
		if (a % 2 == 0) {
			gotoXY(M_R * 2 / 3 + 6, M_C / 2);
			SetColor(240);
			cout << "  Tiep tuc   ";
			gotoXY(M_R * 2 / 3 - 19, M_C / 2);
			SetColor(15);
			cout << "    Thoat    ";
		}
		else {
			gotoXY(M_R * 2 / 3 - 19, M_C / 2);
			SetColor(240);
			cout << "    Thoat    ";
			gotoXY(M_R * 2 / 3 + 6, M_C / 2);
			SetColor(15);
			cout << "  Tiep tuc   ";
		}
		int key;
		do 
			key = inputkey();
		while (key == -1);
		if (key == 1077) a += 1;
		else if (key == 1075) a -= 1;
		else if (key == 13) {
			int a = 0;
			if (whereX() == M_R * 2 / 3 - 6) a = 0;
			else if (whereX() == M_R * 2 / 3 + 19) a = 1;
			SetColor(15);
			for (int i = 0; i < 5; i++) {
				gotoXY(M_R * 2 / 3 - 25, M_C / 2 - 3 + i);
				cout << in_khoang_trang(50);
			}
			if (a == 0)return true;
			else return false;
		}
	}
}
int time_dung(int tocdo, int huongdichuyen) {
	int tgian = 1000 / tocdo;
	switch (huongdichuyen) {
	case 1: tgian = int(tgian * 2.2);
		break;
	case 2: tgian = int(tgian * 2.2);
		break;
	}
	return tgian;
}

/*================================================================================*/
Tro_Choi::Tro_Choi() {
	con_ran = NULL;
	che_do_choi.set_che_do(1);

	vachtuong.p_dau.x = 0;	vachtuong.p_dau.y = 0;
	vachtuong.p_cuoi.x = 0;	vachtuong.p_cuoi.y = 0;
	
	muc_do = 1;
	tong_diem = 0;
	for (int i = 0; i < 5; i++) list_diem_cao_nhat[i] = 0;
	set_list_diem_cao_nhat();
	trang_thai = false;
	con_moi.x = 0;		con_moi.y = 0;
}
void Tro_Choi::khoi_tao_ran() {
	con_ran = new Con_Ran;
	con_ran->set_toc_do(muc_do * 10);
}
inline void xoa_duoi_ran(const Toa_Do& toadoduoiran) {
	gotoXY(toadoduoiran.x, toadoduoiran.y);		cout << " ";
}

void Tro_Choi::bat_dau_game() {
	gotoXY(26, 6);		cout << get_che_do_choi_lama();
	gotoXY(25, 8);		cout << get_muc_do();

	if(con_ran==NULL)	khoi_tao_ran();
	else {
		delete con_ran;	con_ran = NULL;
		khoi_tao_ran();
	}
	tong_diem = 0;
	tao_con_moi();
	while (true) {
		gotoXY(24, 10);		cout << "       ";
		gotoXY(24, 10);		cout << get_tong_diem();
		hien_thi_ran();
		hien_thi_moi();

		const int key = inputkey();
		//1072 1077 1080 1075
		if (con_ran->get_huong_di_chuyen() == 1 || con_ran->get_huong_di_chuyen() == 2)
			Sleep(time_dung(con_ran->get_toc_do(), con_ran->get_huong_di_chuyen()));
		else if (con_ran->get_huong_di_chuyen() == 3 || con_ran->get_huong_di_chuyen() == 4)
			Sleep(time_dung(con_ran->get_toc_do(), con_ran->get_huong_di_chuyen()));

		switch (key) {
		case 27: if (nhan_esc()) {
			ket_thuc_game();
			return;
		}
			   else {
			ve_vat_can(che_do_choi.get_vatcan());
			hien_thi_moi();
			hien_thi_ran();
		}
			break;
		case 1072: con_ran->set_huong_di_chuyen(1);
			break;
		case 1080: con_ran->set_huong_di_chuyen(2);
			break;
		case 1077: con_ran->set_huong_di_chuyen(3);
			break;
		case 1075: con_ran->set_huong_di_chuyen(4);
			break;
		}
		su_kien_ran_di_chuyen();
		if (!get_trang_thai()) {
			ket_thuc_game();
			return;
		}
	}
}
void Tro_Choi::ket_thuc_game() {
	set_trang_thai(false);
	save_diem(tong_diem);
	//in thong bao da thua
	SetColor(240);
	gotoXY(vachtuong.p_cuoi.x * 2 / 3 - 25, vachtuong.p_cuoi.y / 2);		cout << in_khoang_trang(50);
	gotoXY(vachtuong.p_cuoi.x * 2 / 3 - 4, vachtuong.p_cuoi.y / 2);				cout << "KET THUC";
	for (int i = 0; i < 3; i++) {
		Sleep(150);
		gotoXY(vachtuong.p_cuoi.x * 2 / 3 - 4, vachtuong.p_cuoi.y / 2);				cout << "        ";
		Sleep(150);
		gotoXY(vachtuong.p_cuoi.x * 2 / 3 - 4, vachtuong.p_cuoi.y / 2);				cout << "KET THUC";
	}
	SetColor(15);
	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputkey();
	while (nhan_phim_esc_de_thoat != 27);
	delete con_ran;
	con_ran = NULL;
	return;
}

/*================================================================================*/

void Tro_Choi::set_tuong(int x, int xx, int y, int yy) {
	vachtuong.p_dau.x = x;			vachtuong.p_cuoi.x = xx;
	vachtuong.p_dau.y = y;			vachtuong.p_cuoi.y = yy;
}
void Tro_Choi::set_list_diem_cao_nhat() {
	ifstream doc_file_diem("danh_sach_diem.txt");
	if (!doc_file_diem) return;
	vector<int> list_diem;
	while (!doc_file_diem.eof()) {
		int a = 0;
		doc_file_diem >> a;
		list_diem.push_back(a);
	}
	doc_file_diem.close();
	quickSort(list_diem, 0, list_diem.size() - 1);
	int j = 0;
	for (size_t i = 0; i < list_diem.size(); i++) {
		if (j > 4) break;
		if (i > 0 && list_diem.at(i) == list_diem_cao_nhat[j - 1]) continue;
		list_diem_cao_nhat[j] = list_diem.at(i);
		j++;
	}
}
void Tro_Choi::set_trang_thai(bool trangthai) {
	trang_thai = trangthai;
}
void Tro_Choi::set_muc_do(const int& md) {
	muc_do = md;
}
void Tro_Choi::set_che_do_choi(const int& a) {
	che_do_choi.set_che_do(a);
}
void Tro_Choi::save_diem(const int& diem) {
	ofstream ghi_file_diem("danh_sach_diem.txt", ios::app);
	ghi_file_diem << "\n" << diem;
	ghi_file_diem.close();
	set_list_diem_cao_nhat();
}

/*================================================================================*/

bool kiem_tra_toa_do_con_moi(const Than_Ran* ran, const vector<Toa_Do>& vatcan, const Toa_Do& conmoi, const int& cdo) {
	while (ran != NULL) {
		if (ran->toadoxy.x == conmoi.x && ran->toadoxy.y == conmoi.y) return true;
		ran = ran->next;
	}
	for (size_t i = 0; i < vatcan.size(); i++) {
		int x = vatcan.at(i).x;
		int y = vatcan.at(i).y;
		if (x > 1000 && y > 1000) {
			x -= 1000;
			y -= 1000;
		}
		if (x < 0 && y < 0) {
			x = -x;		y = -y;
		}
		if (conmoi.x == x && conmoi.y == y) return true;
	}
	return false;
}
int tao_so_ngau_nhien(int a, int b) {
	return rand() % (b - a + 1) + a;
}

/*================================================================================*/

void Tro_Choi::su_kien_ran_di_chuyen() {
	Toa_Do toa_do_duoi_ran =	node_duoi_ran(con_ran->con_ran());
	con_ran->ran_di_chuyen(che_do_choi.get_che_do(), vachtuong, che_do_choi.get_vatcan());
	if (con_ran->ran_die(vachtuong, che_do_choi.get_vatcan(), che_do_choi.get_che_do())) {
		set_trang_thai(false);
		return;
	}
	su_kien_ran_an_moi();
	xoa_duoi_ran(toa_do_duoi_ran);
}
void Tro_Choi::su_kien_ran_an_moi() {
	if (con_ran->con_ran()->toadoxy.x == con_moi.x && con_ran->con_ran()->toadoxy.y == con_moi.y) {
		tong_diem += get_muc_do();
		con_ran->ran_an_moi();
		tao_con_moi();
	}
}
void Tro_Choi::tao_con_moi() {
	do {
		//tao 1 toa do bat ki
		con_moi.x = tao_so_ngau_nhien(vachtuong.p_dau.x + 1, vachtuong.p_cuoi.x - 1);
		con_moi.y = tao_so_ngau_nhien(vachtuong.p_dau.y + 1, vachtuong.p_cuoi.y - 1);
	} while (kiem_tra_toa_do_con_moi(con_ran->con_ran(), che_do_choi.get_vatcan(), con_moi, che_do_choi.get_che_do()));
}
void Tro_Choi::hien_thi_ran() const {
	Than_Ran* conran = con_ran->con_ran();
	gotoXY(conran->toadoxy.x, conran->toadoxy.y);		cout << "X";
	conran = conran->next;
	while (conran != NULL) {
		gotoXY(conran->toadoxy.x, conran->toadoxy.y);		cout << "O";
		conran = conran->next;
	}
}
void Tro_Choi::hien_thi_moi() const  {
	gotoXY(con_moi.x, con_moi.y);
	cout << "+";
}

/*================================================================================*/

const Toa_Do_Tuong& Tro_Choi::get_vachtuong() {
	return vachtuong;
}
const vector<Toa_Do>& Tro_Choi::get_vatcan() {
	return che_do_choi.get_vatcan();
}
int Tro_Choi::get_list_diem_cao_nhat(const int& a) const {
	return list_diem_cao_nhat[a];
}
int Tro_Choi::get_tong_diem() const  {
	return tong_diem;
}
int Tro_Choi::get_muc_do() const  {
	return muc_do;
}
bool Tro_Choi::get_trang_thai() const  {
	return trang_thai;
}
string Tro_Choi::get_che_do_choi_lama() {
	return che_do_choi.get_che_do_choi_lama();
}
int Tro_Choi::get_che_do_choi()   {
	return che_do_choi.get_che_do();
}

Tro_Choi::~Tro_Choi() {}
