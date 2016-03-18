#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b);

struct fraction
{
	int numerator = 0, denominator = 0;
	bool is_correct()
	{
		return ((denominator != 0 && abs(numerator) < abs(denominator)) ? true : false);
	}
	void shorten(int a)
	{
		numerator /= a;
		denominator /= a;
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].numerator = rand() % 19 -9;
			fractions[i].denominator =  rand() % 19 -9;
		}
		while (fractions[i].is_correct() != true);
		fractions[i].shorten(gcd(fractions[i].numerator, fractions[i].denominator));
	}
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i + 1, 
			fractions[i].numerator, 
			fractions[i].denominator);
}

int gcd(int a, int b)
{
	int temp = 0;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}