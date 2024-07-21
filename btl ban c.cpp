#include <stdio.h>
#include <string.h>

#define MAX 100

// C?u trúc KhachHang
typedef struct {
    char ten[100];
    char diaChi[100];
    char dienThoai[12];
    char tuNgay[20];
    char denNgay[20];
    float tienTamUng;
    int maDatPhong;
} KhachHang;

// C?u trúc Phong
typedef struct {
    char loai;
    char kieu;
    char dieuHoa;
    int soPhong;
    int giaThue;
    int trangThai;
    KhachHang kh;
} Phong;

// Khai báo toàn c?c
Phong phongs[MAX];
int count = 0;

// Hàm thêm phòng
Phong themPhong(int soPhong) {
    Phong phong;
    phong.soPhong = soPhong;
    printf("\nLoai dieu hoa (C/K) : ");
    scanf(" %c", &phong.dieuHoa);
    printf("\nLoai tien nghi (C/BT) : ");
    scanf(" %c", &phong.loai);
    printf("\nLoai kich thuoc (L/N) : ");
    scanf(" %c", &phong.kieu);
    printf("\nGia thue hang ngay : ");
    scanf("%d", &phong.giaThue);
    phong.trangThai = 0;
    printf("\nPhong da duoc them thanh cong!");
    return phong;
}

// Hàm hi?n th? phòng
void hienThiPhong(Phong tempPhong) {
    printf("\nSo phong: \t%d", tempPhong.soPhong);
    printf("\nLoai dieu hoa (C/K) %c", tempPhong.dieuHoa);
    printf("\nLoai tien nghi (C/BT) %c", tempPhong.loai);
    printf("\nLoai kich thuoc (L/N) %c", tempPhong.kieu);
    printf("\nGia thue: %d", tempPhong.giaThue);
}
// Hàm tìm phòng
void timPhong(int soPhong) {
    int i, timThay = 0;
    for (i = 0; i < count; i++) {
        if (phongs[i].soPhong == soPhong) {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1) {
        printf("Chi tiet phong\n");
        if (phongs[i].trangThai == 1) {
            printf("\nPhong da duoc dat truoc");
        } else {
            printf("\nPhong dang trong");
        }
        hienThiPhong(phongs[i]);
    } else {
        printf("\nKhong tim thay phong");
    }
}



// Hàm báo cáo khách
void baoCaoKhach() {
    if (count == 0) {
        printf("\nKhong co khach trong khach san !!");
    }
    for (int i = 0; i < count; i++) {
        if (phongs[i].trangThai == 1) {
            printf("\nTen khach hang : %s", phongs[i].kh.ten);
            printf("\nSo phong : %d", phongs[i].soPhong);
            printf("\nDia chi (chi thanh pho) : %s", phongs[i].kh.diaChi);
            printf("\nDien thoai : %s", phongs[i].kh.dienThoai);
            printf("\n---------------------------------------");
        }
    }
}

// Hàm check-in phòng
void checkIn() {
    int i, timThay = 0, soPhong;

    printf("\nNhap so phong : ");
    scanf("%d", &soPhong);
    for (i = 0; i < count; i++) {
        if (phongs[i].soPhong == soPhong) {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1) {
        if (phongs[i].trangThai == 1) {
            printf("\nPhong da duoc dat truoc");
            return;
        }

        printf("\nNhap ten khach hang (ten dau tien): ");
        getchar();  // Ð?c ký t? m?i
        fgets(phongs[i].kh.ten, sizeof(phongs[i].kh.ten), stdin);
        phongs[i].kh.ten[strcspn(phongs[i].kh.ten, "\n")] = '\0'; // Lo?i b? ký t? newline

        printf("\nNhap dia chi (chi thanh pho): ");
        fgets(phongs[i].kh.diaChi, sizeof(phongs[i].kh.diaChi), stdin);
        phongs[i].kh.diaChi[strcspn(phongs[i].kh.diaChi, "\n")] = '\0'; // Lo?i b? ký t? newline

        printf("\nNhap dien thoai: ");
        fgets(phongs[i].kh.dienThoai, sizeof(phongs[i].kh.dienThoai), stdin);
        phongs[i].kh.dienThoai[strcspn(phongs[i].kh.dienThoai, "\n")] = '\0'; // Lo?i b? ký t? newline

        printf("\nNhap ngay den: ");
        fgets(phongs[i].kh.tuNgay, sizeof(phongs[i].kh.tuNgay), stdin);
        phongs[i].kh.tuNgay[strcspn(phongs[i].kh.tuNgay, "\n")] = '\0'; // Lo?i b? ký t? newline

        printf("\nNhap ngay di: ");
        fgets(phongs[i].kh.denNgay, sizeof(phongs[i].kh.denNgay), stdin);
        phongs[i].kh.denNgay[strcspn(phongs[i].kh.denNgay, "\n")] = '\0'; // Lo?i b? ký t? newline

        printf("\nNhap tien tam ung: ");
        scanf("%f", &phongs[i].kh.tienTamUng);

        phongs[i].trangThai = 1;

        printf("\nKhach hang da check-in thanh cong..");
    }
}

// Hàm ki?m tra phòng tr?ng
void phongTrong() {
    int i, timThay = 0;
    for (i = 0; i < count; i++) {
        if (phongs[i].trangThai == 0) {
            hienThiPhong(phongs[i]);
            printf("\n\nNhan enter de xem phong tiep theo");
            timThay = 1;
        }
    }
    if (timThay == 0) {
        printf("\nTat ca cac phong da duoc dat truoc");
    }
}

// Hàm tìm khách hàng
void timKhachHang(char *ten) {
    int i, timThay = 0;
    for (i = 0; i < count; i++) {
        if (phongs[i].trangThai == 1 && strcmp(phongs[i].kh.ten, ten) == 0) {
            printf("\nTen khach hang: %s", phongs[i].kh.ten);
            printf("\nSo phong: %d", phongs[i].soPhong);
            printf("\n\nNhan enter de xem thong tin tiep theo\n");
            timThay = 1;
        }
    }
    if (timThay == 0) {
        printf("\nKhong tim thay khach hang.\n");
    }
}

// Hàm check-out phòng
void checkOut(int soPhong) {
    int i, timThay = 0, soNgay;
    float tienPhong = 0;
    for (i = 0; i < count; i++) {
        if (phongs[i].trangThai == 1 && phongs[i].soPhong == soPhong) {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1) {
        printf("\nNhap so ngay:\t");
        scanf("%d", &soNgay);
        tienPhong = soNgay * phongs[i].giaThue;

        printf("\n\t######## Chi tiet CheckOut ########\n");
        printf("\nTen khach hang : %s", phongs[i].kh.ten);
        printf("\nSo phong : %d", phongs[i].soPhong);
        printf("\nDia chi : %s", phongs[i].kh.diaChi);
        printf("\nDien thoai : %s", phongs[i].kh.dienThoai);
        printf("\nTong tien : %.2f /", tienPhong);
        printf("\nTien tam ung: %.2f /", phongs[i].kh.tienTamUng);
        printf("\n*** Tong so tien phai tra: %.2f/ chi", tienPhong - phongs[i].kh.tienTamUng);

        phongs[i].trangThai = 0;
    }
}

// Hàm qu?n lý phòng
void quanLyPhong() {
    int opt, soPhong, i, flag = 0;
    do {
        printf("\n### Quan Ly Phong ###");
        printf("\n1. Them Phong");
        printf("\n2. Tim Phong");
        printf("\n3. Quay lai Menu chinh");
        printf("\n\nNhap lua chon: ");
        scanf("%d", &opt);

        // Câu l?nh switch
        switch (opt) {
        case 1:
            printf("\nNhap so phong: ");
            scanf("%d", &soPhong);
            for (i = 0; i < count; i++) {
                if (phongs[i].soPhong == soPhong) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                printf("\nSo phong da ton tai.\nVui long nhap so khac");
                flag = 0;
            } else {
                phongs[count] = themPhong(soPhong);
                count++;
            }
            break;
        case 2:
            printf("\nNhap so phong: ");
            scanf("%d", &soPhong);
            timPhong(soPhong);
            break;
        case 3:
            // Không làm gì c?
            break;
        default:
            printf("\nVui long nhap lua chon dung");
            break;
        }
    } while (opt != 3);
}

// Hàm main
int main() {
    int opt, soPhong;
    char tenKhach[100];

    do {
        printf("######## Quan Ly Khach San #########\n");
        printf("\n1. Quan Ly Phong");
        printf("\n2. Check-In Phong");
        printf("\n3. Phong Trong");
        printf("\n4. Tim Khach Hang");
        printf("\n5. Check-Out Phong");
        printf("\n6. Bao Cao Khach");
        printf("\n7. Thoat");
        printf("\n\nNhap lua chon: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            quanLyPhong();
            break;
        case 2:
            if (count == 0) {
                printf("\nDu lieu phong khong co.\nVui long them phong truoc.");
            } else
                checkIn();
            break;
        case 3:
            if (count == 0) {
                printf("\nDu lieu phong khong co.\nVui long them phong truoc.");
            } else
                phongTrong();
            break;
        case 4:
            if (count == 0) {
                printf("\nKhong co phong.\nVui long them phong truoc.");
            } else {
                printf("Nhap ten khach hang: ");
                getchar();  // Ð?c ký t? m?i
                fgets(tenKhach, sizeof(tenKhach), stdin);
                tenKhach[strcspn(tenKhach, "\n")] = '\0'; // Lo?i b? ký t? newline
                timKhachHang(tenKhach);
            }
            break;
        case 5:
            if (count == 0) {
                printf("\nKhong co phong.\nVui long them phong truoc.");
            } else {
                printf("Nhap so phong : ");
                scanf("%d", &soPhong);
                checkOut(soPhong);
            }
            break;
        case 6:
            baoCaoKhach();
            break;
        case 7:
            printf("\nCAM ON BAN DA SU DUNG PHAN MEM\n");
            break;
        default:
            printf("\nVui long nhap lua chon dung");
            break;
        }
    } while (opt != 7);

    return 0;
}

