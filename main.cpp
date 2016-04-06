#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cmath>
#include <cstdlib>
int gcd (int a, int b)
{
  	int c;
 	while ( a != 0 ) {
 	 	    c = a;
			a = b % a;
			b = c;
 	}
  	return b;
}

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct();

	fraction shorten();
};

bool fraction::is_correct()
{
		return ( (nominator!=0 && denominator!=0 && std::abs(nominator)<std::abs(denominator))? true : false);
}

fraction fraction::shorten()
{
	fraction wynik;
	int k=gcd(nominator,denominator);
	denominator=denominator/k;
	nominator=nominator/k;
	wynik.denominator=denominator;
	wynik.nominator=nominator;
	if(denominator < 0)
		{
			wynik.nominator=(-1)*nominator;
			wynik.denominator=(-1)*denominator;
		}


	return wynik;

}

int main(int argc, char **argv)
{

	int n=10;
	fraction *fractions=new fraction[n];
	srand( time( NULL ) );

	for(int i = 0; i < n; i++)
	{
		do{
			fractions[i].nominator=(rand() % 19) + (-9);
			fractions[i].denominator=(rand() % 19) + (-9);
		}while(!fractions[i].is_correct());

		fractions[i]=fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n",
			i,
			fractions[i].nominator,
			fractions[i].denominator);

}
