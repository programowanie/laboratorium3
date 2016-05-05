#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{	
		return((abs(denominator)>abs(nominator)) && (denominator!=0)?true:false);
	};
	void shorten()
	{
		int a = gcd(abs(nominator), abs(denominator));
		nominator = nominator/a;
		denominator = denominator/a;
	};
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(time(NULL));

	fraction *fractions = new fraction[n];

	for (int i=0; i<n; i++)
	{
		do
		{ 
			fractions[i].nominator = (rand() % 19) - 9;
			fractions[i].denominator = (rand() % 19) - 9;			
		}
		while (fractions[i].is_correct() != true);

		fractions[i].shorten();
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", i, fractions[i].nominator, fractions[i].denominator);
}

int gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}
