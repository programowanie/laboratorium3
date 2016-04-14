#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd (int a, int b);

struct fraction
{
	int counter;
	int denominator;

	bool is_correct()
	{
		bool check = denominator != 0 && abs(counter) < abs(denominator) ? true : false;
		
		return check;
	}

	void shorten(int counter, int denominator)
	{
		int divisor = gcd(counter, denominator);

		counter /= divisor;
		denominator /= divisor;

		printf(" %2i / %2i\n", counter, denominator);
	}
};

int main(int argc, char **argv)
{
	
	int n = atoi(*(argv+1));

	fraction *fractions = new fraction[n];

	srand(time(NULL));

	for(int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].counter = rand()%19-10;
			fractions[i].denominator = rand()%19-10;
		}
		while(fractions[i].is_correct() == false);
	}
		


	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		{
			printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].counter, 
			fractions[i].denominator);
		}

	for(int i = 0; i < n; i++)
	{
		printf("[%i] ", i);

		fractions[i].shorten(fractions[i].counter, fractions[i].denominator);
		
	}
}

int gcd (int a, int b)
{
	int greatest = 1;
	int n = min(abs(a),abs(b));

	if(n > 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a%i == 0 && b%i == 0)
				greatest = i;
		}
	}

	return greatest;
}