#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

const int primes[4] = {2, 3, 5, 7};

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		return denominator != 0 ? (nominator < denominator ? true : false) : false;
	}
	void shorten() {
		printf("    %2i / %2i\n", 
			nominator/gcd(nominator, denominator), 
			denominator/gcd(nominator, denominator));
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction [n];
	srand(time(NULL));

	for (int i = 0; i < n; assert(fractions[i++].is_correct())) {
		
		do {
			fractions[i].nominator = rand() %18 - 9;
			fractions[i].denominator = rand() %18 - 9;
		} while (!fractions[i].is_correct());

		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
		fractions[i].shorten();
	}

	delete [] fractions;	
}

int gcd(int a, int b) {

	int gcd = 1;

	if (a == 0) 	
	{
		return 1;
	}

	if (b % a != 0)
	{		
		for (int i = 0; i < 4; ++i)
		{
			if ( (primes[i] <= (a > 0 ? a : a * -1) ) && (a % primes[i] == 0) && (b % primes[i] == 0) )
			{
				gcd *= primes[i];
			}
		}
	} else gcd = (a > 0 ? a : a * -1);

	return gcd;
}