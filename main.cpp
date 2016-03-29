
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b)
{
    return b==0 ? a: gcd(b, a % b);
 
}


struct fraction
{
	int nominator,denominator;


	void shorten()
	{
		int divisor=gcd(nominator,denominator);	
		nominator/=divisor;
		denominator/=divisor;
		if(denominator<0)
		{
			nominator*=-1;
			denominator*=-1;
		}
	}

	bool is_correct()
	{
		return(denominator && abs(denominator) > abs(nominator))?true:false;
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
			fractions[i].nominator=(rand()%19)-9;
			fractions[i].denominator=(rand()%19)-9;
		}
		while(!fractions[i].is_correct());
		fractions[i].shorten();
	} 

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

	delete [] fractions;
}
