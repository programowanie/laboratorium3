#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b)
{
	while(a!=b);
	{
		if (a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return denominator!=0 && abs(nominator)<abs(denominator)?true:false;
	}
	int shorten()
	{
		int NWD=gcd(nominator,denominator);
		nominator=nominator/NWD;
		denominator=denominator/NWD;
	}

};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions=new fraction[n];
	for (int i=0;i<n;i++)
	{
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}
		while (fractions[i].is_correct()==false);
		fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i,
			fractions[i].nominator, 
			fractions[i].denominator);
	delete [] fractions;
}