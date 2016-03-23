#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>	
#include <math.h>

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return (denominator!=0)&&((abs(nominator))<(abs(denominator)))?true:false;
	}
	void shorten();
};


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

void fraction::shorten()
{
	int temp=gcd(nominator, denominator);
	denominator=denominator/temp;
	nominator=nominator/temp;
	/*if((nominator<0)&&(denominator<0))
		{
			nominator*=(-1);
			denominator*=(-1);
		}*/
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions;
	fractions=new fraction[n];
	for(int i=0; i<n; i++)
	{
		do
		{
		fractions[i].nominator=(rand()%19)-9;
		fractions[i].denominator=(rand()%19)-9;
		}
		while(fractions[i].is_correct()==false);
		fractions[i].shorten();
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}