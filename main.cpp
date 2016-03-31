#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
int nominator,denominator;
bool is_correct()
{
	return (denominator!=0 && abs(nominator)<abs(denominator))?true:false;
}
void shorten()
{
	int d=gcd(nominator,denominator);
	nominator=nominator/d;
	denominator=denominator/d;
	if( denominator<0 && nominator<0)
	{
		denominator*=(-1);
		nominator*=(-1);
	}
}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n=atoi(argv[1]);
	fractions=new fraction[n];
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		do
		{
		fractions[i].nominator = -9 +rand()% (9-(-9)+1);
		fractions[i].denominator = -9 +rand()% (9-(-9)+1);
		}while(!(fractions[i].is_correct()));
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
if(b==0) return a;
else return gcd(b, a%b);
}