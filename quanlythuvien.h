#ifndef QUANLYTHUVIEN_H
#define QUANLYTHUVIEN_H
#include "sach.h"
#include "sinhvien.h"
#include<vector>

class quanlythuvien
{
private:
    vector<Sach> danhSachSach;
    vector<SinhVien> danhSachSV;

    const string SACH_FILE="sach.dat"; 
    const string SINHVIEN_FILE="sinhvien.dat";

    void docDulieuSach();
    void ghiDuLieuSach();//để trong private để chỉ có các hàm trong cùng lớp mới gọi đc tránh việc ng khác vô tình truy cập
    void docDuLieuSV();
    void ghiDuLieuSV();

    Sach*timSach(string maSach);//dùng con trỏ để dễ dàng truy cập và thay đổi dữ liệu gốc
    SinhVien*timSV(string maSV);

public:
    quanlythuvien();
    
    void themSach();
    void suaSach();
    void xoaSach();
    
    void themSinhVien();
    void suaSinhVien();
    void xoaSinhVien();
    
    void muonSach();
    void traSach();
    
    void lietKeTatCaSach();
    void lietKeSachSVMuon();
    void lietKeTatCaSachDangMuon();
    
    void hienThiMenu();
    void xuLyMenu();
};

#endif 

