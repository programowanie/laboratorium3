#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b)
{	//algorytm Euklidesa
	a = abs(a);
	b = abs(b);
	if (a==0 || a==b) return b;
	if (b==0) return a;
	do{
		if (a>b) a = a-b;
		else b = b-a;
	}while(a!=b);
	return a;
}

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		bool wartosc = true;
		(nominator > denominator)?(wartosc = false):((denominator == 0)?(wartosc = false):(wartosc = true));
		return wartosc;
	}
	void shorten()
	{
		int dzielnik = 0;
		do
		{
			dzielnik = gcd(nominator, denominator);
			nominator = nominator / dzielnik;
			denominator = denominator / dzielnik;
		}while(dzielnik != 1);	
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions;

	for (int i = 0; i < n; i++)
		fractions = new fraction;

	for (int i = 0; i < n; i++)
	{
		do{
			fractions[i].nominator = rand()%19-9;
			fractions[i].denominator = rand()%19-9;
		}while(!(fractions[i].is_correct()));
		fractions[i].shorten();
	}


	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

}