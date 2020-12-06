#include"tro_choi.h"
#define M_R 152		//do rong cua man hinh
#define M_C 35		//do cao cua man hinh
#define dc 12			//do cao cua bang menu

int zxcv = 0;
void in_thong_bao(string abc, int mau_sac = 78) {
	int a = (100 - abc.length()) / 2;
	gotoXY(M_R / 2 - 50, 3);
	SetColor(mau_sac);
	cout << in_khoang_trang(a) << abc << in_khoang_trang(100 - abc.length() - a);
	SetColor(15);
	Sleep(1500);
	gotoXY(M_R / 2 - 50, 3);
	cout << in_khoang_trang(a) << in_khoang_trang(abc.length()) << in_khoang_trang(100 - abc.length() - a);
}
void ve_khung(int mau_sac = 20) {
	SetColor(mau_sac);
	cout << in_khoang_trang(M_R) << endl;
	for (int i = 0; i < M_C - 2; i++) {
		cout << "  ";
		gotoXY(M_R - 2, i + 1);
		cout << "  \n";
	}
	cout << in_khoang_trang(M_R);
	SetColor(15);
}
void in_tuy_chon(string abc, int ma_mau = 15, int t = 0) {
	const int dd = 40;			// chinh do rong cua menu
	SetColor(15);
	if (t != 0) {
		zxcv = t - 1;
		gotoXY((M_R - dd) / 2 - 3, dc + zxcv);		cout << ">>";
		gotoXY((M_R + dd) / 2 + 1, dc + zxcv);		cout << "<<";
	}
	else {
		gotoXY((M_R - dd) / 2 - 3, dc + zxcv);		cout << "  ";
		gotoXY((M_R + dd) / 2 + 1, dc + zxcv);		cout << "  ";
	}
	SetColor(ma_mau);
	gotoXY((M_R - dd) / 2, dc + zxcv);
	int a = (dd - abc.length()) / 2;
	cout << in_khoang_trang(a);
	cout << abc;
	cout << in_khoang_trang(dd - a - abc.length());
	SetColor(15);
	zxcv++;
}
void tao_menu(int in = 1) {
	if (in == 1) {
		system("cls");
		ve_khung();
	}
	zxcv = 0;
	gotoXY(M_R / 2 - 2, 9);			cout << "MENU";
	gotoXY(M_R / 2 - 20, 10);		cout << "----------------------------------------";
	in_tuy_chon("BAT DAU");
	in_tuy_chon("CHE DO CHOI");
	in_tuy_chon("MUC DO CHOI");
	in_tuy_chon("DIEM CAO NHAT");
	in_tuy_chon("CACH CHOI");
	in_tuy_chon("THOAT GAME");
	gotoXY(M_R / 2 - 20, 19);		cout << "----------------------------------------";
}
inline void nhap_nhay_tuy_chon_menu(int a) {
	string abc = "";
	switch (a) {
	case 0:abc = "BAT DAU";
		break;
	case 1:abc = "CHE DO CHOI";
		break;
	case 2:abc = "MUC DO CHOI";
		break;
	case 3:abc = "DIEM CAO NHAT";
		break;
	case 4:abc = "CACH CHOI";
		break;
	case 5:abc = "THOAT GAME";
		break;
	}
	for (int i = 0; i < 3; i++) {
		Sleep(150);
		in_tuy_chon(abc, 255, a + 1);
		Sleep(150);
		in_tuy_chon(abc, 240, a + 1);
	}
}
int chon_option() {
	while (1) {
		const int a = (whereY() - dc >= 0) ? ((whereY() - dc) % 6) : 5;
		tao_menu(0);
		switch (a) {
		case 0:
			in_tuy_chon("BAT DAU", 240, 1);
			break;
		case 1: 
			in_tuy_chon("CHE DO CHOI", 240, 2);
			break;
		case 2: 
			in_tuy_chon("MUC DO CHOI", 240, 3);
			break;
		case 3:
			in_tuy_chon("DIEM CAO NHAT", 240, 4);
			break;
		case 4:
			in_tuy_chon("CACH CHOI", 240, 5);
			break;
		case 5:
			in_tuy_chon("THOAT GAME", 240, 6);
			break;
		}
		ShowCur(false);
		int nhap_vao = 0;
		do
			nhap_vao = inputkey();
		while (nhap_vao == -1);
		switch (nhap_vao) {
		case 1080: //di xuong duoi
			gotoXY(M_R / 2, whereY() + 1);
			break;
		case 1072: //di len tren
			gotoXY(M_R / 2, whereY() - 1);
			break;
		case 13:
			nhap_nhay_tuy_chon_menu(a);
			return a;
		}
	}
}
void ve_tuong(Tro_Choi& game_ran) {
	game_ran.set_tuong(M_R - 3 * M_C - 1, M_R - 2, 0, M_C - 1);
	ve_khung(20);
	SetColor(20);
	for (int i = 0; i < M_C; i++) {
		gotoXY(M_R - 3 * M_C - 2, i);
		cout << "  ";
	}
	//in vat can
	if (game_ran.get_che_do_choi() != 1) ve_vat_can(game_ran.get_vatcan());
	SetColor(15);
}

/*==========================================================================*/

void bat_dau_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_tuong(game_ran);
	game_ran.set_trang_thai(true);
	gotoXY(13, 6);		cout << "CHE DO CHOI:";
	gotoXY(14, 8);		cout << "MUC CHOI:";
	gotoXY(17, 10);		cout << "DIEM:";
	gotoXY(15, 29);		cout << "DUNG :  ESC";
	if (!game_ran.get_trang_thai()) return;
	game_ran.bat_dau_game();
}

void che_do_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	int chedo = game_ran.get_che_do_choi();
	gotoXY(M_R / 2 - 16, M_C / 2 - 1);	cout << "CHE DO CHOI  -  ";
	while (true) {
		int mn = chedo, mi = -1;
		for (int i = 0; i < 3; i++) {
			gotoXY(M_R / 2, M_C / 2 + mi);			cout << "                        ";
			gotoXY(M_R / 2, M_C / 2 + mi);			cout << "    " << che_do_choi_lama(mn) << "    ";
			mn += 1;		mn = (mn > 3) ? 1 : mn;
			mi += 1; 		mi = (mi > 0) ? -2 : mi;
		}
		SetColor(240);
		gotoXY(M_R / 2, M_C / 2 - 1);			cout << "    " << che_do_choi_lama(chedo) << "    ";
		SetColor(15);
		int key = 0;
		do
			key = inputkey();
		while (key == -1);
		switch (key) {
		case 1072: chedo--;
			break;
		case 1080: chedo++;
			break;
		}
		if (key == 13) {
			SetColor(240);
			for (int j = 0; j < 3; j++) {
				gotoXY(M_R / 2, M_C / 2 - 1);			cout << "           ";
				Sleep(100);
				gotoXY(M_R / 2, M_C / 2 - 1);			cout << "    " << che_do_choi_lama(chedo) << "    ";
				Sleep(100);
			}
			SetColor(15);
			Sleep(200);
			break;
		}
		if (chedo > 3) chedo = 1;
		else if (chedo < 1) chedo = 3;
	}
	game_ran.set_che_do_choi(chedo);
}

void muc_do(Tro_Choi& game_ran) {
	system("cls");
	ve_khung(20);
	int mucdo = game_ran.get_muc_do();
	gotoXY(M_R / 2 - 11, M_C / 2);		cout << "MUC DO  =  ";
	while (true) {
		int mn = mucdo, mi = 0;
		for (int i = 0; i < 5; i++) {
			gotoXY(M_R / 2, M_C / 2 + mi);			cout << "           ";
			gotoXY(M_R / 2, M_C / 2 + mi);			cout << "     " << mn << "     ";
			mn += 1;		mn = (mn > 5) ? 1 : mn;
			mi += 1;		mi = (mi > 2) ? -2 : mi;
		}
		SetColor(240);
		gotoXY(M_R / 2, M_C / 2);			cout << "     " << mucdo << "     ";
		SetColor(15);
		int key = 0;
		do
			key = inputkey();
		while (key == -1);
		switch (key) {
		case 1072: mucdo--;
			break;
		case 1080: mucdo++;
			break;
		}
		if (key == 13) {
			SetColor(240);
			for (int i = 0; i < 3; i++) {
				gotoXY(M_R / 2, M_C / 2);			cout << "           ";
				Sleep(100);
				gotoXY(M_R / 2, M_C / 2);			cout << "     " << mucdo << "     ";
				Sleep(100);
			}
			SetColor(15);
			Sleep(200);
			break;
		}
		if (mucdo > 5) mucdo = 1;
		else if (mucdo < 1) mucdo = 5;
	}
	game_ran.set_muc_do(mucdo);
}

inline int so_chu_so(int a) {
	int i = 0;
	while (a != 0) {
		i++;
		a /= 10;
	}
	return i;
}
void diem_cao_nhat(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	gotoXY(M_R / 2 - 7, M_C / 2 - 1);		cout << "Diem cao nhat:";
	
	for (int i = 0; i < 5; i++) {
		int diem = game_ran.get_list_diem_cao_nhat(i);
		if (diem == 0) continue;
		gotoXY(M_R / 2 + 1 - so_chu_so(diem), M_C / 2 + i);		cout << diem;
	}

	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputkey();
	while (nhan_phim_esc_de_thoat != 27);
}

void cach_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	gotoXY(M_R / 2 - 5, M_C / 2 - 10);		cout << "Cach choi:";
	gotoXY(M_R / 2 - 27, M_C / 2 - 9);		cout << "----------------------------------------------------------";
	gotoXY(M_R / 2 - 27, M_C / 2 - 7);		cout << "Su dung bon phim mui ten len - xuong - trai - phai de dieu";
	gotoXY(M_R / 2 - 27, M_C / 2 - 6);		cout << "khien con ran an moi.";
	gotoXY(M_R / 2 - 27, M_C / 2 - 4);		cout << "(*) Che do choi:";
	gotoXY(M_R / 2 - 27, M_C / 2 - 3);		cout << "Che do \"I\" - che do mac dinh: tro choi ket thuc khi ran tu";
	gotoXY(M_R / 2 - 27, M_C / 2 - 2);		cout << "             can vao than hoac cham tuong.";
	gotoXY(M_R / 2 - 27, M_C / 2 - 1);		cout << "Che do \"II\" - che do choi xuyen tuong: tro choi ket thuc khi";
	gotoXY(M_R / 2 - 27, M_C / 2 );			cout << "              ran tu can vao than hoac cham vao vach ngan.";
	gotoXY(M_R / 2 - 27, M_C / 2 + 1);			cout << "Che do \"III\"- che do choi san moi trong nha: tro choi ket";
	gotoXY(M_R / 2 - 27, M_C / 2 + 2);		cout << "              thuc khi ran tu can vao than hoac cham tuong.";
	gotoXY(M_R / 2 - 27, M_C / 2 + 4);		cout << "(*) Muc do choi:";
	gotoXY(M_R / 2 - 27, M_C / 2 + 5);		cout << "Muc do 1 - 2 - 3 - 4 - 5 tuong ung voi toc do ran di chuyen";
	gotoXY(M_R / 2 - 27, M_C / 2 + 6);		cout << "x1 - x2 - x3 - x4 - x5 lan.";
	gotoXY(M_R / 2 - 27, M_C / 2 + 8);		cout << "Nhan phim \"ESC\" de thoat.";

	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputkey();
	while (nhan_phim_esc_de_thoat != 27);
}

/*==========================================================================*/

void setting_tuong(Tro_Choi& game_ran) {
	system("cls");
	ve_tuong(game_ran);
	ofstream ghi_file_toado("toa_do_vach_tuong_II.txt", ios::app);
	int x = M_R - 3 * M_C - 1, y = 0;
	while (true) {
		gotoXY(10, 10);		cout << "          ";
		gotoXY(10, 10);		cout << x << " - " << y;
		gotoXY(x, y);
		int nhan_phim;
		do
			nhan_phim = inputkey();
		while (nhan_phim == -1);
		switch (nhan_phim) {
		case 13:
			SetColor(20);
			cout << " ";
			SetColor(15);
			gotoXY(x, y);
			ghi_file_toado << "\n" << x << " " << y;
			break;
		case 32:
			SetColor(40);
			cout << " ";
			SetColor(15);
			gotoXY(x, y);
			ghi_file_toado << "\n" << -x << " " << -y;
			break;
		case 97:
			SetColor(60);
			cout << " ";
			SetColor(15);
			gotoXY(x, y);
			ghi_file_toado << "\n" << x + 1000 << " " << y + 1000;
			break;
		case 1072: y--;
			break;
		case 1077: x++;
			break;
		case 1080: y++;
			break;
		case 1075: x--;
			break;
		}
		if (nhan_phim == 27)break;
	}
	ghi_file_toado.close();
}

int main() {
	srand(unsigned int(time(NULL)));
	Tro_Choi game_ran;
	SetConsoleTitle(TEXT("GAME: RAN SAN MOI"));
	resizeConsole(1160, 600);
	int _x = 0;
	while (true) {
		tao_menu();
		gotoXY(M_R / 2, dc + _x);
		const int x = chon_option();
		switch (x) {
		case 0:
			bat_dau_choi(game_ran);
			break;
		case 1:
			che_do_choi(game_ran);
			break;
		case 2:
			muc_do(game_ran);
			break;
		case 3:
			diem_cao_nhat(game_ran);
			break;
		case 4:
			cach_choi(game_ran);
			break;
		}
		if (x == 5) break;
		_x = x;
	}
	SetColor(15);
	system("cls");
	return 0;
}
