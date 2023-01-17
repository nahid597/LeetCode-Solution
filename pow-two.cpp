#include <iostream>
#include<cmath>

using namespace std;

double findMod(double a, double b)
{
	double mod;
	// Handling negative values
	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;

	// Finding mod by repeated subtraction
	
	while (mod >= b)
		mod = mod - b;

	// Sign of result typically depends
	// on sign of a.
	if (a < 0)
		return -mod;

	return mod;
}

bool isPowerOfTwo(int n) {
       return (n > 0 && (n & (n-1)) == 0);
}

int main()
{

    int n;

    cout << "enter your number" << endl;
    cin >> n;

    bool s = isPowerOfTwo(n);

    cout << s << endl;

    return 0;
}