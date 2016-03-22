#include <stdio.h>
#include <assert.h>
#include <cstdlib>
#include <time.h>
#include <math.h>

int gcd (int a, int b);


struct fraction
{
	int nominator, denominator;
	bool is_correct();
	void shorten();
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(time(NULL));	
	
	
	fraction *fractions = new fraction [n];
	for (int i =0; i<n; i++)
	{

		do
		{
			fractions[i].nominator=rand()% 19+(-9);
			fractions[i].denominator=rand()% 19+(-9);
		}
		while(! fractions[i].is_correct());
		fractions[i].shorten();
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}

bool fraction::is_correct()
	{
		return (abs(nominator)<abs(denominator)&&denominator!=0) ? true : false;	
	}

void fraction::shorten()
	{
		int divider=gcd(nominator, denominator);
		
		nominator 	/=divider;
		denominator	/=divider;
		if(denominator<0)
			{
				nominator*=-1;
				denominator*=-1;
			}
	}

int gcd(int a, int b)
{
	a=abs(a);
	b=abs(b);
    	printf("a= %i, b= %i\n",a,b );

    while(a!=b&&a!=0)

    {
       if(a>b)
           a-=b;
       else
           b-=a;
    	printf("a= %i, b= %i\n",a,b );
     }
    if(a!=0)
    	return a;
	else
		return 1;
}