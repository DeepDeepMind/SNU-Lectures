#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <iomanip>

using namespace std;

class Array2D {
public:
	Array2D(int);
	~Array2D();

	friend ostream& operator<< (ostream&, const Array2D&);
	void MoveRight(int r, int dist);
	void MoveLeft(int r, int dist);
	void MoveUp(int c, int dist);
	void MoveDown(int c, int dist);
	void MoveUpRight(int d, int dist);
	void MoveDownLeft(int d, int dist);
	void MoveUpLeft(int d, int dist);
	void MoveDownRight(int d, int dist);
	void Swap(int*, int*);
private:
	int** m_array;
	int m_size;
};



#endif