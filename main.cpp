#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

//int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	
	bool is_correct()
	{
		//((denominator != 0 && nominator < denominator) ? return 1 : return 0);
		return ((denominator != 0 && nominator < denominator) ? true : false);
	};
};

int main(int argc, char **argv)
{
	fraction *fractions;
	
	if (argc == 2)
	{
		int n = atoi(argv[1]);
		fractions = new fraction [n];

		
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			fractions[i].nominator = (rand() % 19 - 10);
			fractions[i].denominator = (rand() % 19 - 10);
		}

		for (int i = 0; i < n; i++)

		for (int i = 0; i < n; assert(fractions[i++].is_correct()))
			printf("[%i] %2i / %2i\n", 
				i, 
				fractions[i].nominator, 
				fractions[i].denominator);
	}

	delete [] fractions;
	fractions = NULL;
}