#ifndef NARYBIGNUM_H
#define NARYBIGNUM_H

#include <iostream>
#include <string>

using namespace std;

class NaryBigNum {
private:
	char *number;
	int size;
	int base;
public:
	NaryBigNum();
	NaryBigNum(int, string);
	NaryBigNum(const NaryBigNum&);
	~NaryBigNum();
	char cutter(char);
	NaryBigNum operator+(const NaryBigNum&);
	NaryBigNum& operator=(const NaryBigNum&);
	NaryBigNum operator*(const NaryBigNum&);
	friend ostream& operator<< (ostream&, const NaryBigNum&);
	int charToInt(char);
	char intToChar(int);
	//int max(int, int);
	//int min(int, int);
	int quotByBase(int);
	int remByBase(int);
	void exactSize();
	NaryBigNum const& maxNbn(const NaryBigNum&, const NaryBigNum&);
	NaryBigNum const& minNbn(const NaryBigNum&, const NaryBigNum&);
};
#endif NARYBIGNUM_H