#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct(){
		return (denominator!=0&&nominator<denominator)?true:false;
	}
	void shorten(){
		int divider = gcd(abs(nominator), abs(denominator));
		nominator /= divider;
		denominator /= divider;
	}
};
fraction *fill_fractions(int n);
int main(int argc, char **argv)
{
	
	if(argc<1)
		return 0;
	int n = atoi(argv[1]);
	srand(time(NULL));
	fraction *fractions = fill_fractions(n);

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}
fraction *fill_fractions(int n){
	fraction *fractions = new fraction[n];
	for(int i = 0; i<n; ++i){
		do{
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;
		}while(!fractions[i].is_correct());
		fractions[i].shorten();
	}
	return fractions;
}
int gcd(int a, int b){
	return a==0?1:a!=b?gcd(a>b?a-b:a,b>a?b-a:b):a;
}
