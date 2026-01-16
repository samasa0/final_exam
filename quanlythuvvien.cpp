#include "quanlythuvien.h"
#include<limits>

 quanlythuvien::quanlythuvien(){
    docDulieuSach();
    docDuLieuSV();
 }
 // lấy dữ liệu từ sach_file để đẩy vào danhsachsach
 void quanlythuvien::docDulieuSach(){
    ifstream in(SACH_FILE, ios::binary);
    if(!in) return;
    size_t soLuong;
    in.read((char*)&soLuong, sizeof(soLuong));
    for(size_t i=0; i<soLuong; i++){
        Sach s;
        s.docFile(in);
        danhSachSach.push_back(s);
    }
    in.close();
 }
 void quanlythuvien::ghiDuLieuSach(){
    ofstream out(SACH_FILE, ios::binary);//mở luồng ghi file nhị phân
    size_t soLuong= danhSachSach.size();
    out.write((char*)&soLuong,sizeof(soLuong));
    for (const auto &s : danhSachSach) 
    {
    s.ghiFile(out);
    }
    out.close();
 }
void quanlythuvien::docDuLieuSV(){
    ifstream in(SINHVIEN_FILE, ios :: binary);
    if(!in) return;
    size_t soLuong;
    in.read((char*)&soLuong, sizeof(soLuong));
    for(size_t i=0; i<soLuong; i++){
        SinhVien sv;
        sv.docFile(in);
        danhSachSV.push_back(sv);
    }
    in.close();
}

void quanlythuvien::ghiDuLieuSV(){
    ofstream out(SINHVIEN_FILE, ios:: binary);
    size_t soLuong=danhSachSV.size();
    out.write((char*)&soLuong,sizeof(soLuong));
    for(const auto& sv:danhSachSV)
    {
    sv.ghiFile(out);
    }
    out.close();
}
Sach* quanlythuvien::timSach(string ma)//*
{
    for(auto&s: danhSachSach)//Duyệt qua từng phần tử trong vector danhSachSach
    {
        if (s.getMa()==ma){
            return &s;
        }
    }
    return nullptr;
}
SinhVien* quanlythuvien::timSV(string ma)
{
    for (auto& sv:danhSachSV){
        if(sv.getMaSV()==ma){
            return &sv;
        }
    }
    return nullptr;
}

void quanlythuvien::themSach(){
    cout<<" Them sach moi "<<endl;
    Sach sachmoi;
    sachmoi.nhapThongTin();
    if(timSach(sachmoi.getMa())){
        cout<<" ma sach da ton tai "<<endl;
        return;
    }
    danhSachSach.push_back(sachmoi);
    ghiDuLieuSach();
    cout<<" them sach thanh cong "<<endl;

}

void quanlythuvien::suaSach() {
    cout<<"\n sua thong tin sach "<<endl;
    string maSach;
    cout<<" nhap ma sach can sua  "<<endl;
    getline(cin,maSach);
    Sach*sach=timSach(maSach);
    if(!sach){
        cout<<" khong tim thay sach "<<endl;
        return;
    }
    cout<<"\n thong tin hien tai "<<endl;
    sach->hienThi();
    cout << "\n(Nhan Enter de giu nguyen thong tin)" << endl;
    
    string ten, tacGia, tl;
    int nam;
    
    cout << "ten sach moi: ";
    getline(cin, ten);
    if (!ten.empty()) sach->setTen(ten);//nếu ten ko trống thì sach gọi hàm set
    
    cout << "tac gia moi: ";
    getline(cin, tacGia);
    if (!tacGia.empty()) sach->setTacGia(tacGia);
    
    cout << "nha xuat ban moi: ";
    getline(cin, tl);
    if (!tl.empty()) sach->setTheLoai(tl);   

    cout << "nam xuat ban moi (0 de bo qua): ";
    cin >> nam;
    cin.ignore();
    if (nam != 0) sach->setNamXuatBan(nam);  

    ghiDuLieuSach();
    cout << "Cap nhat thong tin sach thanh cong!" << endl;
}

void quanlythuvien::xoaSach(){
    cout<<"\n xoa sach "<<endl;
    string maSach;
    cout<<" nhap ma sach can xoa ";
    getline(cin, maSach);
    Sach* sach = timSach(maSach);
    if(!sach) {
        cout<<" ko tim thay sach ";
        return;
    }
    if(sach->getDangMuon()){
        cout<<" sach dang muon ko the xoa ";
         return;
    }
     for (auto it = danhSachSach.begin()//tạo con trỏ chỉ vào vị trí đầu tiên của chuỗi
        ;it != danhSachSach.end()//điều kiện kết thúc là khi con trỏ chỉ vào sau phần tử cuối cùng của chuỗi
        ;++it) 
     {
        if (it->getMa() == maSach) {
            danhSachSach.erase(it);
            break;
        }
    }
    
    ghiDuLieuSach();
    cout << "xoa sach thanh cong" << endl;
}
void quanlythuvien::themSinhVien(){
    cout<<"\n them sinh vien moi ";
    SinhVien svMoi;
    svMoi.nhapThongTin();
    if (timSV(svMoi.getMaSV())){
        cout<<" ma sinh vien da ton tai "<<endl;
        return ;
    }
    danhSachSV.push_back(svMoi);
    ghiDuLieuSV();
    cout<<" them sinh vien thanh cong "<<endl;
}
void quanlythuvien::suaSinhVien(){
    cout<<"/n sua thong tin sinh vien "<<endl;
    string maSV;
    cout<<" nhap ma sinh vien can sua "<<endl;
    getline(cin,maSV);
    SinhVien*sv=timSV(maSV);
    if(!sv){
        cout<<" khong tim thay sinh vien "<<endl;
        return ;
    }
    cout<<"\n thong tin hien tai "<<endl;
    sv->hienThi();
    cout << "\n Nhan Enter de giu nguyen thong tin " << endl;
    string ten,lop ,sdt;
    cout<<" ten sinh vien moi ";
    getline(cin,ten);
    if(!ten.empty()) sv->setTen(ten);

    cout<<" lop moi ";
    getline(cin, lop);
    if(!lop.empty()) sv->setLop(lop);

    cout<<" sdt moi ";
    getline(cin,sdt);
    if(!sdt.empty()) sv->setSDT(sdt);

    ghiDuLieuSV();
    cout<<" cap nhat thanh cong ";
}
void quanlythuvien::xoaSinhVien(){
    cout<<"/n xoa sinh vien "<<endl;
    string maSV;
    cout<<" nhap ma sinh vien can xoa "<<endl;
    getline(cin,maSV);

    SinhVien*sv=timSV(maSV)    ;
    if(!sv){
        cout<<"khong tim thay ma sinh vien "<<endl;
        return ;
    }
    if(!sv->getSachDangMuon().empty()){
        cout<<" khong the xoa vi sinh vien dang muon sach "<<endl;
    }
    for(auto it = danhSachSV.begin();it!=danhSachSV.end();it++){
        if( it->getMaSV()==maSV){
            danhSachSV.erase(it);
            break;
        }
    }
    ghiDuLieuSV();
    cout<<" xoa sinh vien thanh cong ";
}
void quanlythuvien::muonSach(){
    cout<<"\n muon sach "<< endl;
    string maSV, maSach;
    cout<<"nhap ma sinh vien "<<endl;
    getline(cin,maSV);
    cout << "Nhap ma sach ";
    getline(cin, maSach);

    SinhVien*sv=timSV(maSV);
    if(!sv){
        cout<<" khong tim thay sinh vien "<<endl;
        return;
    }
    Sach*sach=timSach(maSach);
    if(!sach){
        cout<<" khong tim thay sach"<<endl;
        return;
    }
    if(sach->getDangMuon()){
        cout<<"sach dang đc muon "<<endl;
        return;
    }
    sach->setDangMuon(true);
    sach->setMaSVMuon(maSV);
    sv->themSachMuon(maSach);
    ghiDuLieuSach();
    ghiDuLieuSV();
    cout<<" muon sach thanh cong "<<endl;
}
void quanlythuvien::traSach() {
    cout << "\n tra sach" << endl;
    string maSV, maSach;
    
    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);
    cout << "Nhap ma sach: ";
    getline(cin, maSach);
    
    SinhVien* sv = timSV(maSV);
    if (!sv) {
        cout << "khong tim thay sinh vien" << endl;
        return;
    }
    
    Sach* sach = timSach(maSach);
    if (!sach) {
        cout << "khong tim thay sach" << endl;
        return;
    }
    if(!sach->getDangMuon()||sach->getMaSVMuon()!=maSV){
        cout<<" sinh vien khong muon sach nay ";
        return;
    }
    sach->setDangMuon(false);
    sach->setMaSVMuon("");
    sv->xoaSachMuon(maSach);
    cout<<" tra sach thanh cong "<<endl;
    ghiDuLieuSach();
    ghiDuLieuSV();

}
void quanlythuvien::lietKeTatCaSach(){
    cout<<" danh sach tat ca cac sach trong thu vien "<<endl;
    if(danhSachSach.empty()){
        cout<<" thu vien trong  ";
        return;
    }
    for(size_t i=0;i<danhSachSach.size();i++){
        cout<<i+1<<". ";
        danhSachSach[i].hienThi();
    }
}
void quanlythuvien:: lietKeSachSVMuon(){
    cout<<" danh sach sach ma sinh vien dang muon ";
    string maSV;
    cout<<" nhap ma sinh vien can xoa "<<endl;
    getline(cin,maSV);

    SinhVien*sv=timSV(maSV)    ;
    if(!sv){
        cout<<"khong tim thay ma sinh vien "<<endl;
        return ;
    }
    vector<string> sachMuon = sv->getSachDangMuon();
    if (sachMuon.empty()) {
        cout << " sinh vien " << sv->getTen() << " chua muon sach nao " << endl;
        return;
    }
    cout<<"\n sinh vien "<<sv->getTen()<<" ma sinh vien "<<maSV<<endl;
    cout<<" so sach dang muon "<<sachMuon.size()<<endl;

      for (size_t i = 0; i < sachMuon.size(); ++i) {
        Sach* sach = timSach(sachMuon[i]);
        if (sach) {
            cout << i + 1 << ". ";
            sach->hienThi();
        }
    }
}
void quanlythuvien::lietKeTatCaSachDangMuon(){
    cout<<"/n danh sach dang dc muon "<<endl;
    int dem=0;
    for(const auto&s:danhSachSach){
        if(s.getDangMuon()){
            dem++;
        }
    
    }
    cout<<" tong so sach dang dc muon "<<dem;
    int stt=1;
    for(const auto&s:danhSachSach){
        if(s.getDangMuon()){
            SinhVien*sv=timSV(s.getMaSVMuon());
            string tenSV=sv? sv->getTen():" khong xac dinh ";
            cout<<stt<<" ma sach "<<s.getMa()<<" ten sach "<<s.getTen()<<" nguoi muon "<<tenSV<<" ma sinh vien "<<sv->getMaSV()<<endl;
        }
    }
}
void quanlythuvien::hienThiMenu() {
    cout << "\n" << " " << endl;
    cout << "          HE THONG QUAN LY THU VIEN" << endl;
    cout << " " << endl;
    cout << "1.  Nhap them 1 cuon sach" << endl;
    cout << "2.  Sua thong tin sach (theo ma)" << endl;
    cout << "3.  Xoa 1 cuon sach (theo ma)" << endl;
    cout << "4.  Nhap thong tin sinh vien" << endl;
    cout << "5.  Sua thong tin sinh vien (theo ma)" << endl;
    cout << "6.  Xoa thong tin sinh vien (theo ma)" << endl;
    cout << "7.  Muon sach" << endl;
    cout << "8.  Tra sach" << endl;
    cout << "9.  Liet ke toan bo sach trong thu vien" << endl;
    cout << "10. Liet ke sach sinh vien dang muon" << endl;
    cout << "11. Liet ke toan bo sach dang duoc muon" << endl;
    cout << "12. Thoat khoi he thong" << endl;
    cout << " " << endl;
}
void quanlythuvien::xuLyMenu() {
    int luaChon;
    
    while (true) {
        hienThiMenu();
        cout << "\nLua chon cua ban (1-12): ";
        cin >> luaChon;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (luaChon) {
            case 1: themSach(); break;
            case 2: suaSach(); break;
            case 3: xoaSach(); break;
            case 4: themSinhVien(); break;
            case 5: suaSinhVien(); break;
            case 6: xoaSinhVien(); break;
            case 7: muonSach(); break;
            case 8: traSach(); break;
            case 9: lietKeTatCaSach(); break;
            case 10: lietKeSachSVMuon(); break;
            case 11: lietKeTatCaSachDangMuon(); break;
            case 12:
                cout << "\nCam on ban da su dung he thong. Tam biet!" << endl;
                return;
            default:
                cout << "Lua chon khong hop le. Vui long chon tu 1-12." << endl;
        }
        
        cout << "\nNhan Enter de tiep tuc...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}