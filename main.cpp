#include <stdio.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		 return denominator != 0 || nominator > denominator  ? true : false

	}

};


int main(int argc, char **argv)
{
	fraction *fractions;
	int n = atoi(argv[2]);
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}