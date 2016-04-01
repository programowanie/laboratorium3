#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

struct fraction
{
	int denominator,nominator;

	bool is_correct()
	{
	return (abs(denominator) > abs(nominator) && denominator !=0) ?true :false;
	};

};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions= new fraction[n];
	for(int i=0;i<n;i++)
	{
		do
		{
		fractions[i].denominator=rand()%19-9;
		fractions[i].nominator=rand()%19-9;
		}while( !fractions[i].is_correct());
		assert (fractions[i].is_correct());
		
	}
		
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
}
