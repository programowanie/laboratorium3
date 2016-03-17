#include <stdio.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct;
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	int fraction *fractions=new int fraction.denominator[n];
	int fraction *fractions=new int fraction.nominator[n];
	for(int i=0; i<n; i++)
	{
		fraction[i].nominator=(rand()%19)-9;
		fraction[i].denominator=(rand()%19)-9;
	}

	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	*/
}
