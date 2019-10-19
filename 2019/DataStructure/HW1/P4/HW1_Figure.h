#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using namespace std;

class Figure {
protected:
	float area;

public:
	// TODO: Declare and define member functions following the instruction
	// You can add other member functions if you need
	Figure();
	virtual ~Figure() { }

	friend ostream& operator<< (ostream& os, Figure &f);
	virtual void shift(int _x, int _y) = 0;
	virtual ostream& print(ostream& os) const = 0;
};

class Rectangle : public Figure {
private:
	int width;
	int height;
	int* point;

public:
	// TODO: Define member functions declared as below
	// You can add other member functions if you need
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	~Rectangle();
	void shift(int _x, int _y);

	ostream& print(ostream& os) const;
};

class Circle : public Figure {
private:
	int radius;
	int* center;

public:
	// TODO: Define member functions declared as below
	// You can add other member functions if you need
	Circle();
	Circle(int cx, int cy, int r);
	~Circle();
	void shift(int _x, int _y);
	ostream& print(ostream& os) const;
};


#endif