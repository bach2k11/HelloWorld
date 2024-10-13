#include <iostream>
using namespace std;
///   file cua dung 
//template <class T>
//class Array {
//protected:
//	T* data;
//	int length;
//public:
//	Array() : length(0), data(0) {
//		cout << "Ham tao mac dinh \n";
//	}
//	Array(int n) : length(n) {
//		data = new T[n];
//		cout << "Ham tao" << data << endl;
//	}
//	~Array() {
//		cout << "Ham huy" << data << endl;
//		if (data) delete[] data;
//	}
//public:
//	int Length()const { return length; }
//	T& ElementAt(int index) {
//		return data[index];
//	}
//
//	T& operator [](int index) {
//		return data[index];
//	}
//
//	Array& operator = (const Array& s) {
//		if (data) delete[] data;
//		data = new T[length = s.length];
//		for (int i = 0; i < length; i++)
//			data[i] = s.data[i];
//		return *this;
//	}
//public:
//	class Iter {
//		T* pointer;
//
//	public:
//		Iter(T* p) : pointer(p) {}
//		T& operator *() { return *pointer; }
//		friend bool operator != (const Iter& a, const Iter& b) {
//			return a.pointer != b.pointer;
//		}
//		Iter& operator ++() {
//			++pointer;
//			return *this;
//		}
//	};
//
//	friend Iter begin(const Array& s) {
//		return Iter(s.data);
//	}
//
//	friend Iter end(const Array& s) {
//		return Iter(s.data + s.length);
//	}
//};
//class Phanso {
//
//
//public:int tu, mau;
//	  Phanso(int a = 0, int b = 1) : tu(a), mau(b) {}
//	  friend ostream& operator<<(ostream& out, const Phanso& p) {
//		  Phanso a = p(); //   return out << p.tu << '/' << p.mau;
//		  if (a.tu == 0 || a.mau == 1) return out << a.tu;
//		  if (a.mau < 0) {
//			  a.mau = -a.mau;
//			  a.tu = -a.tu;
//		  }
//		  return out << a.tu << '/' << a.mau;
//
//	  }
//	  friend Phanso operator +(const Phanso& a, const Phanso& b) {
//		  return Phanso(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
//	  }
//	  friend Phanso operator -(const Phanso& a, const Phanso& b) {
//		  return a + Phanso(-b.tu, b.mau);
//	  }
//	  Phanso operator()() const {
//		  int u = tu, b = mau;
//		  while (b) {
//			  int r = u % b;
//			  u = b;
//			  b = r;
//		  }
//		  return Phanso(tu / u, mau / u);
//	  }
//
//
//};
//class HonSo : public Phanso() {
//public:
//	HonSo(const Phanso & p) : Phanso(p) {}
//	HonSo(int n = 0; int a = 0; int b = 1) : Phanso(n * b + a, b) {}
//	friend ostream& operator <<(ostream & out, const HonSo & h) {
//		int a = h.tu, b = h.mau, n = a / b;
//		if (n == 0) return out << Phanso(a, b);
//		a %= b;
//		return out << n << '(' << Phanso(a, b) << ')';
//	}
//};
//class Polynorm :public Array<double> {
//public:
//	Polynorm(int n, const  double* a) :Array(n + 1) {
//		if (a) {
//			for (int i = 0; i < length(); i++)
//				(*this)[i] = a[i];
//		}
//	}
//	double operator()(double x) {
//		int n = length() - 1;
//		double f = (*this)[n];
//		while (n) { f = f * x + (*this)[--n]; }
//		return f;
//	}
//};
//
//
//int main() {
//	double a[] = { 3,-4,1 };
//	Polynorm y(2, a);
//	cout << y(1) << endl << y(3) << endl;
//
//}
class PhanSo {
protected:
	int tu, mau;
public:
	PhanSo(int a = 0, int b = 1) : tu(a), mau(b) {}
	friend ostream& operator<<(ostream& out, const PhanSo& p) {
		PhanSo a = p(); //   return out << p.tu << '/' << p.mau;
		if (a.tu == 0 || a.mau == 1) return out << a.tu;
		if (a.mau < 0) {
			a.mau = -a.mau;
			a.tu = -a.tu;
		}
		return out << a.tu << '/' << a.mau;

	}
	friend PhanSo operator +(const PhanSo& a, const PhanSo& b) {
		return PhanSo(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
	}
	friend PhanSo operator -(const PhanSo& a, const PhanSo& b) {
		return a + PhanSo(-b.tu, b.mau);
	}
	PhanSo operator()() const {
		int u = tu, b = mau;
		while (b) {
			int r = u % b;
			u = b;
			b = r;
		}
		return PhanSo(tu / u, mau / u);
	}


};
class HonSo : public PhanSo() {
public:
	HonSo(int n = 0; int a = 0; int b = 1) : PhanSo(n * b + a, b) {}
	friend ostream& operator<<(ostream & out, const HonSo & h) {
		int a = h.tu, b = h.mau, n = a / b;
		if (n == 0) return out << PhanSo(a, b);
		a %= b;
		return out << n << '(' << PhanSo(a, b) << ')';
	}
}
class Polynorm :public Array<double> {
public:
	Polynorm(int n, const  double* a) :Array(n + 1) {
		if (a) {
			for (int i = 0; i < length(); i++)
				(*this)[i] = a[i];
		}
	}
	double operator()(double x) {
		int n = length() - 1;
		double f = (*this)[n];
		while (n) { f = f * x + (*this)[--n]; }
		return f;
	}
};


int main() {
	double a[] = { 3,-4,1 };
	Polynorm y(2, a);
	cout << y(1) << endl << y(3) << endl;

}