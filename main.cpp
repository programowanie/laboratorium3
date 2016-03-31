
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		return ((denominator!=0)&&(abs(nominator)<abs(denominator))?true:false);
	}
	void shorten()
	{
	int nwd=gcd(nominator, denominator);
	nominator=nominator/nwd;
	denominator=denominator/nwd;
	if(denominator<0)
	{
		nominator*=-1;
		denominator*=-1;
	}
}


};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	fraction *fractions=new fraction[n];
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		
		do
		{
			fractions[i].nominator=-9+rand()%19;
		fractions[i].denominator=-9+rand()%19;

		}
		while(fractions[i].is_correct()==false);
	}


	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	//sprawdzam poprawność funkcji shorten
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
int pom;
 
  while(b!=0)
    {
    pom = b;
    b = a%b;
    a = pom;  
  }
 
    return a;
}