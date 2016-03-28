#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

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

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct ()
	{
		return (denominator!=0 && abs(nominator)<abs(denominator))?true:false;
	}

	void shorten()
	{
		int NWD=gcd(nominator,denominator);
		nominator=nominator/NWD;
		denominator=denominator/NWD;
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	srand(time(NULL));
	int n=atoi(argv[1]);

	fractions=new fraction[n];
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;

			fractions[i].shorten();
		}
		while(fractions[i].is_correct()==0);
		
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	
}
