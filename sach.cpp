#include "sach.h"

Sach:: Sach(){}
Sach:: Sach(string ma,string ten,string tg,int nam,string tl):TaiLieu(ma, ten ,nam),tacGia(tg),theLoai(tl){}
Sach::~Sach(){}

string Sach::getTacGia()const{return tacGia;}
string Sach::getTheLoai()const{return theLoai;}


void Sach::setTacGia(string tg) { tacGia = tg; }
void Sach::setTheLoai(string tl) {theLoai=tl;}

void Sach::nhapThongTin(){
    cout<<"nhap ma sach: ";
    getline(cin,ma);
    cout<<"nhap ten sach: ";
    getline(cin,ten);
    cout<<"ten tac gia: ";
    getline(cin, tacGia);
    cout << "Nhap nam xuat ban: ";
    cin >> namXuatBan;
    cout<<"nhap the loai: ";
    getline(cin, theLoai);
    cin.ignore();
}
void Sach::hienThi()const {
    cout<<"ma sach: "<<ma<<endl;
    cout<< "  Ten: " << ten ;
    cout<< "  Tac gia: " << tacGia; 
    cout<< "  Nam XB: " << namXuatBan; 
    cout<< "  The Loai " << theLoai;
    cout<< "  Trang thai: " << (dangMuon ? "Dang duoc muon" : "Co san"); 
}
void Sach::ghiFile(ofstream&out)const{
    TaiLieu::ghiFile(out);//ghi thông tin từ lớp cha
    size_t len;//đếm số lượng kí tự
    len=tacGia.size();
    out.write((char*)&len,sizeof(len));// 2. Ghi độ dài (lấy địa chỉ &, ép kiểu char*)
    out.write(tacGia.c_str(),len);// 3. Ghi nội dung (dùng trực tiếp c_str(), không cần &

    

    len=theLoai.size();
    out.write((char*)&len,sizeof(len));
    out.write(theLoai.c_str(),len);

}
void Sach::docFile(ifstream&in){
    TaiLieu:docFile(in);
    size_t len;
    
    in.read((char*)&len, sizeof(len));
    tacGia.resize(len);
    in.read(&tacGia[0], len);
    
    in.read((char*)&len, sizeof(len));
    theLoai.resize(len);
    in.read(&theLoai[0], len);
}




