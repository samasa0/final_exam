#include "SinhVien.h"
#include <fstream>
#include <cstring>

void themSinhVien() {
    SinhVien sv;
    cout << "Ma SV: "; cin >> sv.maSV;
    cin.ignore();
    cout << "Ten SV: "; cin.getline(sv.tenSV, 50);
    cout << "Lop: "; cin.getline(sv.lop, 20);
    sv.soSachDangMuon = 0;

    ofstream f("sinhvien.dat", ios::binary | ios::app);
    f.write((char*)&sv, sizeof(SinhVien));
    f.close();
}
