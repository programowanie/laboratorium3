#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return(denominator != 0) ? (abs(nominator) < abs(denominator) ? true : false) :false;
	}
	void shorten()
	{
		int z=gcd(nominator,denominator);
		nominator=nominator/z;
		denominator=denominator/z;
	}

};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n = atoi(argv[1]);
	fractions = new fraction[n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator=9-rand()%19;
			fractions[i].denominator=9-rand()%19;
		}
		while(fractions[i].is_correct()==0);
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}
int gcd(int a, int b)
{
	for (int i = a; i > 0; i--)
	{
		if(a%i==0 && b%i==0) 
			return i;
	}
}
