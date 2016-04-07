#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int numerator;
	int denominator;
	bool is_correct(){
		return ((denominator!=0)&&(abs(numerator)<abs(denominator)))?1:0;
	}
	void shorten(){
		int tmp = gcd(numerator,denominator);
		if (tmp!=1){
			numerator /= tmp;
			denominator /= tmp;
		}
	}
};

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	fraction *fractions = new fraction [n];
	srand(time(NULL));
	
	for (int i = 0; i < n; i++){
		do {
			fractions[i].numerator = rand()%19 - 9;
			fractions[i].denominator = rand()%19 - 9;
		}while (!fractions[i].is_correct());
		fractions[i].shorten();
	}
	
	for (int i = 0; i < n; assert(fractions[i++].is_correct())){
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].numerator, 
			fractions[i].denominator);
	}
}

int gcd (int a, int b)
{
	while(b!=0){
	    int reszta = a % b;
	    a = b;
	    b = reszta;
	}
    return a;
}