#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b)
	{
		while(a!=b)
			{
				if(a>b) a = a-b;
				else b = b-a;
			}
		return a;
	}

struct fraction
{
	int licznik, mianownik;

	bool is_correct()
	{
		return ((mianownik!=0 && abs(licznik)<(mianownik)))? (true):(false);
	}

	void shorten()
	{
		if(licznik!=0)
		{
			int dzielnik = gcd(abs(licznik),abs(mianownik));

				licznik = licznik / dzielnik;
				mianownik = mianownik / dzielnik;
		}

		if(licznik<0 && mianownik<0)
		{
			licznik = abs(licznik);
			mianownik = abs(mianownik);
		}
	}

};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);

	srand(time(NULL));

	fraction *fractions;
	fractions = new fraction[n];

	for(int i=0; i<n; i++)
	{
		do
			{
				fractions[i].licznik = rand()%19 -9;
				fractions[i].mianownik = rand()%19 -9;


			}while( !(fractions[i].is_correct() ));

			assert(fractions[i].is_correct());

	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].licznik, 
			fractions[i].mianownik);
	

	printf("Po skroceniu:\n");

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{

		fractions[i].shorten();

		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].licznik, 
			fractions[i].mianownik);
	}
	
	
}