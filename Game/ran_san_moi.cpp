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
inline void nhap_nhay_chu(int a) {
	string abc = "";
	switch (a)
	{
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
		const int a = (whereY() - dc >= 0) ? (whereY() - dc) % 6 : 5;
		switch (a) {
		case 0:
			tao_menu(0);
			in_tuy_chon("BAT DAU", 240, 1);
			break;
		case 1: 
			tao_menu(0);
			in_tuy_chon("CHE DO CHOI", 240, 2);
			break;
		case 2: 
			tao_menu(0);
			in_tuy_chon("MUC DO CHOI", 240, 3);
			break;
		case 3: 
			tao_menu(0);
			in_tuy_chon("DIEM CAO NHAT", 240, 4);
			break;
		case 4:
			tao_menu(0);
			in_tuy_chon("CACH CHOI", 240, 5);
			break;
		case 5:
			tao_menu(0);
			in_tuy_chon("THOAT GAME", 240, 6);
			break;
		default: in_thong_bao("Eror chon_option");
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
			nhap_nhay_chu(a);
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
	SetColor(15);
}

void bat_dau_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_tuong(game_ran);
	game_ran.set_trang_thai(0);
	gotoXY(10, 6);		cout << "CHE DO CHOI:";
	gotoXY(10, 8);		cout << "MUC CHOI:";
	gotoXY(10, 10);		cout << "DIEM:";
	gotoXY(18, 30);		cout << "DUNG :  ESC";
	if (game_ran.get_ket_thuc()) return;
	game_ran.bat_dau_game();
}

void che_do_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	gotoXY(M_R / 2 - 16, M_C / 2 - 1);	cout << "Tinh nang dang duoc cap nhap...";
	gotoXY(M_R / 2 - 16, M_C / 2);	cout << "Moi ban quay lai sau!";
	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputKey();
	while (nhan_phim_esc_de_thoat != 27);
}

void muc_do(Tro_Choi& game_ran) {
	system("cls");
	ve_khung(20);
	int mucdo = game_ran.get_muc_do();
	gotoXY(M_R / 2 - 11, M_C / 2);		cout << "MUC DO  =  ";
	SetColor(240);
	cout << "     " << mucdo << "     ";
	SetColor(15);
	int mn = mucdo, mi = 0;
	for (int i = 0; i < 4; i++) {
		mn += 1;		mn = (mn > 5) ? 1 : mn;
		mi += 1;		mi = (mi > 2) ? -2 : mi;
		gotoXY(M_R / 2, M_C / 2 + mi);			cout << "     " << mn << "     ";
	}
	while (true) {
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
		SetColor(240);
		gotoXY(M_R / 2, M_C / 2);			cout << "     " << mucdo << "     ";
		SetColor(15);
		mi = 0;	mn = mucdo;
		for (int i = 0; i < 4; i++) {
			mn += 1;		mn = (mn > 5) ? 1 : mn;
			mi += 1;		mi = (mi > 2) ? -2 : mi;
			gotoXY(M_R / 2, M_C / 2 + mi);			cout << "     " << mn << "     ";
		}
	}
	game_ran.set_muc_do(mucdo);
}

void diem_cao_nhat(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	gotoXY(M_R / 2 - 7, M_C / 2 - 1);		cout << "Diem cao nhat:";
	gotoXY(M_R / 2 - 0, M_C / 2);		cout << game_ran.get_diem_cao_nhat();
	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputKey();
	while (nhan_phim_esc_de_thoat != 27);
}

void cach_choi(Tro_Choi& game_ran) {
	system("cls");
	ve_khung();
	gotoXY(M_R / 2 - 5, M_C / 2 - 4);		cout << "Cach choi:";
	gotoXY(M_R / 2 - 28, M_C / 2 - 3);		cout << "------------------------------------------------------------";
	gotoXY(M_R / 2 - 28, M_C / 2 - 1);		cout << "Su dung bon phim mui ten len - xuong - trai - phai de dieu";
	gotoXY(M_R / 2 - 28, M_C / 2);			cout << "khien con trai an moi; neu de ran cham tuong hay tu can vao";
	gotoXY(M_R / 2 - 28, M_C / 2 + 1);		cout << "than thi game se ket thuc.                                    ";
	gotoXY(M_R / 2 - 28, M_C / 2 + 3);		cout << "Nhan phim \"ESC\" de thoat.                                    ";
	int nhan_phim_esc_de_thoat;
	do
		nhan_phim_esc_de_thoat = inputKey();
	while (nhan_phim_esc_de_thoat != 27);
}


int main() {
	srand(unsigned int(time(NULL)));
	Tro_Choi game_ran;
	SetConsoleTitle(TEXT("GAME: RAN SAN MOI"));
	resizeConsole(1160, 600);
	while (1) {
		tao_menu();
		gotoXY(M_R / 2, dc);
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
		if (x == 5) {
			system("cls");
			break;
		}
	}
	SetColor(15);
	system("cls");
	return 0;
}