#ifndef DOITUONG_H
#define DOITUONG_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Lớp cơ sở trừu tượng cho các đối tượng trong thư viện
class DoiTuong {
protected:
    string ma;
    string ten;

public:
    DoiTuong();
    DoiTuong(string m, string t);
    virtual ~DoiTuong();
    
    // Getter
    string getMa() const;
    string getTen() const;
    
    // Setter
    void setMa(string m);
    void setTen(string t);
    
    // Phương thức ảo thuần túy - bắt buộc override
    virtual void nhapThongTin() = 0;
    virtual void hienThi() const = 0;
    virtual void ghiFile(ofstream &out) const = 0;
    virtual void docFile(ifstream &in) = 0;
};

#endif
