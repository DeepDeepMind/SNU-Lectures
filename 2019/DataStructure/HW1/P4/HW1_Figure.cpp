#include "HW1_Figure.h"

Figure::Figure() { area = 0; }
ostream& operator<< (ostream& os, Figure &f) {
	return f.print(os);
}

Rectangle::Rectangle() : Figure() {
	width = 0;
	height = 0;
	point = NULL;
}
Rectangle::Rectangle(int x1, int y1, int x2, int y2) {
	width = x2 - x1;
	height = y2 - y1;
	area = width * height;
	point = new int[4];
	point[0] = x1;
	point[1] = y1;
	point[2] = x2;
	point[3] = y2;
}
Rectangle::~Rectangle() {
	delete[] point;
	width = 0;
	height = 0;
}
void Rectangle::shift(int _x, int _y) {
	point[0] += _x;
	point[2] += _x;

	point[1] += _y;
	point[3] += _y;
}
ostream& Rectangle::print(ostream& os) const {
	os << "Figure: rectangle" << endl
		<< "Width: " << width << ", " << "Height: " << height << " -> Area: " << area << endl
		<< "The coordinate of diagonal line: (" << point[0] << ", " << point[1] << "), ("
		<< point[2] << ", " << point[3] << ")" << endl;
	return os;
}

Circle::Circle() : Figure() {
	radius = 0;
	center = NULL;
}
Circle::Circle(int cx, int cy, int r) {
	center = new int[2];
	center[0] = cx;
	center[1] = cy;
	radius = r;
	area = r * r * 3.14;
}
Circle::~Circle() {
	delete center;
	radius = 0;
}
void Circle::shift(int _x, int _y) {
	center[0] += _x;
	center[1] += _y;
}
ostream& Circle::print(ostream& os) const {
	os << "Figure: circle" << endl
		<< "Radius: " << radius << " -> Area: " << area << endl
		<< "The coordinate of center: (" << center[0] << ", " << center[1] << ")" << endl;
	return os;
}