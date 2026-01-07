#include "tailieu.h"
TaiLieu::TaiLieu():namXuatBan(0),dangMuon(false){}
TaiLieu::TaiLieu(string ma, string ten, int nam):DoiTuong(ma,ten),namXuatBan(nam),dangMuon(false){}
TaiLieu::~TaiLieu(){}//đây là hàm hủy nó sẽ tự động xóa khi hàm này đc gọi xg giúp giải phóng bộ nhớ

int TaiLieu::getNamXuatBan() const {return namXuatBan;}
bool TaiLieu::getDangMuon() const {return dangMuon;}
string TaiLieu::getMaSVMuon() const { return maSVMuon; }

void TaiLieu::setNamXuatBan(int nam) { namXuatBan = nam; }
void TaiLieu::setDangMuon(bool dm) { dangMuon = dm; }
void TaiLieu::setMaSVMuon(string ma) { maSVMuon = ma; }

void TaiLieu::nhapThongTin(){
    cout<<"nhap ma tai lieu: ";
    getline(cin,ma);
    cout<<"nhap ten tai lieu: ";
    getline(cin,ten);
    cout << "Nhap nam xuat ban: ";
    cin >> namXuatBan;
    cin.ignore();
}
void TaiLieu::hienThi()const{
    cout<<"ma tai lieu: "<<ma<<endl;
    cout<< " Ten: " << ten ;
    cout<< " Nam XB: " << namXuatBan; 
    cout<< " Trang thai: " << (dangMuon ? "Dang duoc muon" : "Co san"); 
}
void TaiLieu::ghiFile(ofstream&out)const{
    size_t len;//đếm số lượng kí tự
    len=ma.size();
    out.write((char*)&len,sizeof(len));// 2. Ghi độ dài (lấy địa chỉ &, ép kiểu char*)
    out.write(ma.c_str(),len);// 3. Ghi nội dung (dùng trực tiếp c_str(), không cần &

    len=ten.size();
    out.write((char*)&len,sizeof(len));
    out.write(ten.c_str(), len);

    out.write((char*)&namXuatBan, sizeof(namXuatBan));
    out.write((char*)&dangMuon, sizeof(dangMuon));

    len = maSVMuon.size();
    out.write((char*)&len, sizeof(len));
    out.write(maSVMuon.c_str(), len);
}
void TaiLieu::docFile(ifstream&in){
    size_t len;
    in.read((char*)&len, sizeof(len));//đọc độ dài chuỗi

    ma.resize(len);//chuẩn bị bộ nhớ
    in.read(&ma[0], len);// đọc nội dung chuỗi đc lấy ra ở trên

    ten.resize(len);
    in.read(&ten[0], len);
    
    
    in.read((char*)&namXuatBan, sizeof(namXuatBan));
    in.read((char*)&dangMuon, sizeof(dangMuon));
    
    in.read((char*)&len, sizeof(len));
    maSVMuon.resize(len);
    in.read(&maSVMuon[0], len);
}