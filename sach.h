#ifndef SACH_H
#define SACH_H
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
class Sach
{
    private:
    string maSach;
    string tenSach;
    string tacGia;
    int namXuatBan;
    bool dangMuon;
    string maSVMuon;
    public:
    Sach();
    Sach(string ma,string ten,string tg,int nam);
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
     void setMaSVMuon(string ma);

    void nhapThongTin();
    void hienThi();

    void ghiFile(ofstream& out);
    void docFile(ifstream& in);
};

#endif
