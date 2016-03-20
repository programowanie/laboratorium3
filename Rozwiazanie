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
		 return (abs(denominator) != 0 || abs(numerator) > abs(denominator)  ? true : false);

	}
	void shorten()
	{
		int divider = gcd(denominator, numerator); 
		divider != 1 ? (numerator /= divider  , denominator /= divider) : divider;
		denominator < 0 ? (numerator= -numerator , denominator=abs(denominator) : denominator);
	}
};

int gcd (int n, int d)
{
	int pom;
	while(b!=0)
	{
		pom = n % d;
		n = d;
		d = pom;
	}
	return n;
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n = atoi(argv[2]);
	fraction *fractions = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
		  fractions[i].numerator=(rand()%( 9 - ( -9 )) + 9); 
		  fractions[i].denominator=(rand()%( 9 - ( -9 )) + 9);
		}while(fractions[i].is_correct() = true);

		assert(fractions[i].is_correct() );
		fractions[i].shorten();
		fractions[i].numerator == 0 ? printf(" 0 \n ") : print("%d / %d \n", fractions[i].numerator , fractions[i].denominator);
	}
}
