#include <stdio.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;

	bool is_correct()
	{
		return (denominator != 0 && abs(nominator) < abs(denominator) ? true : false); 
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n = atoi(argv[1]);
	fractions = new fraction[n];

	srand(time(NULL));
	for(int i=0; i < n; i++)
	{
		do 
		{
			fractions[i].nominator = rand()%18 - 19;
			fractions[i].denominator = rand()%18 - 19;
		}while(fraction[i].is_correct() == false)
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator;
	}
}
int gcd (int a, int b)
{
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
		return a;
	}
}