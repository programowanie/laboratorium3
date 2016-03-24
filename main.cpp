#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
 	bool is_correct()
 	{
 		return denominator!=0?
 		(abs(nominator)<abs(denominator)?
 			true
 			:
 			false)
 		:
 		false;
 	};
 	void shorten()
 	{		
 		int g = gcd(denominator, nominator);
 		g!=1?(nominator/=g,denominator/=g):g;
 		denominator<0?
 		(nominator=-nominator,denominator=abs(denominator))
 		:
 		denominator;
 	};
};

int main(int argc, char **argv)
{
	int n;
	n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));
	for(int i = 0 ; i < n ; i++)
	{
		do
		{
 			fractions[i].nominator=rand() % 19 + (-9);
 			fractions[i].denominator=rand() % 19 + (-9);
 		}
 		while (fractions[i].is_correct()!=true);
 		assert(fractions[i].is_correct());
 		fractions[i].shorten();
 		fractions[i].nominator==0?
 		printf("0\n")
 		:
 		printf("%d/%d\n", fractions[i].nominator, fractions[i].denominator);
	}
delete []fractions ;
}

int gcd(int a, int b)
{
 	int c;
 	while (b!=0)
 		{
 			c=a%b;
 			a=b;
 			b=c;
 		}
 	return a;
}