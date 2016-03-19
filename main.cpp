#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int gcd(int x, int y);

struct fraction	{
				int n,d;
				bool is_correct(){return d!=0?(abs(n)<abs(d)?true:false):false;};
				void shorten(){int g = gcd(d, n);g!=1?(n/=g,d/=g):g;d<0?(n=-n,d=abs(d)):d;};
				};



int main(int argc, char** argv)
{
	int n=atoi(argv[1]);
	fraction *fractions = new fraction[n];
	srand(time(NULL));
	for (int i=0; i<n; i++)
	{
		do{
		fractions[i].n=rand() % 19 + (-9);
		fractions[i].d=rand() % 19 + (-9);
		}while (fractions[i].is_correct()!=true);
		assert(fractions[i].is_correct());
		fractions[i].shorten();
		fractions[i].n==0?printf("0\n"):printf("%d/%d\n", fractions[i].n, fractions[i].d);
	}
	delete []fractions;
	printf("XD\n");
}

int gcd(int x, int y)
{
	int z;
	while (y!=0){z=x%y;x=y;y=z;}
	return x;
}