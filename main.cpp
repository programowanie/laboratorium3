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
{return (denominator&&(nominator/denominator==0)? true:false);};
void shorten()
{
	int n=gcd(nominator,denominator);
	nominator/=n;
	denominator/=n;
};
};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n=atoi(argv[1]);
	srand(time(NULL));
	fractions= new fraction[n];
	for(int i=0; i<n; i++)
	{
		do
		{
			fractions[i].nominator=rand()%19 -9;
			fractions[i].denominator=rand()%19 -9;

		}while(fractions[i].is_correct()==0);

	}
	for(int i=0; i<n; i++)
		fractions[i].shorten();


	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	delete []fractions;
	
}
int gcd (int a, int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}