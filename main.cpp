#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gdc(int quantity1, int quantity2);

struct fraction
{
	int nominator, denominator;

	bool is_correct()
	{
		return (nominator < denominator && denominator!=0)? true : false;
	}
	void shorten()
	{
		int divider = gdc(nominator, denominator);
		nominator = nominator/divider;
		denominator = denominator/divider;
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));

	//Pierwszy wariant. Losowanie ułamków o wartościach <-9,9>
	/*
	for(int i = 0; i < n; i++)			
	{
		do
		{
			fractions[i].nominator = rand();
			fractions[i].denominator = rand();
		}while((double)fractions[i].nominator/fractions[i].denominator <= 9 && 
			(double)fractions[i].nominator/fractions[i].denominator >= -9);
	}
	*/
	//Drugi wariant. Losowanie licznika i mianownika z <-9,9>. Pierwsza opcja zgadza się z
	//poleceniem, ale nie działa z resztą programu, a druga odwrotnie.
	
	for(int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator = (rand()%19)-9;
			fractions[i].denominator = (rand()%19)-9;
		}while(!fractions[i].is_correct());
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	
	delete [] fractions;
}

int gdc(int quantity1, int quantity2)
{
	int divider = 1;
	int lower_quantity;
	lower_quantity = (quantity1 < quantity2) ? quantity1 : quantity2;

	for(int i = 2; i <= lower_quantity; i++)
	{
		if(quantity1%i == 0 && quantity2%i == 0)
		{
			divider = i;
		}
	}
	return divider;
}



