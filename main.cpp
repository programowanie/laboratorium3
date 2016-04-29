#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;

	bool is_correct()
	{
		return (abs(nominator)<abs(denominator)&&denominator!=0)?true:false;
	}

	void shorten()
	{
		int a=gcd(nominator,denominator);
		nominator/=a;
		denominator/=a;
	}
};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	
	fraction *fractions = new fraction[n];

	srand (time(NULL));

	for(int i=0;i<n;i++)
	{
		do
		{
		fractions[i].nominator=rand()%18-9;
		fractions[i].denominator=rand()%18-9;
		} while(fractions[i].is_correct()==false);
	
		fractions[i].shorten();
	}

	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}

int gcd (int a, int b)
	
{
    a=abs(a);
    b=abs(b);
    
    if(a>0 && b>0)
    {  int r=0;
       do
       { r=a%b;
           a=b;
           b=r;
       }while(b!=0);
    
    return a;
    }
    return 1;
}
