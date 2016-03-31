#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		return (abs(nominator) < abs(denominator) && denominator != 0) ? true : false;
	}
	void shorten()
	{
		int gcd_buff = gcd(nominator, denominator);
		nominator /= gcd_buff;
		denominator /= gcd_buff;

		//kwestia kosmetyczna, lepiej wygląda '-' w liczniku
		if(denominator < 0)
		{
			nominator *= -1;
			denominator *= -1;
		}
	}
};

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Nieprawidłowa liczba argumentów.\nUżycie: ./lab2 ilość_ułamków");
		return 1;
	}

	int n = atoi(argv[1]);
	if(!(n >0))
	{
		printf("Ilość ułamków musi być > 0");
		return 2;
	}

	fraction *fractions;
	fractions = new fraction[n];

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator = -9 + rand()%19;
			fractions[i].denominator = -9 + rand()%19 ;
		}while(!(fractions[i].is_correct()));
		fractions[i].shorten();
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}

//Algorytm Euklidesa wykorzystujący funkcję modulo
int gcd(int a, int b)
{
	int c;
	while(b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}