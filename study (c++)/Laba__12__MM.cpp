#include <iostream>
#include <conio.h>
#include <math.h>
#include<stddef.h>
using namespace std;


class drob
{
private:
	int ch, zm;

public:
	drob(int = 0, int = 0);

	drob operator+(const drob&);
	drob operator-(const drob&);
	drob operator*(const drob&);
	drob operator/(const drob&);
	drob operator%(const drob&);
	drob operator||(const drob&);

	void print();
};

drob::drob(int a, int b)
{
	ch = a;
	zm = b;
}

drob drob::operator+(const drob& obj2)
{
	drob sum;

	sum.ch = ch + obj2.ch;
	sum.zm = zm + obj2.zm;

	return sum;
}

drob drob::operator-(const drob& obj2)
{
	drob razn;

	razn.ch = ch - obj2.ch;
	razn.zm = zm - obj2.zm;

	return razn;
}

drob drob::operator*(const drob& obj2)
{
	drob proizv;

	proizv.ch = ch * obj2.ch;
	proizv.zm = zm * obj2.zm;

	return proizv;
}

drob drob ::operator/(const drob& obj2)
{
	drob drob;

	drob.ch = ch * obj2.zm;
	drob.zm = zm * obj2.ch;

	return drob;
}

drob drob::operator%(const drob& obj2)
{
	int ch1 = ch, zm1 = zm, nod;
	drob konc;

	while (ch1 != zm1)
	{
		if (ch1 > zm1)
			ch1 -= zm1;
		else
			zm1 -= ch1;
	}

	nod = ch1;
	konc.ch = ch / nod;
	konc.zm = zm / nod;

	return konc;
}

drob drob::operator||(const drob& obj2)
{
	int a = 0, b = 0;

	a = ch / zm;
	b = obj2.ch / obj2.zm;

	if (a > b)
	{
		cout << "(" << ch << "/" << zm << ")" << ">" << "(" << obj2.ch << "/" << obj2.zm << ")" << endl;
	}
	else
	{
		cout << "(" << ch << "/" << zm << ")" << "<" << "(" << obj2.ch << "/" << obj2.zm << ")" << endl;
	}

	return 0;
}

void drob::print()
{
	cout << "(" << ch << "/" << zm << ")" << endl;
}


int main()
{
	int a1, b1;
	int a2, b2;

	cout << "Vvedite 1-u drob\n";
	cin >> a1 >> b1;

	cout << "Vvedite 2-u drob\n";
	cin >> a2 >> b2;

	drob x(a1, b1), y(a2, b2), z;

	cout << "Drob 1:";
	x.print();

	cout << "Drob 2:";
	y.print();

	cout << "Sum:\n";
	z = x + y;
	z.print();

	cout << "Razn:\n";
	z = x - y;
	z.print();

	cout << "Proizv:\n";
	z = x * y;
	z.print();

	cout << "Delenie:\n";
	z = x / y;
	z.print();

	cout << "Okonch1:\n";
	z = x % y;
	z.print();

	cout << "Okonch2:\n";
	z = y % x;
	z.print();

	cout << "Sravnenie:\n";
	z = x || y;
	z.print();

	system("pause");
	return 0;
}