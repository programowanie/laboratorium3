#include <stdio.h>
#include <assert.h>
#include <cstdlib>
#include <time.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct();
	
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	
	
	fraction *fractions;
	*fractions = new franction[n];
	for (int i =0; i<n; i++)
	{
		fractions[i]=rand()% 9+(-9);
	}
	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}

bool is_correct()
	{
		if()
		{

		}
	}