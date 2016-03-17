#include <stdio.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	
	bool is_correct(denominator!=0 && nominator<denominator)
	{
		return true;
	}


};

int main(int argc, char **argv)
{
	int n;

	n = atoi(argv[1])

	fraction *fractions;
	fractions = new fraction [n];

	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}