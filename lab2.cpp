#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int counter;
	int denominator;
	bool is_correct()
	{
		return denominator != 0 &&  abs(counter) < abs(denominator) ? true : false;
	}

	void shorten()
	{
		int div = gcd(counter, denominator);
			counter /= div;
			denominator /= div;

	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(*(argv + 1));
	fraction * fractions = new fraction[n];

	for(int i; i < n; i++)
	{
		do
		{
			fractions[i].counter = rand()%19 -9;
			fractions[i].denominator = rand()%19 -9;
		} while(fractions[i].is_correct() == false); 
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{	
		fractions[i].shorten();
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].counter, 
			fractions[i].denominator);
	}

}

int gcd (int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}