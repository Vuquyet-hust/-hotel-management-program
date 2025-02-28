#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#define MAX 100
helloo i.m quyết
using namespace std;

// Khai bao cau truc du lieu khach hang trong ds
struct KhachHang {
    int MaKH;
    char TenKH[30];
    char GioiTinh[5];
    int NamSinh;
    char SDT[11];
    char DiaChi[30];
};
typedef KhachHang KH;

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
int docFile(KH a[], char fileName[]);
void ghiFile(KH a[], int n, char fileName[]);
void pressAnyKey();

// Ham main
int main() {
    int key;
    char fileName[] = "KhachHang.txt";
    KH arrayKH[MAX];
    int soluongKH = 0;
    int idCount = 0;

    // Nhap sanh sach khach hang tu file
    soluongKH = docFile(arrayKH, fileName);
    idCount = idLonNhat(arrayKH, soluongKH);

    while (true) {
        cout << "         CHUONG TRINH QUAN LY KHACH SAN                \n";
        cout << "*******************************************************\n";
        cout << "1. THEM KHACH HANG\n";
        cout << "2. CAP NHAT THONG TIN KHACH HANG BOI MA KHACH HANG\n";
        cout << "3. XOA KHACH HANG BOI MA KHACH HANG\n";
        cout << "4. TIM KIEM KHACH HANG THEO TEN\n";
        cout << "5. SAP XEP KHACH HANG THEO MA SO\n";
        cout << "6. SAP XEP KHACH HANG THEO TEN\n";
        cout << "7. HIEN THI DANH SACH KHACH HANG\n";
        cout << "8. GHI LAI DANH SACH KHACH HANG VAO FILE\n";
        cout << "0. THOAT CHUONG TRINH\n";
        cout << "********************************************************\n";
        cout << "                >>>>>> Nhap lua chon cua ban: ";
        cin >> key;
        switch (key) {
            case 1:
                cout << "\n------------- THEM KHACH HANG ----------";
                idCount++;
                nhapKH(arrayKH, idCount, soluongKH);
                cout << "\nThem khach hang thanh cong!";
                pressAnyKey();
                break;
            case 2:
                if (soluongKH > 0) {
                    int id;
                    cout << "\n--------- CAP NHAT THONG TIN KHACH HANG ------------";
                    cout << "\n Nhap MaKH: ";
                    cin >> id;
                    capNhatKH(arrayKH, id, soluongKH);
                } else {
                    cout << "\n Danh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if (soluongKH > 0) {
                    int id;
                    cout << "\n--------- XOA KHACH HANG ------------";
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
            case 4:
                if (soluongKH > 0) {
                    cout << "\n ------------- TIM KIEM KHACH HANG THEO TEN ---------------";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: ";
                    fflush(stdin);
                    gets(strTen);
                    timKiemTheoTen(arrayKH, strTen, soluongKH);
                } else {
                    cout << "\n Danh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 5:
                if (soluongKH > 0) {
                    cout << "------------- SAP XEP KHACH HANG THEO MA SO -------------";
                    sapXepTheoMaKH(arrayKH, soluongKH);
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if (soluongKH > 0) {
                    cout << "\n------------- SAP XEP KHACH HANG THEO TEN -------------";
                    sapXepTheoTen(arrayKH, soluongKH);
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if (soluongKH > 0) {
                    cout << "\n------------- HIEN THI DANH SACH KHACH HANG -------------";
                    showKhachHang(arrayKH, soluongKH);
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 8:
                if (soluongKH > 0) {
                    cout << "\n------------- GHI DANH SACH KHACH HANG VAO FILE -------------";
                    ghiFile(arrayKH, soluongKH, fileName);
                    cout << "\nGhi danh sach vao file " << fileName << " thanh cong!";
                } else {
                    cout << "\nDanh sach khach hang trong!";
                }
                pressAnyKey();
                break;
            case 0:
                cout << "\n----------- THOAT CHUONG TRINH ----------";
                return 0;
            default:
                cout << "\nKhong co chuc nang nay";
                cout << "\nHay chon lai trong menu";
                pressAnyKey();
                break;
        }
    }
}

// Ham nhap thong tin khach hang
void nhapThongTinKH(KH &kh, int id) {
    kh.MaKH = id;
    cout << "\nTen khach hang: ";
    fflush(stdin);
    gets(kh.TenKH);
    cout << "Gioi tinh: ";
    fflush(stdin);
    gets(kh.GioiTinh);
    cout << "Nam sinh: ";
    cin >> kh.NamSinh;
    cout << "SDT: ";
    fflush(stdin);
    gets(kh.SDT);
    cout << "Dia chi: ";
    fflush(stdin);
    gets(kh.DiaChi);
}

// Ham nhap khach hang
void nhapKH(KH a[], int id, int &n) {
    printLine(40);
    cout << "Nhap khach hang thu " << n + 1 << ": ";
    nhapThongTinKH(a[n], id);
    n++;
    printLine(40);
}

// Ham cap nhat thong tin khach hang
void capNhatThongTinKH(KH &kh) {
    cout << "\nTen khach hang: ";
    fflush(stdin);
    gets(kh.TenKH);
    cout << "Gioi tinh: ";
    fflush(stdin);
    gets(kh.GioiTinh);
    cout << "Nam sinh: ";
    cin >> kh.NamSinh;
    cout << "SDT: ";
    fflush(stdin);
    gets(kh.SDT);
    cout << "Dia chi: ";
    fflush(stdin);
    gets(kh.DiaChi);
}

// Ham cap nhat khach hang
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

// Ham xoa khach hang theo ma so
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

// Ham tim kiem khach hang theo ten
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

// Ham hien thi danh sach khach hang
void showKhachHang(KH a[], int n) {
    printLine(80);
    cout << "\nSTT | MAKH |              HO_TEN|GIOI TINH|NAM SINH|        SDT|           DIA CHI|";
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

// Ham sap xep khach hang theo ma tang dan
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

// Ham sap xep khach hang theo ten theo thu tu tang dan
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

// Ham ma so lon nhat
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

// Ham doc file khach hang
int docFile(KH a[], char fileName[]) {
    FILE *fp;
    int i = 0;
    fp = fopen(fileName, "r");
    cout << "Chuan bi doc file: ";
    puts(fileName);
    // Doc thong tin khach hang
    while (fscanf(fp, "%d %s %s %d %s %s\n", &a[i].MaKH, a[i].TenKH, a[i].GioiTinh, &a[i].NamSinh, a[i].SDT, a[i].DiaChi) != EOF) {
        i++;
        cout << "Doc ban ghi thu: " << i << endl;
    }
    cout << "So luong khach hang co trong file la: " << i << endl;
    cout << endl;
    fclose(fp);
    // Tra ve so luong khach hang duoc doc tu file
    return i;
}

// Ham ghi file khach hang
void ghiFile(KH a[], int n, char fileName[]) {
    FILE *fp;
    fp = fopen(fileName, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %s %d %s %s\n", a[i].MaKH, a[i].TenKH, a[i].GioiTinh, a[i].NamSinh, a[i].SDT, a[i].DiaChi);
    }
    fclose(fp);
}

// Ham in danh sach khach hang
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

// Ham lua chon phim
void pressAnyKey() {
    cout << "\n\nBam phim bat ki de tiep tuc...";
    getch();
    system("cls");
}



