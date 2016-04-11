#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;

	bool is_correct()
	{
		return ((abs(nominator) < abs(denominator)) && 
				(denominator!=0)) ? true : false;
	}

	void shorten(int a)
	{
		nominator/=a;
		denominator/=a;
	}
};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]), a;
	srand(time(NULL));
	fraction *fractions = new fraction[n];

	for(int i=0; i<n; i++)
	{
		do
		{
			fractions[i].denominator=rand()%19-9;
			fractions[i].nominator=rand()%19-9;
		}while(!fractions[i].is_correct());
		
		a = gcd(fractions[i].nominator, fractions[i].denominator);
		fractions[i].shorten(a);
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}

int gcd (int a, int b)
{
	int tmp;
	while(b!=0)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}

	return a;
}