#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int gcd (int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

struct fraction
{
	int nominator,denominator; //deklaracja licznika i mianownika
	bool is_correct() //funkcja sprawdzajaca poprawnosc
	{
		return (nominator < denominator	||	denominator==0)
		?false:true;
	}
	void shorten(int &a, int &b)
	{
		int d=gcd(a,b);
		a=(a/d);
		b=(b/d);
	}
};

int main(int argc, char **argv)
{
	int n;
	if(argc>1) n=atoi(argv[1]); //pobranie argumentu wiersza polecen
	srand(time(NULL));
	fraction *fractions = new fraction;  //przydzielenie pamieci

	for (int i = 0; i < n; ++i)
	{
		do
		{
			fractions[i].denominator =
			rand()%19-9;
			fractions[i].nominator =
			rand()%19-9;	
		}
		while (!fractions[i].is_correct());
		assert (fractions[i].is_correct());
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	/*
	printf("Po skroceniu:\n");
	for (int i = 0; i < n; ++i)
	{
		fractions[i].shorten(
			fractions[i].nominator, 
			fractions[i].denominator);
		printf("[%i] %2i / %2i\n",
			i,
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	*/
}