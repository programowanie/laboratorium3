#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
//int gcd (int a, int b);

struct fraction
{
	int numerator;
	int denominator;
	bool is_correct()
	{
		return((denominator!=0) && (abs(numerator)<abs(denominator))?true:false);
	}
};

int main(int argc, char **argv)
{
	srand (time(NULL));
	fraction *fractions;

	int n = atoi(argv[1]);		
	fractions = new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			fractions[i].numerator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}
		while(!fractions[i].is_correct());
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].numerator, 
			fractions[i].denominator);

	}
}