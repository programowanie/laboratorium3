#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
		{
			return (denominator != 0 && abs(nominator) < abs(denominator)? 
				true: false);
		}
	void shorten()
		{
			if (int factor = gcd(abs(nominator),abs(denominator)))
			{
				nominator /= factor;
				denominator /= factor;
			}
		}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand (time(NULL));
	for (int i = 0; i < n; i++)
	{
		do
		{
		fractions[i].denominator = rand() % 19 - 9;
		fractions[i].nominator = rand() % 19 - 9;
		} while (fractions[i].is_correct()==false);

		fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}

int gcd (int a, int b)
	{
		int check=1;
		for (int i = 2; i <= a; i++)
		{
			if (a%i ==0 && b%i ==0)
			{
				check=i;
			}
		}
		if (check>1)
			return check;
		else
			return false;		
	}