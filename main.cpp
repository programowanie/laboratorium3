#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int n, int d)
{
	return d==0 ? n : gcd (d, n%d);
}

struct fraction
{
	int denominator;
	int nominator;

	bool is_correct()
	{
		return (denominator!=0 && abs(nominator)<abs(denominator))? true : false;
	}
	
	int shorten ()
	{
		int r = gcd (nominator, denominator);
		r=abs(r);
		nominator=(nominator/r);
		denominator=(denominator/r);
		return (nominator, denominator);
	}

};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(time(NULL));
	fraction *fractions = new fraction [n];
	for (int i=0; i<n; i++)
	{
		do
		{
			fractions[i].nominator = rand()%19-9;
		 	fractions[i].denominator = rand()%19-9;
		} while (!fractions[i].is_correct());
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
			printf("[%i] %2i / %2i\n", i, fractions[i].nominator, fractions[i].denominator);
		
		printf ("\nPowyzsze ulamki po skroceniu:\n");	
		for (int i=0; i<n; i++)
		{
			fractions[i].shorten();
			printf("[%i] %2i / %2i\n", i, fractions[i].nominator, fractions[i].denominator);
	 	}
}