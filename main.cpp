#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b)
{
	a=abs(a);
	b=abs(b);
	if(a==0 || b==0) return 1;
	do 
	{
		if(a>b)
			a-=b;
		else 
			b-=a;
	}while(a!=b);

	return a;
}

struct fraction
{
	int nominator,denominator;
	bool is_correct(int nominator,int denominator)
	{

		return ((abs(nominator) < abs(denominator)) && (denominator!=0)) ? (true) : (false);
	}
	void shorten(int nom, int den)
	{
		printf("after reducing : %d / %d \n",nom/gcd(nom,den), den/gcd(nom,den) );
	}

};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions= new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
		fractions[i].nominator=rand() % 18 -9;
		fractions[i].denominator=rand() % 18 -9;
		} while (!(fractions->is_correct(fractions[i].nominator, fractions[i].denominator)));
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct(fractions[i].nominator,fractions[i].denominator)))
	{
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
		fractions->shorten(fractions[i].nominator,fractions[i].denominator);
	}
	
}