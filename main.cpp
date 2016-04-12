#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
//korzystam z funkcji abs() z biblioteki math.h aby uniknąć ułamków typu -9/2, bo i takie program losował


int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct()
	{
		return ((denominator!=0 && abs(nominator)<abs(denominator)) ? (true) : (false));
	}
	void shorten()
	{
		int g;
		g=gcd(nominator, denominator);
		nominator=nominator/g;
		denominator=denominator/g;
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		do
		{
			fractions[i].nominator=(rand()%19)-9;
			fractions[i].denominator=(rand()%19)-9;
		}
		while(!fractions[i].is_correct());
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	printf("\n\n");
	for(int i=0; i<n; i++)
	{
		fractions[i].shorten();
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	
	delete[] fractions;
}

int gcd(int a, int b)
{
	int c;
	while(b!=0)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}