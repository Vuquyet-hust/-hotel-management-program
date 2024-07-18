#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#define MAX 100

using namespace std;

struct KhachHang {
    int MaKH;
    char TenKH[30];
    char GioiTinh[5];
    int NamSinh;
    char SDT[11];
    char DiaChi[30];
};

struct DatPhong {
    int MaDP;
    int MaKH;
    int SoPhong;
    char NgayDat[11];
    char NgayTra[11];
};

typedef KhachHang KH;
typedef DatPhong DP;

// Function prototypes
void printLine(int n);
void nhapThongTinKH(KH &kh, int id);
void nhapKH(KH a[], int id, int &n);
void capNhatThongTinKH(KH &kh);
void capNhatKH(KH a[], int id, int n);
int xoaTheoID(KH a[], int id, int &n);
void timKiemTheoTen(KH a[], char ten[], int n);
int idLonNhat(KH a[], int n);
void sapXepTheoMaKH(KH a[], int n);
void sapXepTheoTen(KH a[], int n);
void showKhachHang(KH a[], int n);
int docFile(KH a[], const char fileName[]);
void ghiFile(KH a[], int n, const char fileName[]);
void pressAnyKey();
void nhapThongTinDP(DP &dp, int id, int maKH);
void nhapDP(DP a[], int id, int maKH, int &n);
void showDatPhong(DP a[], int n);

// Main function
int main() {
    int key;
    const char fileName[] = "KhachHang.txt";
    KH arrayKH[MAX];
    DP arrayDP[MAX];
    int soluongKH = 0;
    int idCount = 0;
    int soLuongDP = 0;
    int idCountDP = 0;

    // Nhap sanh sach khach hang tu file
    soluongKH = docFile(arrayKH, fileName);
    idCount = idLonNhat(arrayKH, soluongKH);

    while (true) {
        cout << "         CHUONG TRINH QUAN LY KHACH SAN                \n";
        cout << "*******************************************************\n";
        cout << "1. THEM KHACH HANG\n";
        cout << "2. THEM DAT PHONG\n";
        cout << "3. CAP NHAT THONG TIN KHACH HANG BOI MA KHACH HANG\n";
        cout << "4. XOA KHACH HANG BOI MA KHACH HANG\n";
        cout << "5. TIM KIEM KHACH HANG THEO TEN\n";
        cout << "6. SAP XEP KHACH HANG THEO MA SO\n";
        cout << "7. SAP XEP KHACH HANG THEO TEN\n";
        cout << "8. HIEN THI DANH SACH KHACH HANG\n";
        cout << "9. GHI LAI DANH SACH KHACH HANG VAO FILE\n";
        cout << "10. HIEN THI DANH SACH DAT PHONG\n";
        cout << "0. THOAT CHUONG TRINH\n"; 
        cout << "********************************************************\n";
        cout << "                >>>>>> Nhap lua chon cua ban: ";
        cin >> key;

        switch (key) {
            case 1:
                cout << "\n------------- THEM KHACH HANG ----------\n";
                idCount++;
                nhapKH(arrayKH, idCount, soluongKH);
                cout << "\nThem khach hang thanh cong!";
                pressAnyKey();
                break;
             case 2:
                cout << "\n------------- THEM DAT PHONG ----------\n";
                idCountDP++;
                nhapDP(arrayDP, idCountDP, idCount, soLuongDP);
                cout << "\nThem dat phong thanh cong!";
                pressAnyKey();
                break;
            case 3:
                if (soluongKH > 0) {
                    int id;
                    cout << "\n--------- CAP NHAT THONG TIN KHACH HANG ------------\n";
                    cout << "\n Nhap MaKH: ";
                    cin >> id;
                    capNhatKH(arrayKH, id, soluongKH);
                } else {
                    cout << "\n Danh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if (soluongKH > 0) {
                    int id;
                    cout << "\n--------- XOA KHACH HANG ------------\n";
                    cout << "\n Nhap MaKH: ";
                    cin >> id;
                    if (xoaTheoID(arrayKH, id, soluongKH) == 1) {
                        cout << "\nKhach hang co MaKH = " << id << " da bi xoa.";
                    }
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if (soluongKH > 0) {
                    cout << "\n ------------- TIM KIEM KHACH HANG THEO TEN ---------------\n";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: ";
                    cin.ignore();
                    cin.getline(strTen, 30);
                    timKiemTheoTen(arrayKH, strTen, soluongKH);
                } else {
                    cout << "\n Danh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if (soluongKH > 0) {
                    cout << "------------- SAP XEP KHACH HANG THEO MA SO -------------\n";
                    sapXepTheoMaKH(arrayKH, soluongKH);
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if (soluongKH > 0) {
                    cout << "\n------------- SAP XEP KHACH HANG THEO TEN -------------\n";
                    sapXepTheoTen(arrayKH, soluongKH);
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 8:
                if (soluongKH > 0) {
                    cout << "\n------------- HIEN THI DANH SACH KHACH HANG -------------\n";
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 9:
                if (soluongKH > 0) {
                    cout << "\n------------- GHI DANH SACH KHACH HANG VAO FILE -------------\n";
                    ghiFile(arrayKH, soluongKH, fileName);
                    cout << "\nGhi danh sach vao file " << fileName << " thanh cong!";
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
           
            case 10:
                if (soLuongDP > 0) {
                    cout << "\n------------- HIEN THI DANH SACH DAT PHONG -------------\n";
                    showDatPhong(arrayDP, soLuongDP);
                } else {
                    cout << "\nDanh sach dat phong trong!";
                }
                pressAnyKey();
                break;
            case 0:
                cout << "\n----------- THOAT CHUONG TRINH ----------\n";
                return 0;
            default:
                cout << "\nKhong co chuc nang nay";
                cout << "\nHay chon lai trong menu";
                pressAnyKey();
                break;
        }
    }
}

void nhapThongTinKH(KH &kh, int id) {
    kh.MaKH = id;
    cout << "\nTen khach hang: ";
    cin.ignore();
    cin.getline(kh.TenKH, 30);
    cout << "Gioi tinh: ";
    cin.getline(kh.GioiTinh, 5);
    cout << "Nam sinh: ";
    cin >> kh.NamSinh;
    cout << "SDT: ";
    cin.ignore();
    cin.getline(kh.SDT, 11);
    cout << "Dia chi: ";
    cin.getline(kh.DiaChi, 30);
}

void nhapKH(KH a[], int id, int &n) {
    printLine(40);
    cout << "Nhap khach hang thu " << n + 1 << ": ";
    nhapThongTinKH(a[n], id);
    n++;
    printLine(40);
}

void capNhatThongTinKH(KH &kh) {
    cout << "\nTen khach hang: ";
    cin.ignore();
    cin.getline(kh.TenKH, 30);
    cout << "Gioi tinh: ";
    cin.getline(kh.GioiTinh, 5);
    cout << "Nam sinh: ";
    cin >> kh.NamSinh;
    cout << "SDT: ";
    cin.ignore();
    cin.getline(kh.SDT, 11);
    cout << "Dia chi: ";
    cin.getline(kh.DiaChi, 30);
}

void capNhatKH(KH a[], int id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].MaKH == id) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin khach hang co MaKH = " << id;
            capNhatThongTinKH(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        cout << "\n Khach hang co MaKH = " << id << " khong ton tai.";
    }
}

int xoaTheoID(KH a[], int id, int &n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].MaKH == id) {
            found = 1;
            printLine(40);
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            cout << "\n Da xoa khach hang co MaKH = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        cout << "Khach hang co MaKH = " << id << " khong ton tai.";
        return 0;
    } else {
        return 1;
    }
}

void timKiemTheoTen(KH a[], char ten[], int n) {
    KH arrayFound[MAX];
    char tenKH[30];
    int found = 0;
    for (int i = 0; i < n; i++) {
        strcpy(tenKH, a[i].TenKH);
        if (strstr(strupr(tenKH), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showKhachHang(arrayFound, found);
}

void showKhachHang(KH a[], int n) {
    printLine(80);
    cout << "\nSTT | MAKH |                        HO_TEN|GIOI TINH|NAM SINH|        SDT|           DIA CHI|";
    for (int i = 0; i < n; i++) {
        printf("\n%4d|", i + 1);
        printf("%6d|", a[i].MaKH);
        printf("%30s|", a[i].TenKH);
        printf("%9s|", a[i].GioiTinh);
        printf("%8d|", a[i].NamSinh);
        printf("%11s|", a[i].SDT);
        printf("%13s|", a[i].DiaChi);
    }
    printLine(80);
}

void sapXepTheoMaKH(KH a[], int n) {
    KH tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].MaKH > a[j].MaKH) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapXepTheoTen(KH a[], int n) {
    KH tmp;
    char tenKH1[30];
    char tenKH2[30];
    for (int i = 0; i < n; i++) {
        strcpy(tenKH1, a[i].TenKH);
        for (int j = i + 1; j < n; j++) {
            strcpy(tenKH2, a[j].TenKH);
            if (strcmp(strupr(tenKH1), strupr(tenKH2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int idLonNhat(KH a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].MaKH;
        for (int i = 1; i < n; i++) {
            if (a[i].MaKH > idMax) {
                idMax = a[i].MaKH;
            }
        }
    }
    return idMax;
}

int docFile(KH a[], const char fileName[]) {
    ifstream fp(fileName);
    int i = 0;
    cout << "Chuan bi doc file: " << fileName << endl;
    // Doc thong tin khach hang
    while (fp >> a[i].MaKH >> a[i].TenKH >> a[i].GioiTinh >> a[i].NamSinh >> a[i].SDT >> a[i].DiaChi) {
        i++;
        cout << "Doc ban ghi thu: " << i << endl;
    }
    cout << "So luong khach hang co trong file la: " << i << endl;
    cout << endl;
    fp.close();
    // Tra ve so luong khach hang duoc doc tu file
    return i;
}

void ghiFile(KH a[], int n, const char fileName[]) {
    ofstream fp(fileName);
    for (int i = 0; i < n; i++) {
        fp << a[i].MaKH << " " << a[i].TenKH << " " << a[i].GioiTinh << " " << a[i].NamSinh << " " << a[i].SDT << " " << a[i].DiaChi << endl;
    }
    fp.close();
}

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\n\nBam phim bat ki de tiep tuc...";
    cin.ignore();
    cin.get();
    system("cls");
}

void nhapThongTinDP(DP &dp, int id, int maKH) {
    dp.MaDP = id;
    dp.MaKH = maKH;
    cout << "So phong: ";
    cin >> dp.SoPhong;
    cout << "Ngay dat (dd/mm/yyyy): ";
    cin.ignore();
    cin.getline(dp.NgayDat, 11);
    cout << "Ngay tra (dd/mm/yyyy): ";
    cin.getline(dp.NgayTra, 11);
}

void nhapDP(DP a[], int id, int maKH, int &n) {
    printLine(40);
    cout << "Nhap dat phong thu " << n + 1 << ": ";
    nhapThongTinDP(a[n], id, maKH);
    n++;
    printLine(40);
}

void showDatPhong(DP a[], int n) {
    printLine(80);
    cout << "\nSTT | MADP | MAKH | SOPHONG |  NGAY DAT  |  NGAY TRA  |";
    for (int i = 0; i < n; i++) {
        printf("\n%4d|", i + 1);
        printf("%6d|", a[i].MaDP);
        printf("%6d|", a[i].MaKH);
        printf("%9d|", a[i].SoPhong);
        printf("%12s|", a[i].NgayDat);
        printf("%12s|", a[i].NgayTra);
    }
    printLine(80);
}

