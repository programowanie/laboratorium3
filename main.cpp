#include <stdio.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b);
{
	do
	{
		if(a > b) a = a-b;
		else b = b-a;
	}while(a!=b)
	return a;
}

struct fraction
{
	int licznik;
	int mianownik;

	bool iscorrect()
	{
		return ( mianownik && abs(licznik) < abs(mianownik))) ? true : false;
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
	fraction *fractions;
	srand=(time(NULL));
	int n = atoi(argv[1]);
	fraction *fraction = new fraction[n];

	for(int i = 0; i < n; i++)
	{
		do
		{
			fraction.[i].licznik = rand() % 19 - 9;
			fraction.[i].mianownik = rand() % 19 - 9;

		}while ((fraction.[i].iscorrect == false))
		fraction.[i].shorten();
	}

	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}