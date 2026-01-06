#ifndef TAILIEU_H
#define TAILIEU_H
#include "doituong.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TaiLieu :public DoiTuong{
    protected:
    int namXuatBan;
    bool dangMuon;
    string maNguoiMuon;
    public:
        TaiLieu();
        TaiLieu(string ma, string ten, int nam);
        virtual ~TaiLieu();

        int getNamXuatBan()const;
        bool getDangMuon()const;
        string getMaNguoiMuon()const;

        void setNamXuatBan(int nam);
        void setDangMuon(bool dm);
        void setMaNguoiMuon(string ma);

    virtual void nhapThongTin() override;
    virtual void hienThi() const override;
    virtual void ghiFile(ofstream &out) const override;
    virtual void docFile(ifstream &in) override;   
};
#endif