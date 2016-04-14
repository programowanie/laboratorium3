#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;

	bool is_correct()
	{
		return (((nominator < 0 ) ? -nominator : nominator) < ((denominator < 0 ) ? -denominator : denominator) 
			&& denominator != 0) ? true : false;
	}

	void shorten()
	{
		int shortener = gcd(nominator, denominator);
		nominator /= shortener;
		denominator /= shortener;
	}


};

int main(int argc, char **argv)
{
	srand(time(NULL));

	int n = atoi(argv[1]);

	fraction *fractions = new fraction[n];

	for(int i = 0; i <  n; i++)
	{
		do
		{
			fractions[i].nominator = rand()%19 - 9;
			fractions[i].denominator = rand()%19 - 9;
		}
		while(!fractions[i].is_correct());
		
	}

	for(int i = 0; i < n; i++)
		fractions[i].shorten();

	for(int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}

int gcd(int a, int b)
{
	int temporary;
                  
    while(b != 0)             
    {
        temporary = a % b;
        a = b;
        b = temporary;
    }

    return a;
}
