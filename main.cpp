#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;

	bool is_correct()
	{
		return(denominator!=0 && nominator<denominator) ? true : false;
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;

	int n=atoi(argv[1]);

	fractions = new fraction[n];

	srand(time(NULL));

	for( int i=0; i<n; i++)
	{
		fractions[i].nominator=rand()% 19-9;
		fractions[i].denominator=rand()% 19-9;
	}

	for(int i=0; i)

	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}