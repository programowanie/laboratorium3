#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <math.h>

int gcd(int a, int b)
{
	do
	{
		if(a > b) a = a-b;
		else b = b-a;
	}while(a!=b);
	return a;
}

struct fraction
{
	int licznik;
	int mianownik;

	bool iscorrect()
	{
		return ( mianownik != 0 && abs(licznik) < abs(mianownik)) ? true : false;
	}
void shorten()
{
	int dzielnik;
	dzielnik = gcd(licznik, mianownik);
	licznik = licznik / dzielnik;
	mianownik = mianownik / dzielnik;
}
};

int main(int argc, char **argv)
{	
	
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];

	for(int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].licznik = (rand() % 19) - 9;
			fractions[i].mianownik = (rand() % 19) - 9;

		}while((fractions[i].iscorrect() == false));
		fractions[i].shorten();
	}

	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}