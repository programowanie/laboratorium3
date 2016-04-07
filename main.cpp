#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b)
{
	while(a!=b)
	{
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	return a;
}

struct fraction
{
int nominator,denominator;
bool is_correct(void) 
	{
return((denominator!=0)&&(abs(nominator)<abs(denominator))?true:false);
	}
void shorten()
	{
		if(nominator!=0)
		{
	int a=gcd(abs(nominator),abs(denominator));
	nominator=nominator/a;
	denominator=denominator/a;
		}
	}
};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	fraction *fractions=new fraction [n];
	srand(time(NULL));
	for (int i=0;i<n;i++)
	{	
		do {
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;
			}
		while (fractions[i].is_correct()!=true);
		fractions[i].shorten();
	}
	
for (int i = 0; i < n; assert(fractions[i++].is_correct()))
{
	
	printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
};
}
