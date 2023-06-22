#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class korabl
{
private:
	char* name;
	float vodaizm;
	int chislennost;
	char* tip;
public:
	korabl();
	korabl(char*, float, int, char*);
	korabl(const korabl&);
	void print();
	~korabl();
};

korabl::korabl()
{
	name = new char[10];
	tip = new char[10];

	strcpy(name, " ");
	strcpy(tip, " ");

	cout << "\nConstructor bes parametrov visvan for obj:" << this << endl;
}

korabl::korabl(char* Name, float Vodaizm, int Chislennost, char* Tip)
{
	name = new char[10];
	tip = new char[10];

	vodaizm = Vodaizm;
	chislennost = Chislennost;

	strcpy(name, Name);
	strcpy(tip, Tip);

	cout << "\nKonstructor s parametrs visvan for obj:" << this << endl;
}

korabl::korabl(const korabl& D)
{
	name = new char[10];
	tip = new char[10];

	vodaizm = D.vodaizm;
	chislennost = D.chislennost;

	strcpy(name, D.name);
	strcpy(tip, D.tip);

	cout << "\nKonstructor kopy for obj:" << this << endl;
}

void korabl::print()
{
	cout << "\nName: " << name;
	cout << "\nVodaizm: " << vodaizm << " tonne";
	cout << "\nChislennost: " << chislennost << " chelovek";
	cout << "\nTip: " << tip;
}

korabl::~korabl()
{
	delete[] name;
	delete[] tip;

	cout << "\n Destructor for obj:" << this << endl;
}


int main()
{
	char* name = new char[10];
	char* tip = new char[10];
	int chislennost, m[2];
	float vodaizm;

	cout << "\nVvedite imy, tip, chislennost, vodaizmesheniye ship:" << endl;
	cin >> name >> tip >> chislennost >> vodaizm;

	korabl A;
	korabl B;
	A.korabl::korabl(name, vodaizm, chislennost, tip);
	korabl* D = new korabl(A);

	A.print();
	cout << endl;
	D->print();
	cout << endl;
	B.print();
	cout << endl;
	D->~korabl();

	return 0;
}