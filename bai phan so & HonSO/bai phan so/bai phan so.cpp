

#include <iostream>
using namespace std;
class PhanSo
{
protected:
    int tu, mau;
public:
    PhanSo(int a = 0, int b = 1) :tu(a), mau(b) {}
//public:
//    PhanSo& Minimize();
public:
    friend ostream& operator << (ostream& out, const PhanSo& p) {
        PhanSo a = p();
        if (a.tu == 0 || a.mau == 1) return out << a.tu;
        if (a.mau < 0) {
            a.mau = -a.mau;
            a.tu = -a.tu;
        }
        return out << p.tu << "/" << p.mau;
    }
    friend PhanSo operator + (const PhanSo& a, const PhanSo& b) {
        return PhanSo(a.tu * b.mau + a.mau * b.tu, a.mau * b.tu);
    }
    friend PhanSo operator - (const PhanSo& a, const PhanSo& b) {
        return a + PhanSo(-b.tu, b.mau);
    }
    PhanSo operator()() const {
        int u = tu, b = mau;
        while (b) {
            int r = u % b;
            u = b; b = r;
        }
        return PhanSo(tu / u, mau / u);
    }
};
class Honso : public PhanSo {
public: Honso(int n= 0, int a = 0, int b=1) : PhanSo(n*b+a,b){}
      Honso(const PhanSo& p) : PhanSo(p) {}

      friend ostream& operator <<(ostream& out, const Honso& h) {
          int a = h.tu, b = h.mau; int n = a / b;
          if (n == 0) return out << PhanSo(h.tu, h.mau);
          a %= b;
          return out << n << '(' << PhanSo(a, b) << ')';

      }
};
int main()
{
    PhanSo a(5, 4);
    Honso b(a);
    cout << b;
	//cout << a() << " + 1 = " << (a + 1)() << endl;
	return 0;
}



