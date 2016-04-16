#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd(int n, int d);


struct fraction
{
	int numerator;
	int denominator;
	bool is_correct()
	{
		 return denominator != 0 ? (abs(numerator) < abs(denominator) ? true : false) : false;

	}
	void shorten()
	{
		int divider = gcd(denominator, numerator); 
		divider != 1 ? (numerator /= divider  , denominator /= divider) : divider;
		denominator < 0 ? (numerator= -numerator , denominator=abs(denominator)) : denominator;
	}
};

int gcd (int numerator, int denominator)
{
	int pom;
	while(denominator!=0)
	{
		pom = numerator % denominator;
		numerator = denominator;
		denominator = pom;
	}
	return numerator;
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
		  fractions[i].numerator=rand()% 19 + (-9);
		  fractions[i].denominator=rand()% 19 + (-9);
		}while(fractions[i].is_correct() != true);

		assert(fractions[i].is_correct() );
		fractions[i].shorten();
		fractions[i].numerator == 0 ? printf(" 0 \n ") : printf("%d / %d \n", fractions[i].numerator , fractions[i].denominator);
	}
	delete []fractions;
}
