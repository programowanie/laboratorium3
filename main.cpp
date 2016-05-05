#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct() {
		return((denominator!=0) && (nominator<denominator))?true:false;
	}

	void shorten()
	{
	int NWD;
		NWD=gcd(nominator,denominator);
		if(NWD!=0)
		{
			nominator/=NWD;
			denominator/=NWD;
		}
	}
};

int main(int argc, char **argv)
{
	int n= atoi(argv[1]);
	fraction *fractions = new fraction[n];

	srand(time(NULL));

	for(int i=0; i<n; i++) {
			do{
				fractions[i].nominator=rand()%19-9;
				fractions[i].denominator=rand()%19-9;
			} while(!fractions[i].is_correct());
		}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%d] %2d / %2d\n", i, fractions[i].nominator, fractions[i].denominator);
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		fractions[i].shorten();
		printf("[%d] %2d / %2d\n", i, fractions[i].nominator, fractions[i].denominator);
	}
	delete []fractions;
}

int gcd(int a, int b)
{
    int y;
    while( b != 0){
        y = b;
        b = a % b;
        a = y;
        return a;
    }
return 0;
}