#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct();
	void shorten();
};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n = atoi(argv[1]);
	fractions = new fraction[n];

	srand(time(NULL));

	for(int i=0; i<n; i++)
	{
		do
		{
			fractions[i].nominator = rand()%19-9;
			fractions[i].denominator = rand()%19-9;
		}
		while(!fractions[i].is_correct());

		fractions[i].shorten();
	}

	for (int i=0; i<n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}

bool fraction::is_correct()
{
	return(denominator!=0 && abs(nominator)<abs(denominator) ? true : false);
	//działa też dla licznika o wartości ujemnej, bo pobiera wart. bezwzględną
}

int gcd(int a, int b) //Algorytm Euklidesa
{
	a = abs(a);
	b = abs(b);

	do
	{
		if(a>b) a -= b;
		if(b>a) b -= a;
	}
	while(a!=b && a!=0);

	return a;
}

void fraction::shorten()
{
	int c = gcd(nominator, denominator);

		nominator /= c;
		denominator /= c;
}