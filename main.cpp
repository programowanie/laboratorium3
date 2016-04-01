#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int gcd (int nominator, int denominator)
{
	for(int i = abs(nominator); i > 1; i--)
	{
		if(nominator%i == 0 && denominator%i == 0)
			return i;
	}
	return 1;
}

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return (denominator != 0 && abs(nominator) < abs(denominator)) ? true:false;
	}
	void shorten()
	{
		int divider = gcd(nominator, denominator);
		
		if(divider > 1)
		{
			nominator /= divider;
			denominator /= divider;
		}
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));

	for(int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator = -9 + rand()% + 19;
			fractions[i].denominator = -9 + rand()% + 19;
		}
		while (fractions[i].is_correct() != true);

		fractions[i].shorten();
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}
