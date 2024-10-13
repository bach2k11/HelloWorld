// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../OOP/Screen.h"
#include "../OOP/Array.h"

using namespace std;

class Coord {
public:
	double x, y;

public:
	Coord(double x = 0, double y = 0) : x(x), y(y) { }
	friend ostream& operator<<(ostream& out, const Coord& p) {
		return out << p.x << ',' << p.y;
	}
};

class Polynorm : public Array<double> {
public:
	Polynorm(int degree, const double* coef = 0) : Array(degree + 1, coef) {
	}

public:
	int Degree() const { return Length() - 1; }
	double operator()(double x) const;
	Array<Coord> operator()(double a, double b, double dx);
};

double Polynorm::operator()(double x) const {
	int n = this->Degree();
	double f = this->GetAt(n);

	while (n) {
		f = f * x + GetAt(--n);
	}
	return f;
}

Array<Coord> Polynorm::operator()(double a, double b, double dx) {
	int n = (int)(b - a) / dx;
	Array<Coord> result(n + 1);

	double x = a;
	for (Coord& p : result) {
		p.x = x;
		p.y = operator()(x);

		x += dx;
	}
	return result;
}

#include <fstream>
int main() {

	double a[] = { 3, -4, 1 };
	Polynorm y(2, a);

	ofstream ofs;
	const char* fn = "test.csv";

	cout << "Writing to " << fn << " ... ";

	ofs.open(fn);
	ofs << "x, y" << endl;

	for (Coord& p : y(-1, 5, 0.1)) {
		ofs << p << endl;
	}

	ofs.close();
	cout << "done\n";

	while (true)
	{
	}
}
