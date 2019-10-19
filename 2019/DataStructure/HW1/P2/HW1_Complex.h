#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class Complex {
private:
	T re;
	T im;

public:
	Complex() {
		re = 0;
		im = 0;
	}
	Complex(T a, T b) {
		re = a;
		im = b;
	}

	T getRe() const {
		return re;
	}
	T getIm() const {
		return im;
	}
	void setRe(T a) {
		re = a;
	}
	void setIm(T b) {
		im = b;
	}

	Complex<T> operator+ (const Complex<T>& z) {
		return Complex<T>(re + z.getRe(), im + z.getIm());
	}
	Complex<T> operator- (const Complex<T>& z) {
		return Complex<T>(re - z.getRe(), im - z.getIm());
	}
	Complex<T> operator* (const Complex<T>& z) {
		return Complex<T>(re * z.getRe() - im * z.getIm(), im * z.getRe() + re * z.getIm());
	}
	Complex<T> operator~ () const {
		return Complex<T>(re, im * -1);
	}

	friend ostream& operator<< (ostream& os, const Complex<T>& z) {
		if (z.getIm() < 0) {
			os << "(" << z.getRe() << " - " << -1 * z.getIm() << "i)" << endl;
			return os;
		}
		os << "(" << z.getRe() << " + " << z.getIm() << "i)" << endl;
		return os;
	}
};

void solveQuadratic(Complex<double>& x1, Complex<double>& x2, int a, int b, int c) {
	double D = b * b - 4 * a * c;
	if (D > 0) {
		x1.setRe((-1 * b + sqrt(D)) / (2 * a));
		x2.setRe((-1 * b - sqrt(D)) / (2 * a));
	}
	else if (D == 0) {
		x1.setRe(-1 * b / (2 * a));
		x2.setRe(-1 * b / (2 * a));
	}
	else {
		x1.setRe(-1 * b / (2 * a));
		x1.setIm(sqrt(-1 * D) / (2 * a));
		x2.setRe(-1 * b / (2 * a));
		x2.setIm(-1 * sqrt(-1 * D) / (2 * a));
	}
}
#endif