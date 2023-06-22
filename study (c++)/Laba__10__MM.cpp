#include <iostream>
using namespace std;

int find(int n, ...)
{
	int* ptr = &n;
	int chislo = *ptr;
	int x, i = 0;

	cin >> x;

	while (i < x)
	{
		chislo = *(++ptr);
		i++;
	}

	return chislo;
}


int main()
{
	printf("%d \n", find(5, 1, 2, 3, 4, 5));
	printf("%d \n", find(10, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
	printf("%d \n", find(12, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27));
	return 0;
}