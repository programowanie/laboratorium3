#include <stdio.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);
//komentarz

struct fraction
{ int nominator;
  int denominator;
};

bool is_correct
{
   return denominator != 0 && nominator < denominator
   	? true
   	: false;
}

int main(int argc, char **argv)
{
	int n;
    n=atoi(argv[1]);
    srand(time(NULL));
	fraction *fractions;
	*fractions = new fractions [n];
	do{
	for (int i=0;i<n;i++)
	{
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;

	}
    }while(fractions[i].is_correct()!=0;)
  
	for (int i = 0; i < n; assert(fractions[i++].is_correct()!=0))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}