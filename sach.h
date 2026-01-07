#ifndef SACH_H
#define SACH_H
#include<iostream>
#include<fstream>
#include <string>
#include "tailieu.h"
using namespace std;
class Sach: public TaiLieu
{
    private:
    string tacGia;
    string theLoai;
    public:
    Sach();
    Sach(string ma,string ten,string tg,int nam,string tl);
    virtual ~Sach();
    // getter
    
    string getTacGia()const;
    string getTheLoai()const;
   
    //setter
    
     void setTacGia(string tg);
     void setTheLoai(string tl);

        void nhapThongTin()override;
        void hienThi()const override;
        void ghiFile(ofstream& out)const override;
        void docFile(ifstream& in)override;
};

#endif
