#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
int gcd (int a, int b);

struct fraction
{	
	int nominator;
	int denominator;
	bool is_correct()
	{
		return (abs(nominator)<abs(denominator)&&denominator!=0) ?  true :  false;
	}
	void shorten()
	{ 	int nwd=gcd(nominator,denominator);
		nominator=nominator/nwd;
		denominator=denominator/nwd;
	}
};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);

	fraction *fractions=new fraction[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{	
		do 
		{	fractions[i].nominator=(rand()%19)-9;
			fractions[i].denominator=(rand()%19)-9;
		}while(!(fractions[i].is_correct()));	
	}

	

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{	
		fractions[i].shorten();
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	delete []fractions;
}

int gcd(int a,int b)
{
	int c;
  	while(b!=0)
  	{	
  		c=a%b;
  		a=b;
  		b=c;

  	}

  	return a;
}