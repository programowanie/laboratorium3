#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
	//Algorytm NWD
    int temp;

	while(b!=0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}

	return a;
 }

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct()
	{
		return (denominator != 0 && abs(nominator) < abs(denominator))? true : false;
	}

	void shorten()
	{
		int GCD = gcd(nominator, denominator);
		nominator = nominator/GCD;
		denominator = denominator/GCD;
	}
};


int main(int argc, char **argv)
{
	srand(time(NULL));

	int n = atoi(argv[1]);

	//Tworzenie tablicy
	fraction *fractions = new fraction[n];

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		//Losuje dopóki ułamek nie będzie prawidłowy
		do
		{
			fractions[i].nominator = (rand() % 19) - 9;
			fractions[i].denominator = (rand() % 19) - 9;
			fractions[i].shorten();
		}
		while (fractions[i].is_correct() != true);

		//Wypisuje 0 zamiast ułamka z licznikiem równym 0
		if (fractions[i].nominator != 0)
		{
			printf("[%i] %2i / %2i\n",i, fractions[i].nominator, fractions[i].denominator);
		}
		else printf("[%i]  0\n",i);
	}
}