#include <stdio.h>
#include <assert.h>
#include <time.h>

#include <stdlib.h> //[S]Rand

int gcd (int a, int b) {
	int c;
	while(b!=0) {
		c = a%b;
		a = b;
		b = c;
	}
	return a; // dzielnik via euklides.
}

struct fraction
{
	int nominator, denominator;
	bool is_correct(int nom, int denom) {
		return (denom != 0 && nom < denom) ? true : false;
	}
	void shorten (int &a, int &b) {
		int x = a/gcd(a, b);
		int y = b/gcd(a, b);
		a = x;
		b = y;
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *frs = new fraction[n];
	for (int i=0; i < n; i++) {
		do {
			frs[i].nominator = rand() % 18 -9;
			frs[i].denominator = rand() % 18 -9;
		}
		while(!(frs[i].is_correct(frs[i].nominator, frs[i].denominator)));
		printf("%d/%d\n", frs[i].nominator, frs[i].denominator);
	}
	for (int i = 0; i < n; assert(frs[i++].is_correct(frs[i].nominator, frs[i].denominator))) {
		printf("[%i] %2i / %2i\n", 
			i+1, 
			frs[i].nominator, 
			frs[i].denominator);
	}
}
