#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{return((denominator!=0 && abs(nominator)<denominator) ? 1:0	);}
	int shorten()
	{
		int div=gcd(nominator,denominator);
		nominator=nominator/div;
		denominator=denominator/div;
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions=new fraction[n];
	for(int i=0;i<n;i++)
	{
		do{
		fractions[i].nominator=rand()%19 -9;
		fractions[i].denominator=rand()%19 -9;
		fractions[i].shorten();
		}while(!fractions[i].is_correct());
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct())){
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
}

int gcd (int a, int b)
{
	int c;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}