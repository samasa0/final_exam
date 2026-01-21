#include "doiTuong.h"

DoiTuong::DoiTuong() {}

DoiTuong::DoiTuong(string m, string t) : ma(m), ten(t) {}

DoiTuong::~DoiTuong() {}

string DoiTuong::getMa() const { return ma; }
string DoiTuong::getTen() const { return ten; }

void DoiTuong::setMa(string m) { ma = m; }
void DoiTuong::setTen(string t) { ten = t; }

