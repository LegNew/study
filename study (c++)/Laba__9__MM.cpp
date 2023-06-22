#include <iostream>
using namespace std;

int chisl1, znam1, chisl2, znam2, z1 = 0, z2 = 0;
float cis1, cis2, result = 0;

int umnosh10(int chisl1, int znam1, int chisl2, int znam2)
{
    z1 = chisl1 * chisl2;
    z2 = znam1 * znam2;

    return z1, z2;
}

float umnosh10(float cis1, float cis2)
{
    result = cis1 * cis2;

    return result;
}


int main()
{
    umnosh10(4399, 1680, 4368, 252);
    umnosh10(12.5, 64.5);

    cout << z1 << "/" << z2 << endl;
    cout << result << endl;

    return 0;
}
