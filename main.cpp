#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b)
{
	int c;
	while (b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	if(a<0)
	{
		a=a*(-1);
	}
	return a;
}

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		
		return((denominator!=0) && (nominator<denominator) ? true: false);
		
	}
	int shorten()
	{
		int r=gcd(nominator,denominator);
		nominator=nominator/r;
		denominator=denominator/r;
		return (nominator,denominator);
	}
	
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions=new fraction[n];
	for (int i=0;i<n;i++)
	{
		do{
		fractions[i].nominator=(-9)+rand()%19;
		fractions[i].denominator=(-9)+rand()%19;	
		}while(!fractions[i].is_correct());
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		{printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
		printf("A teraz po skroceniu:\n");
		fractions[i].shorten();	
		printf("[%i] %2i / %2i\n\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
		}
	
}
