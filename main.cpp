#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd (int a, int b)
{
	int min=std::min(abs(a),abs(b));
	int gcd;
	for (int i=1; i<=min; i++)
	{
		if (a%i==0 && b%i==0)
		{
			gcd=i;
		}
	}
	return gcd;
}

struct Fraction
{
	int licznik, mianownik;
	bool is_correct()
	{
		return mianownik!=0 && licznik<mianownik;
	}
	void shorten()
	{
		int a=gcd(licznik, mianownik);

		licznik=licznik/a;
		mianownik=mianownik/a;
	}

};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);

	cout << n << endl;

	Fraction *fractions = new Fraction[n];
	for (int i=0; i<n; i++)
	{

		do
		{
			fractions[i].licznik=rand()%19-9;
			fractions[i].mianownik=rand()%19-9;
		}
		while (!fractions[i].is_correct());

		assert(fractions[i].is_correct());

		cout << i+1 << ": " << fractions[i].licznik << "/" <<fractions[i].mianownik<< endl;
		fractions[i].shorten();
		cout << i+1 << ": " << fractions[i].licznik << "/" <<fractions[i].mianownik<< endl;
		
	}
}