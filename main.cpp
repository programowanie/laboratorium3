#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>


//int gcd (int a, int b);

int gcd(int a, int b)
{
	a=abs(a);
	b=abs(b);
	if(a==0) return b;
	while(a!=b)
	{
		if(a>b) a-=b;
		else b-=a;
	}
	return a;
}

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return (denominator != 0 && abs(denominator)>abs(nominator) ? 1 : 0);
	};
	void shorten()
	{
		int dzielnik=gcd(nominator,denominator);
		nominator/=dzielnik;
		denominator/=dzielnik;
	}

};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions= new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}
		while(!fractions[i].is_correct());
		fractions[i].shorten();
	}
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}

	delete[] fractions;
}