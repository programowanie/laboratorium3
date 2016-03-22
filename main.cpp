#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct();
	void shorten();
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n = atoi(argv[1]);
	fractions = new fraction [n];
	
	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;	
		}
		while(!fractions[i].is_correct());
	fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);	
}

int gcd(int a, int b)
{
	//it seems like Euclidean algorithm can't handle negative values 
	a=abs(a);
	b=abs(b); 	
    while(a!=b && a!=0)
    {
       if(a>b)
           a-=b;
       else
           b-=a;
     }
    //dividing by zero makes black holes in the galaxy, right?
    if(a!=0) 	
    	return a;
	else
		return 1;
}

bool fraction::is_correct()
	{	//absolute values solves problem of -9/1 considered as correct fraction
		return 
		(abs(nominator) < abs(denominator) 
		&& denominator!=0) ? true : false;
	}

void fraction::shorten()
	{
		int diviser=gcd(nominator, denominator);
		
		nominator 	/=diviser;
		denominator	/=diviser;
		//we are getting rid of negative value in denominator cuz -3/4 looks better than 3/-4 AND 3/4 is more correct than -3/-4
		if(denominator<0)
			{
				nominator*=-1;
				denominator*=-1;
			}
	}