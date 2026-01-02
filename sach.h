#ifndef SACH_H
#define SACH_H
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
class sach
{
    private:
    string maSach;
    string tenSach;
    string tacGia;
    int namXuatBan;
    bool dangMuon;
    string maSVMuon;
    public:
    sach();
    sach(string ma,string ten,string tg,int nam);
    // getter
    string getMaSach()const;
    string getTenSach()const;
    string getTacGia()const;
    int getNamXuatBan()const;
    bool getDangMuon()const;
    string getMaSVMuon()const;
    //setter
     void setMaSach(string ten);
     void setTenSach(string tg);
     void setNamXuatBan(int nam);
     void setDangMuon(bool dm);
    void nhapThongTin();
    void hienThi();

    void ghiFile(ofstream& out);
    void docFile(ifstream& is);
};

#endif
