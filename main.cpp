#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int gcd (int a, int b)
{
	int c;
	while(b!=0)
	{
		c=a;
		a=b;
		b= c % b;

	}
	if(a<0)
	{
		a=a*(-1);
	}
	return a;

};

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		return (denominator !=0 && abs(nominator) > abs(denominator)) ? true : false ;
	};
	void shorten()
	{
		int NWD =gcd(nominator,denominator);
		nominator=nominator/NWD;
		denominator=denominator/NWD;
	}

};

int main(int argc, char **argv)

{
	int n=atoi(argv[1]);
	srand(time(NULL));
	fraction *fractions = new fraction[n];
	for(int i=0;i<n;i++)
	{
		do{
			fractions[i].nominator = rand() %19 -9;
			fractions[i].denominator = rand() %19 -9;
		}while(!fractions[i].is_correct());
		fractions[i].shorten();

	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
 }