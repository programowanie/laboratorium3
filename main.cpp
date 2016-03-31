#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	
	bool is_correct() {
		return denominator != 0 ? (nominator < denominator ? true : false ) : false;
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	
	int n = atoi (argv[1]);
	fractions = new fraction[n];
	
	srand (time(NULL));
	
	for (int i = 0; i<n; i++){
		fraction f;
		
		do {
			f.nominator = (rand() % 18) - 9;
			f.denominator = (rand() % 18) - 9;
		} while(!f.is_correct());

		fractions[i] = f;
	}


	for (int i = 0; i < n; assert(fractions[i++].is_correct()))

		printf("[%i] %2i / %2i\n", i, fractions[i].nominator, fractions[i].denominator);
}