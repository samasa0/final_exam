#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "doituong.h"
using namespace std;

class SinhVien: public DoiTuong {
private:
    string maSV;
    string tenSV;
    string lop;
    string sdt;
    vector<string> sachDangMuon;

public:
    SinhVien();
    SinhVien(string ma, string ten, string l, string sdt);
    
    // Getter
    string getMaSV() const;
    string getTenSV() const;
    string getLop() const;
    string getSDT() const;
    vector<string> getSachDangMuon() const;
    
    // Setter
    void setTenSV(string ten);
    void setLop(string l);
    void setSDT(string sdt);
    
    void themSachMuon(string maSach);
    void xoaSachMuon(string maSach);
    
    void nhapThongTin();
    void hienThi() const;
    
    // Đọc/ghi file nhị phân
    void ghiFile(ofstream &out) const;
    void docFile(ifstream &in);
};

#endif
