#include <stdio.h>
#include <assert.h>
#include <time.h>

#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int numerator, denominator;

	bool is_correct()
	{
		return ( ((denominator!=0) && (abs(numerator) < abs(denominator)) )? (true):(false));
	}

	void shorten()
	{
		if(numerator!=0)
		{
			int divisor = gcd(abs(numerator),abs(denominator));

			numerator = numerator/divisor;
			denominator = denominator/divisor;
		}

		if(numerator<0 && denominator<0)
		{
			numerator=abs(numerator);
			denominator=abs(denominator);
		}
	}

};

int main(int argc, char **argv)
{
	srand(time(NULL));

	int n = atoi(argv[1]);

	fraction *fractions;
	fractions = new fraction [n];

	for (int i=0; i<n; i++)
	{	
		do
		{
			fractions[i].numerator = rand()%19 -9;
			fractions[i].denominator = rand()%19 -9;
		}
		while( !(fractions[i].is_correct()) );
	}
	


	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].numerator, 
			fractions[i].denominator);

	printf("\n\n");

//2nd printf with void shorten()
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{	
		fractions[i].shorten();

		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].numerator, 
			fractions[i].denominator);	
	}

	printf("\n\n");
}


int gcd (int a, int b)
{
	while(a!=b)
		if (a>b)
			a-=b;
		else
			b-=a;

	return a;
}