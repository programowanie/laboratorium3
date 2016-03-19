#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

struct fraction
{
	signed int nominator, denominator;

	bool is_correct()
	{
		return(denominator==0 || nominator>=denominator || nominator==0) ? false : true;
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;

	int n=atoi(argv[1]);

	fractions = new fraction[n];

	srand(time(NULL));

	for( int i=0; i<n; i++)
	{
		do{
		fractions[i].nominator=rand()% 19-9;
		fractions[i].denominator=rand()% 19-9;}
		while(fractions[i].denominator==0 || fractions[i].nominator>=fractions[i].denominator || fractions[i].nominator==0);

	};

	for (int i = 0; i < n; i++)
	{
		assert(fractions[i].is_correct());
		printf("[%i] %2i / %2i\n", 
			i+1, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	
}