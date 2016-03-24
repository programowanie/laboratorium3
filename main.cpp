#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int gcd (int a, int b);

struct fraction
{
	int numerator;
	int denominator;
	bool is_correct()
	{
		return((denominator!=0) && (abs(numerator)<abs(denominator))?true:false);
	}
	void shorten()
	{
		if(numerator!=0)
		{
			int d=gcd(numerator, denominator);
			numerator=numerator/d;
			denominator=denominator/d;
		}
	}
};

int main(int argc, char **argv)
{
	srand (time(NULL));
	fraction *fractions;

	int n = atoi(argv[1]);		
	fractions = new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			fractions[i].numerator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}
		while(!fractions[i].is_correct());
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{
		/*printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].numerator, 
			fractions[i].denominator);
		*/



			fractions[i].shorten();
			printf("[%i] %2i / %2i\n", 
				i, 
				fractions[i].numerator, 
				fractions[i].denominator);

		}
	}
	//a=numerator, b=denominator
	int gcd (int a, int b)
	{
		a=abs(a);
		b=abs(b);
		int gcd=1;


		if(a==0)
		{
			return 0;

		}

		else if(0==(b%a))
		{
			return a;
		}
		else
		{
			int step=2;

			while(step<=sqrt(b))
			{

				if((a%step==0) && (b%step==0))
					gcd*=step;

				step++;
			}

			return gcd;
		}
	}