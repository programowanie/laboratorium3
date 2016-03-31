#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{	
	int nominator, denominator;
	void shorten();	
	bool is_correct()
	{
		return((denominator)!=0 && abs(nominator) < abs(denominator) ? true : false);
	}
};

int main(int argc, char **argv)
{	
	srand( time( NULL));
	int n=atoi(argv[1]);
	fraction *fractions = new fraction [n];

	for(int i=0; i<n; i++)
	{	
		do
		{
		fractions[i].nominator   = rand()%19-9;
		fractions[i].denominator = rand()%19-9;
		}while(!fractions[i].is_correct());

		fractions[i].shorten();
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		printf("[%i] %2i / %2i\n", i, fractions[i].nominator, fractions[i].denominator);
	}	
	
}
int gcd(int a, int b)
	{
		int x;
		while(b != 0)
		{
			x = a % b;
			a = b;
			b = x;
		}
		return a;
	}	

void fraction::shorten()
	{
		int divisor = gcd(denominator, nominator);
		nominator   = nominator/divisor;
		denominator = denominator/divisor;
		
		if(nominator > 0 and denominator < 0)
		{
			nominator   = nominator   *-1;
			denominator = denominator *-1; 
		}
		
	}