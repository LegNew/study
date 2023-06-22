#include <stdio.h>
#include <iostream>
#include<string>
using namespace std;

class transport
{
protected:
	string type,name,speed,power,weight,chislen,vmestimost;

public:
	static transport* begin;
	transport* next;

	static void add(transport* d)
	{
		d->next = begin;
		begin = d;
	}

	transport()
	{
		add(this);
	}

	virtual void show()
	{
		cout << "\nName: " << name;
		cout << "\nType: " << type;
		cout << "\n----------------------------";
	}

	virtual void set_parameters()
	{
		string a, b;

		cout << "Name:";
		getline(cin, a);

		cout << "Type: ";
		getline(cin, b);

		name = a;
		type = b;
	}

	static void print()
	{
		transport* l = begin;

		while (l)
		{
			l->show();
			l = l->next;
		}
	}
};

transport* transport::begin;
class AUTO :public transport
{
public:
	void show()
	{
		cout << "\nname:" << name;
		cout << "\nspeed:" << speed << " km/h";
		cout << "\npower:" << power << " L";
		cout << "\nweight:" << weight << " kg";
		cout << "\n----------------------------";
	}

	void set_parameters()
	{
		string n, s, p, w;

		cout << "\nName: ";
		getline(cin, n);
		name = n;

		cout << "\nSpeed: ";
		getline(cin, s);
		cout << "km/h";
		speed = s;

		cout << "\nPower: ";
		getline(cin, p);
		cout << "L";
		power = p;

		cout << "\nWeight: ";
		getline(cin, w);
		cout << "kg";
		weight = w;
	}
};

class poezd :public transport
{
public:
	void show()
	{
		cout << "\nname:" << name;
		cout << "\nspeed:" << speed << " km/h";
		cout << "\nvmestimost:" << vmestimost << " ton";
		cout << "\nweight:" << weight << " ton";
		cout << "\n----------------------------";
	}
	void set_parameters()
	{
		string n, s, v, w;
		cout << "\nName: ";
		getline(cin, n);
		name = n;

		cout << "\nSpeed: ";
		getline(cin, s);
		cout << "km/h";
		speed = s;

		cout << "\nVmestimost: ";
		getline(cin, v);
		cout << "ton";
		vmestimost = v;

		cout << "\nWeight: ";
		getline(cin, w);
		cout << "ton";
		weight = w;
	}
};

class express :public transport
{
public:
	void show()
	{
		cout << "\nname:" << name;
		cout << "\nspeed:" << speed << " km/h";
		cout << "\nvmestimost:" << vmestimost << " chelovek";
		cout << "\nweight:" << weight << " ton";
		cout << "\n----------------------------";
	}
	void set_parameters()
	{
		string n, s, v, w;

		cout << "\nName: ";
		getline(cin, n);
		name = n;

		cout << "\nSpeed: ";
		getline(cin, s);
		cout << "km/h";
		speed = s;

		cout << "\nVmestimost: ";
		getline(cin, v);
		cout << "chelovek";
		power = v;

		cout << "\nWeight: ";
		getline(cin, w);
		cout << "ton";
		weight = w;
	}
};


int main()
{
	system("chcp 1251 >> null");
	system("TITLE LABORATORY WORK 13");

	cout << "auto,poezd and express is transport\n";

	transport::begin = 0;
	transport trans1;
	AUTO auto1;
	poezd poez1;
	express ex1;

	cout << "\nDobavim transport=-\n";
	trans1.set_parameters();

	cout << "\nDobavim auto=-\n";
	auto1.set_parameters();

	cout << "\nDobavim poezd=-\n";
	poez1.set_parameters();

	cout << "\nDobavim express=-\n";
	ex1.set_parameters();

	cout << "============================\n";
	cout << "vse transorti:\n";
	cout << "============================\n";
	
	trans1.print();
	cout << "\n";
	system("pause");

	return 0;
}