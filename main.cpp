#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd(int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		return (denominator != 0) ? (nominator < denominator ? true : false) : false;
	}
	void shorten()
	{
		int divisor = gcd(nominator, denominator);
		nominator /= divisor;
		denominator /= divisor;
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));

	for(int i = 0 ; i < n ; i++)
	{
		do
		{
			fractions[i].nominator = (rand() % 19) - 9;
			fractions[i].denominator = (rand() % 19) - 9;
		}while(!fractions[i].is_correct());

		fractions[i].shorten();
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

	delete [] fractions;

}

int gcd(int a, int b)
{
	// Euclidean algorithm
	int temp;
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	if(a < 0)
			a *= -1; 
	return a;
}