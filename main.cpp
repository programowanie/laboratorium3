#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int gcd (int a, int b);

struct fraction
{
	int denominator,
		nominator;

	void absoluteValue()
	{
		if(denominator<0 && nominator<0)
		{	
			denominator	=fabs(denominator);
			nominator	=fabs(nominator);
		}
		if(denominator<0 && nominator>=0)
		{
			denominator	=fabs(denominator);
			nominator	*=(-1);	
		}

	} 

	void shorten()
	{

		int n;
		if(nominator==0)
			n=1;
		else
			n=gcd(fabs(nominator),fabs(denominator));
		
		denominator/=n;
		nominator/=n;
	}

	bool is_correct()
	{
		return (denominator==0?false:true && fabs(denominator)>=fabs(nominator)?true:false);		
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));	
	int n=atoi(argv[1]);

	fraction *fractions=NULL;
	fractions=new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			fractions[i].denominator=rand()%19-9;
			fractions[i].nominator	=rand()%19-9;
		}while(!(fractions[i].is_correct()));
		
	}
	

	for (int i = 0; i < n;i++)
		{
			assert(fractions[i].is_correct());
			fractions[i].absoluteValue();
			fractions[i].shorten();

			printf("[%i] %2i / %2i\n", 
				i+1, 
				fractions[i].nominator, 
				fractions[i].denominator);
		}
	delete[]fractions;
}

int gcd (int a, int b)
{
	while(a!=b)
		(a>b?a-=b:b-=a);
	return a;

}
