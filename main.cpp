#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct()
	{
		return((nominator>=denominator)||(denominator==0))?false:true;
	}
	void shorten();

};
void fraction::shorten()
{
	int x=gcd(nominator,denominator);
	if(x)
	{
		nominator/=x;
		denominator/=x;
	}
}

int main(int argc, char **argv)
{
	fraction *fractions;
	int n;
	n=atoi(argv[1]);
	fractions=new fraction[n];
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		fractions[i].nominator=-9+rand()%(9+9+1);
		fractions[i].denominator=-9+rand()%(18+1);
		do
		{
			if(!(fractions[i].is_correct()))
			{
				fractions[i].nominator=-9+rand()%(9+9+1);
				fractions[i].denominator=-9+rand()%(18+1);	
			}
		}while(!(fractions[i].is_correct()));
	}


	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
	for(int i=0;i<n;i++)
	{
		if(fractions[i].nominator)
			{
				//fractions[i].shorten();
				printf("[%i] %2i / %2i\n", 
				i, 
				fractions[i].nominator, 
				fractions[i].denominator);
			}
			else printf("[%i] %2c \n",i,'0');

	
	}
}
int gcd(int a,int b)
{
	while(!(a==b))
	{
		if(a>b)a-=b;
			else b-=a;
	}
	return a;
}