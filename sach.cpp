#include "sach.h"
#include<fstream>
#include<string>
Sach::Sach():namXuatBan(0),dangMuon(false){}
Sach:: Sach(string ma,string ten,string tg,int nam):maSach(ma),tenSach(ten),tacGia(tg),namXuatBan(nam){}
string Sach::getMaSach()const{return maSach;}
string Sach::getTenSach()const{return tenSach;}
string Sach::getTacGia()const{return tacGia;}
int Sach::getNamXuatBan()const{return namXuatBan;}
bool Sach::getDangMuon()const{return dangMuon;}


void Sach::setTenSach(string tg){tacGia=tg;}
void Sach::setNamXuatBan(int nam){namXuatBan=nam;}
void Sach::setDangMuon(bool dm){dangMuon=dm;}
void Sach::setMaSVMuon(string ma) { maSVMuon = ma; }

void Sach::nhapThongTin(){
    cout<<"nhap ma sach: ";
    getline(cin,maSach);
    cout<<"nhap ten sach: ";
    getline(cin,tenSach);
    cout<<"ten tac gia: ";
    getline(cin, tacGia);
    cout << "Nhap nam xuat ban: ";
    cin >> namXuatBan;
    cin.ignore();
}
void Sach::hienThi(){
    cout<<"ma sach: "<<maSach<<endl;
    cout<< " | Ten: " << tenSach ;
    cout<< " | Tac gia: " << tacGia; 
    cout<< " | Nam XB: " << namXuatBan; 
    cout<< " | Trang thai: " << (dangMuon ? "Dang duoc muon" : "Co san"); 
}
void Sach::ghiFile(ofstream&out){
    size_t len;//đếm số lượng kí tự
    len=maSach.size();
    out.write((char*)&len,sizeof(len));// 2. Ghi độ dài (lấy địa chỉ &, ép kiểu char*)
    out.write(maSach.c_str(),len);// 3. Ghi nội dung (dùng trực tiếp c_str(), không cần &

    len=tenSach.size();
    out.write((char*)&len,sizeof(len));
    out.write(tenSach.c_str(), len);

    len=tacGia.size();
    out.write((char*)&len,sizeof(len));
    out.write(tacGia.c_str(),len);

    out.write((char*)&namXuatBan, sizeof(namXuatBan));
    out.write((char*)&dangMuon, sizeof(dangMuon));

    len = maSVMuon.size();
    out.write((char*)&len, sizeof(len));
    out.write(maSVMuon.c_str(), len);
}
void Sach::docFile(ifstream&in){
    size_t len;
    in.read((char*)&len,sizeof(len));
     in.read((char*)&len, sizeof(len));
    tenSach.resize(len);
    in.read(&tenSach[0], len);
    
    in.read((char*)&len, sizeof(len));
    tacGia.resize(len);
    in.read(&tacGia[0], len);
    
    in.read((char*)&namXuatBan, sizeof(namXuatBan));
    in.read((char*)&dangMuon, sizeof(dangMuon));
    
    in.read((char*)&len, sizeof(len));
    maSVMuon.resize(len);
    in.read(&maSVMuon[0], len);
}




