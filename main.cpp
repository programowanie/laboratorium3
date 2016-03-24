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

	void shorten()
	{
		nominator = nominator / gcd(nominator, denominator);
		denominator = denominator / gcd(nominator, denominator);
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
			fractions[i].nominator = rand()%19 - 9;
			fractions[i].denominator = rand()%19 - 9;
		}while(fractions[i].is_correct() == false);
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		fractions[i].shorten();
		printf("[%i] %2i / %2i\n", 
			i,
			fractions[i].nominator, 
			fractions[i].denominator);
	}
}
int gcd (int a, int b)
{
    int buf;
 
  	while(b != 0)
    {
    	buf = b;
    	b = a%b;
   		a = buf;  
 	}
    return a;
}
