#include "sinhVien.h"

SinhVien::SinhVien() {}

SinhVien::SinhVien(string ma, string ten, string l, string sd) 
    : maSV(ma), tenSV(ten), lop(l), sdt(sd) {}

string SinhVien::getMaSV() const { return maSV; }
string SinhVien::getTenSV() const { return tenSV; }
string SinhVien::getLop() const { return lop; }
string SinhVien::getSDT() const { return sdt; }
vector<string> SinhVien::getSachDangMuon() const { return sachDangMuon; }

void SinhVien::setTenSV(string ten) { tenSV = ten; }
void SinhVien::setLop(string l) { lop = l; }
void SinhVien::setSDT(string sd) { sdt = sd; }

void SinhVien::themSachMuon(string maSach) {
    sachDangMuon.push_back(maSach);
}

void SinhVien::xoaSachMuon(string maSach) {
    for (auto it = sachDangMuon.begin(); it != sachDangMuon.end(); ++it) {
        if (*it == maSach) {
            sachDangMuon.erase(it);
            break;
        }
    }
}

void SinhVien::nhapThongTin() {
    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);
    cout << "Nhap ten sinh vien: ";
    getline(cin, tenSV);
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
}

void SinhVien::hienThi() const {
    cout << "Ma SV: " << maSV 
         << " | Ten: " << tenSV 
         << " | Lop: " << lop 
         << " | SDT: " << sdt 
         << " | So sach dang muon: " << sachDangMuon.size() << endl;
}

void SinhVien::ghiFile(ofstream &out) const {
    size_t len;
    
    len = maSV.size();
    out.write((char*)&len, sizeof(len));
    out.write(maSV.c_str(), len);
    
    len = tenSV.size();
    out.write((char*)&len, sizeof(len));
    out.write(tenSV.c_str(), len);
    
    len = lop.size();
    out.write((char*)&len, sizeof(len));
    out.write(lop.c_str(), len);
    
    len = sdt.size();
    out.write((char*)&len, sizeof(len));
    out.write(sdt.c_str(), len);
    
    size_t soSach = sachDangMuon.size();
    out.write((char*)&soSach, sizeof(soSach));
    for (const auto &ms : sachDangMuon) {
        len = ms.size();
        out.write((char*)&len, sizeof(len));
        out.write(ms.c_str(), len);
    }
}

void SinhVien::docFile(ifstream &in) {
    size_t len;
    
    in.read((char*)&len, sizeof(len));
    maSV.resize(len);
    in.read(&maSV[0], len);
    
    in.read((char*)&len, sizeof(len));
    tenSV.resize(len);
    in.read(&tenSV[0], len);
    
    in.read((char*)&len, sizeof(len));
    lop.resize(len);
    in.read(&lop[0], len);
    
    in.read((char*)&len, sizeof(len));
    sdt.resize(len);
    in.read(&sdt[0], len);
    
    size_t soSach;
    in.read((char*)&soSach, sizeof(soSach));
    sachDangMuon.clear();
    for (size_t i = 0; i < soSach; ++i) {
        in.read((char*)&len, sizeof(len));
        string ms;
        ms.resize(len);
        in.read(&ms[0], len);
        sachDangMuon.push_back(ms);
    }
}
