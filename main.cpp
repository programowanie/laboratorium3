#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int numerator, denominator;
	bool is_correct()
	{
		bool correct;
		correct=(abs(numerator)>=abs(denominator) || denominator==0 || numerator==0) ? false : true;
		return correct;
	}
	void shorten(int divisor)
	{
		numerator=numerator/divisor;
		denominator=denominator/divisor;
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	if(argc!=2)
	{
		print("Incorrect number of arguments! Exiting...\n");
		exit(1);
	}
	int n=atoi(argv[1]);
	fractions=(fraction*)malloc(n*sizeof(fraction));
	srand(time(NULL));
	int j=0;
	do
	{
		fractions[j].numerator=rand()%19-9;
		fractions[j].denominator=rand()%19-9;
		if (fractions[j].is_correct())
		{
			fractions[j].shorten(gcd(fractions[j].numerator, fractions[j].denominator));
			j++;
		}
	} while (j<n);
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	free(fractions);
	return 0;
}



int gcd (int a, int b)
{
	int divisor;
	for (int i=1; i<=abs(a) && i<=abs(b); i++) if (a%i==0 && b%i==0) divisor=i;
	return divisor;
}
