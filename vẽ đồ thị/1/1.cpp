#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Array {
protected:
    T* data;
    int length;
public:
    Array() : length(0), data(0) {
        cout << "Ham tao mac dinh \n";
    }
    Array(int n) : length(n) {
        data = new T[n];
        cout << "Ham tao" << data << endl;
    }
    ~Array() {
        cout << "Ham huy" << data << endl;
        if (data) delete[] data;
    }
public:
    int Length()const { return length; }

    T& ElementAt(int index) {
        return data[index];
    }

    T& operator [](int index) {
        return data[index];
    }

    Array& operator = (const Array& s) {
        if (data) delete[] data;
        data = new T[length = s.length];
        for (int i = 0; i < length; i++)
            data[i] = s.data[i];
        return *this;
    }
public:
    class Iter {
        T* pointer;

    public:
        Iter(T* p) : pointer(p) {}
        T& operator *() { return *pointer; }
        friend bool operator != (const Iter& a, const Iter& b) {
            return a.pointer != b.pointer;
        }
        Iter& operator ++() {
            ++pointer;
            return *this;
        }
    };

    friend Iter begin(const Array& s) {
        return Iter(s.data);
    }

    friend Iter end(const Array& s) {
        return Iter(s.data + s.length);
    }
};

class Polynorm : public Array<double> {
public:
    Polynorm(int n, const double* a) : Array(n + 1) {
        if (a) {
            for (int i = 0; i < length; i++) {
                (*this)[i] = a[i];
            }
        }
    }
    double operator()(double x) {
        int n = length - 1;
        double f = (*this)[n];
        while (n) f = f * x + (*this)[--n];
        return f;
    }
};

int main() {
    
    double a[] = { 1, 2, 1 };
    Polynorm y(2, a);

    const char* fn = "test.csv";
    ofstream ofs;

    cout << "writng to " << fn << " ... ";

    ofs.open(fn);

    ofs << "x,y\n";
    double x = -3;
    double d = 0.1;
    while (x < 1.001) {
        ofs << x << ',' << y(x) << endl;
        x += d;
    }

    ofs.close();
    cout << "done\n";
    while (1) {}
}