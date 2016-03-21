#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <assert.h>

int gdc(int a, int b){
	if(a == 0) return b>0?b:-b;
	if(a < 0) a*=-1;
	if(b < 0) b*=-1;
    while(a!=b){
		if(a>b)
           a-=b;
       else
           b-=a;
   }
   return a;
}

struct fraction {
	int nominator;
	int denominator;
	bool is_correct() {
		return denominator!=0?nominator%denominator == nominator?1:0:0;
	}
	int shorten() {
		int nwd = gdc(nominator, denominator);
		nominator /= nwd;
		denominator /= nwd;
	}
};


int main(int argc, char **argv) {
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	for(int i = 0; i < n; i++) {
		do {
			fractions[i].nominator = rand()%19 - 9;
			fractions[i].denominator = rand()%19 - 9;
		} while(fractions[i].is_correct() != 1);
		fractions[i].shorten();
	}
	for(int j = 0; j < n; assert(fractions[j++].is_correct())) 
		printf("%d/%d\n", fractions[j].nominator, fractions[j].denominator);

	delete []fractions;
}
