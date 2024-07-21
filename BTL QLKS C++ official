#include <iostream>
#include <cstring>

#define max 100
using namespace std;

//Lop Khach Hang
class KhachHang
{
public:
    char ten[100];
    char diaChi[100];
    char dienThoai[12];
    char tuNgay[20];
    char denNgay[20];
    float tienTamUng;
    int maDatPhong;
};

class Phong
{
public:
    char loai;
    char kieu;
    char dieuHoa;
    int soPhong;
    int giaThue;
    int trangThai;

    KhachHang kh;
    Phong themPhong(int);
    void timPhong(int);
    void hienThiPhong(Phong);
};

//Khai bao toan cuc
Phong phongs[max];
int count = 0;

Phong Phong::themPhong(int soPhong)
{
    Phong phong;
    phong.soPhong = soPhong;
    cout << "\nLoai dieu hoa (C/K) : ";
    cin >> phong.dieuHoa;
    cout << "\nLoai tien nghi (C/BT) : ";
    cin >> phong.loai;
     cin.ignore();
    cout << "\nLoai kich thuoc (L/N) : ";
    cin >> phong.kieu;
    cout << "\nGia thue hang ngay : ";
    cin >> phong.giaThue;
    phong.trangThai = 0;

    cout << "\nPhong da duoc them thanh cong!";
    return phong;
}

void Phong::timPhong(int soPhong)
{
    int i, timThay = 0;
    for (i = 0; i < count; i++)
    {
        if (phongs[i].soPhong == soPhong)
        {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1)
    {
        cout << "Chi tiet phong\n";
        if (phongs[i].trangThai == 1)
        {
            cout << "\nPhong da duoc dat truoc";
        }
        else
        {
            cout << "\nPhong dang trong";
        }
        hienThiPhong(phongs[i]);
    }
    else
    {
        cout << "\nKhong tim thay phong";
    }
}

void Phong::hienThiPhong(Phong tempPhong)
{
    cout << "\nSo phong: \t" << tempPhong.soPhong;
    cout << "\nLoai dieu hoa (C/K) " << tempPhong.dieuHoa;
    cout << "\nLoai tien nghi (C/BT) " << tempPhong.loai;
    cout << "\nLoai kich thuoc (L/N) " << tempPhong.kieu;
    cout << "\nGia thue: " << tempPhong.giaThue;
}

//Lop Quan Ly Khach San
class QuanLyKhachSan : protected Phong
{
public:
    void checkIn();
    void phongTrong();
    void timKhachHang(char *);
    void checkOut(int);
    void baoCaoKhach();
};

void QuanLyKhachSan::baoCaoKhach()
{
    if (count == 0)
    {
        cout << "\nKhong co khach trong khach san !!";
    }
    for (int i = 0; i < count; i++)
    {
        if (phongs[i].trangThai == 1)
        {
            cout << "\nTen khach hang : " << phongs[i].kh.ten;
            cout << "\nSo phong : " << phongs[i].soPhong;
            cout << "\nDia chi (chi thanh pho) : " << phongs[i].kh.diaChi;
            cout << "\nDien thoai : " << phongs[i].kh.dienThoai;
            cout << "\n---------------------------------------";
        }
    }
}

void QuanLyKhachSan::checkIn()
{
    int i, timThay = 0, soPhong;

    cout << "\nNhap so phong : ";
    cin >> soPhong;
    for (i = 0; i < count; i++)
    {
        if (phongs[i].soPhong == soPhong)
        {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1)
    {
        if (phongs[i].trangThai == 1)
        {
            cout << "\nPhong da duoc dat truoc";
            return;
        }  
        cout << "\nNhap ten khach hang (ten dau tien): ";
        cin.ignore();
        cin.getline(phongs[i].kh.ten, 100);

        cout << "\nNhap dia chi (chi thanh pho): ";
        cin.getline(phongs[i].kh.diaChi, 100);
 		cin.ignore();
        cout << "\nNhap dien thoai: ";
        cin.getline(phongs[i].kh.dienThoai, 12);

        cout << "\nNhap ngay den: ";
        cin.getline(phongs[i].kh.tuNgay, 20);

        cout << "\nNhap ngay di: ";
        cin.getline(phongs[i].kh.denNgay, 20);

        cout << "\nNhap tien tam ung: ";
        cin >> phongs[i].kh.tienTamUng;

        phongs[i].trangThai = 1;

        cout << "\nKhach hang da check-in thanh cong..";
    }
}

void QuanLyKhachSan::phongTrong()
{
    int i, timThay = 0;
    for (i = 0; i < count; i++)
    {
        if (phongs[i].trangThai == 0)
        {
            hienThiPhong(phongs[i]);
            cout << "\n\nNhan enter de xem phong tiep theo";
            timThay = 1;
        }
    }
    if (timThay == 0)
    {
        cout << "\nTat ca cac phong da duoc dat truoc";
    }
}

void QuanLyKhachSan::timKhachHang(char *ten)
{
    int i, timThay = 0;
    for (i = 0; i < count; i++)
    {
        if (phongs[i].trangThai == 1 && strcmp(phongs[i].kh.ten, ten) == 0)
        {
            cout << "\nTen khach hang: " << phongs[i].kh.ten;
            cout << "\nSo phong: " << phongs[i].soPhong;
            cout << "\n\nNhan enter de xem thong tin tiep theo\n";
            timThay = 1;
        }
    }
    if (timThay == 0)
    {
        cout << "\nKhong tim thay khach hang.\n";
    }
}

void QuanLyKhachSan::checkOut(int soPhong)
{
    int i, timThay = 0, soNgay;
    float tienPhong = 0;
    for (i = 0; i < count; i++)
    {
        if (phongs[i].trangThai == 1 && phongs[i].soPhong == soPhong)
        {
            timThay = 1;
            break;
        }
    }
    if (timThay == 1)
    {
        cout << "\nNhap so ngay:\t";
        cin >> soNgay;
        tienPhong = soNgay * phongs[i].giaThue;

        cout << "\n\t######## Chi tiet CheckOut ########\n";
        cout << "\nTen khach hang : " << phongs[i].kh.ten;
        cout << "\nSo phong : " << phongs[i].soPhong;
        cout << "\nDia chi : " << phongs[i].kh.diaChi;
        cout << "\nDien thoai : " << phongs[i].kh.dienThoai;
        cout << "\nTong tien : " << tienPhong << " /";
        cout << "\nTien tam ung: " << phongs[i].kh.tienTamUng << " /";
        cout << "\n*** Tong so tien phai tra: " << tienPhong - phongs[i].kh.tienTamUng << "/ chi";

        phongs[i].trangThai = 0;
    }
}

void quanLyPhong()
{
    Phong phong;
    int opt, soPhong, i, flag = 0;
    do
    {
        cout << "\n### Quan Ly Phong ###";
        cout << "\n1. Them Phong";
        cout << "\n2. Tim Phong";
        cout << "\n3. Quay lai Menu chinh";
        cout << "\n\nNhap lua chon: ";
        cin >> opt;

        //Cau lenh switch
        switch (opt)
        {
        case 1:
            cout << "\nNhap so phong: ";
            cin >> soPhong;
            for (i = 0; i < count; i++)
            {
                if (phongs[i].soPhong == soPhong)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << "\nSo phong da ton tai.\nVui long nhap so khac";
                flag = 0;
            }
            else
            {
                phongs[count] = phong.themPhong(soPhong);
                count++;
            }
            break;
        case 2:
            cout << "\nNhap so phong: ";
            cin >> soPhong;
            phong.timPhong(soPhong);
            break;
        case 3:
            //khong lam gi ca
            break;
        default:
            cout << "\nVui long nhap lua chon dung";
            break;
        }
    } while (opt != 3);
}

int main()
{
    QuanLyKhachSan qlks;
    int opt, soPhong;
    char tenKhach[100];

    do
    {
        cout << "######## Quan Ly Khach San #########\n";
        cout << "\n1. Quan Ly Phong";
        cout << "\n2. Check-In Phong";
        cout << "\n3. Phong Trong";
        cout << "\n4. Tim Khach Hang";
        cout << "\n5. Check-Out Phong";
        cout << "\n6. Bao Cao Khach";
        cout << "\n7. Thoat";
        cout << "\n\nNhap lua chon: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            quanLyPhong();
            break;
        case 2:
            if (count == 0)
            {
                cout << "\nDu lieu phong khong co.\nVui long them phong truoc.";
            }
            else
                qlks.checkIn();
            break;
        case 3:
            if (count == 0)
            {
                cout << "\nDu lieu phong khong co.\nVui long them phong truoc.";
            }
            else
                qlks.phongTrong();
            break;
        case 4:
            if (count == 0)
            {
                cout << "\nKhong co phong.\nVui long them phong truoc.";
            }
            else
            {
                cout << "Nhap ten khach hang: ";
                cin.ignore();
                cin.getline(tenKhach, 100);
                qlks.timKhachHang(tenKhach);
            }
            break;
        case 5:
            if (count == 0)
            {
                cout << "\nKhong co phong.\nVui long them phong truoc.";
            }
            else
            {
                cout << "Nhap so phong : ";
                cin >> soPhong;
                qlks.checkOut(soPhong);
            }
            break;
        case 6:
            qlks.baoCaoKhach();
            break;
        case 7:
            cout << "\nCAM ON BAN DA SU DUNG PHAN MEM\n";
            break;
        default:
            cout << "\nVui long nhap lua chon dung";
            break;
        }
    } while (opt != 7);

    return 0;
}

