#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct()
	{	//a ? b : c
		return (nominator > denominator && denominator!=0) ? true : false;
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n = atoi(argv[1]);
		//printf("%i\n", n);
		fractions = new fraction [n];
	
	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;	
		}
		while(!fractions[i].is_correct());
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}