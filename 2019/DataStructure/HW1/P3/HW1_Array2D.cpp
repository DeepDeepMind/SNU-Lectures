#include "HW1_Array2D.h"

using namespace std;

Array2D::Array2D(int size) {
	m_size = size;
	m_array = new int*[size];
	for (int i = 0; i < size; i++)
	{
		m_array[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			m_array[i][j] = size * i + j + 1;
		}
	}
}
Array2D::~Array2D() {
	for (int i = 0; i < m_size; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
}

void Array2D::MoveRight(int r, int dist) {
	while (dist > 0) {
		for (int i = 1; i < m_size; i++)
		{
			swap(m_array[r][m_size - i], m_array[r][m_size - i - 1]);
		}
		dist--;
	}
}
void Array2D::MoveLeft(int r, int dist) {
	while (dist > 0) {
		for (int i = 1; i < m_size; i++)
		{
			swap(m_array[r][i - 1], m_array[r][i]);
		}
		dist--;
	}
}
void Array2D::MoveUp(int c, int dist) {
	while (dist > 0) {
		for (int i = 1; i < m_size; i++)
		{
			swap(m_array[i - 1][c], m_array[i][c]);
		}
		dist--;
	}
}
void Array2D::MoveDown(int c, int dist) {
	while (dist > 0) {
		for (int i = 1; i < m_size; i++)
		{
			swap(m_array[m_size - i][c], m_array[m_size - i - 1][c]);
		}
		dist--;
	}
}
void Array2D::MoveUpRight(int d, int dist) {
	while (dist > 0) {
		if (d < m_size) {
			for (int j = d; j > 0; j--)
			{
				swap(m_array[d - j][j], m_array[d - j  + 1][j - 1]);
			}
		}
		else {
			for (int i = d - m_size + 2; i < m_size; i++)
			{
				swap(m_array[i][d - i], m_array[i - 1][d - i + 1]);
			}
		}
		dist--;
	}
}
void Array2D::MoveDownLeft(int d, int dist) {
	while (dist > 0) {
		if (d < m_size) {
			for (int i = d; i > 0; i--)
			{
				swap(m_array[i][d - i], m_array[i - 1][d - i + 1]);
			}
		}
		else {
			for (int j = d - m_size + 2; j < m_size; j++)
			{
				swap(m_array[d - j][j], m_array[d - j + 1][j - 1]);
			}
		}
		dist--;
	}
}
void Array2D::MoveUpLeft(int d, int dist) {
	while (dist > 0) {
		if (d < m_size) {
			int j = 1;
			for (int i = m_size - d; i < m_size; i++)
			{
				swap(m_array[i][j], m_array[i - 1][j - 1]);
				j++;
			}
		}
		else {
			int i = 1;
			for (int j = d - m_size; j < m_size; j++)
			{
				swap(m_array[i][j], m_array[i - 1][j - 1]);
				i++;
			}
		}
		dist--;
	}
}
void Array2D::MoveDownRight(int d, int dist) {
	while (dist > 0) {
		if (d < m_size) {
			int i = m_size - 1;
			for (int j = d; j > 0; j--)
			{
				swap(m_array[i][j], m_array[i - 1][j - 1]);
				i--;
			}
		}
		else {
			int j = m_size - 1;
			for (int i = m_size - d + 3; i > 0; i--)
			{
				swap(m_array[i][j], m_array[i - 1][j - 1]);
				j--;
			}
		}
		dist--;
	}
}

void Array2D::Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


ostream& operator<< (ostream& os, const Array2D& arr) {
	for (int i = 0; i < arr.m_size; ++i) {
		for (int j = 0; j < arr.m_size; ++j) {
			os << arr.m_array[i][j] << "  ";
		}
		os << endl;
	}
	return os;
}