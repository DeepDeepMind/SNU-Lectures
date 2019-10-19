#include "HW1_NaryBigNum.h"

NaryBigNum::NaryBigNum() {
	number = nullptr;
	size = 0;
	base = 10;
}
NaryBigNum::NaryBigNum(int n, string num) {
	if (n >= 2 && n <= 36) base = n;
	else base = 10;
	size = num.size();
	number = new char[size];
	for (int i = 0; i < size; i++)
	{
		//insert small digit number first
		number[i] = cutter(num.at(size - i - 1));
	}
	exactSize();
}
NaryBigNum::NaryBigNum(const NaryBigNum& nbn) {
	size = nbn.size;
	base = nbn.base;
	number = new char[size];
	for (int i = 0; i < size; i++)
	{
		number[i] = nbn.number[i];
	}
}
NaryBigNum::~NaryBigNum() {
	delete[] number;
}


char NaryBigNum::cutter(char c) {
	//convert lowercase letters to uppercase one
	//convert non-alphabetic, non-numeric characters to '0'
	//convert characters out of range to '0'
	if (c >= 'a' && c <= 'z') c = c - 32;
	if (base <= 10) {
		if (c >= '0' && c <= intToChar(base-1)) return c;
		else return '0';
	}
	else {
		if (c >= '0' && c <= '9') return c;
		else if (c >= 'A' && c <= intToChar(base-1)) return c;
		else return '0';
	}
}

NaryBigNum& NaryBigNum::operator=(const NaryBigNum& nbn) {
	base = nbn.base;
	size = nbn.size;

	delete[] number;
	number = new char[size];
	for (int i = 0; i < size; i++)
	{
		number[i] = nbn.number[i];
	}
	return *this;
}
NaryBigNum NaryBigNum::operator+(const NaryBigNum& nbn) {
	NaryBigNum const& mnbn = maxNbn(*this, nbn);
	NaryBigNum const& nnbn = minNbn(nbn, *this);
	int m = mnbn.size;
	int n = nnbn.size;

	NaryBigNum ans;
	ans.size = m + 1;
	ans.base = base;

	char * result = new char[ans.size];
		int quot = 0;
	for (int i = 0; i < m; i++)
	{
		if (i < n) {
			int sum = charToInt(mnbn.number[i]) + charToInt(nnbn.number[i]) + quot;
			result[i] = intToChar(remByBase(sum));
			quot = quotByBase(sum);
		}
		else {
			int sum = charToInt(mnbn.number[i]) + quot;
			result[i] = intToChar(remByBase(sum));
			quot = quotByBase(sum);
		}
	}
	result[ans.size - 1] = intToChar(quot);

	ans.number = result;
	ans.exactSize();
	return ans;
}
NaryBigNum NaryBigNum::operator*(const NaryBigNum& nbn) {
	NaryBigNum const& mnbn = maxNbn(*this, nbn);
	NaryBigNum const& nnbn = minNbn(nbn, *this);
	int m = mnbn.size;
	int n = nnbn.size;

	NaryBigNum ans;
	ans.size = m + n;
	ans.base = base;

	char * result = new char[ans.size];
	for (int i = 0; i < n; i++)
	{
		int quot = 0;
		for (int j = 0; j < m; j++)
		{
			int sum = charToInt(result[i + j]) + charToInt(mnbn.number[j]) * charToInt(nnbn.number[i]) + quot;
			result[i + j] = intToChar(remByBase(sum));
			quot = quotByBase(sum);
		}
		int sum = charToInt(result[i + m]) + quot;
		result[i + m] = intToChar(sum);
	}

	ans.number = result;
	ans.exactSize();
	return ans;
}

ostream& operator<< (ostream& os, const NaryBigNum& nbn) {
	for (int i = 0; i < nbn.size; i++)
	{
		os << nbn.number[nbn.size - i - 1];
	}
	os << " (" << nbn.base << ")";
	return os;
}

//int NaryBigNum::max(int n1, int n2) { return (n1 > n2) ? n1 : n2; }
//int NaryBigNum::min(int n1, int n2) { return (n1 < n2) ? n1 : n2; }
int NaryBigNum::quotByBase(int n) { return n / base; }
int NaryBigNum::remByBase(int n) { return n % base; }

void NaryBigNum::exactSize() {
	while (number[size - 1] == '0') {
		size--;
	}
}

NaryBigNum const& NaryBigNum::maxNbn(const NaryBigNum& nbn1, const NaryBigNum& nbn2) {
	return (nbn1.size > nbn2.size) ? nbn1 : nbn2;
}
NaryBigNum const& NaryBigNum::minNbn(const NaryBigNum& nbn1, const NaryBigNum& nbn2) {
	return (nbn1.size < nbn2.size) ? nbn1 : nbn2;
}


char NaryBigNum::intToChar(int n) {
	switch (n) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	case 16:
		return 'G';
	case 17:
		return 'H';
	case 18:
		return 'I';
	case 19:
		return 'J';
	case 20:
		return 'K';
	case 21:
		return 'L';
	case 22:
		return 'M';
	case 23:
		return 'N';
	case 24:
		return 'O';
	case 25:
		return 'P';
	case 26:
		return 'Q';
	case 27:
		return 'R';
	case 28:
		return 'S';
	case 29:
		return 'T';
	case 30:
		return 'U';
	case 31:
		return 'V';
	case 32:
		return 'W';
	case 33:
		return 'X';
	case 34:
		return 'Y';
	case 35:
		return 'Z';
	default:
		return '0';
	}
}
int NaryBigNum::charToInt(char c) {
	switch (c) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	case 'G':
		return 16;
	case 'H':
		return 17;
	case 'I':
		return 18;
	case 'J':
		return 19;
	case 'K':
		return 20;
	case 'L':
		return 21;
	case 'M':
		return 22;
	case 'N':
		return 23;
	case 'O':
		return 24;
	case 'P':
		return 25;
	case 'Q':
		return 26;
	case 'R':
		return 27;
	case 'S':
		return 28;
	case 'T':
		return 29;
	case 'U':
		return 30;
	case 'V':
		return 31;
	case 'W':
		return 32;
	case 'X':
		return 33;
	case 'Y':
		return 34;
	case 'Z':
		return 35;
	default:
		return 0;
	}
}