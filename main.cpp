#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b) {
	int sign = ((a<0)&&(b<0))?-1:1;
	a = (a>0)?a:-a; b = (b>0)?b:-b;
	int biggest = (a>b)?a:b;
	while ((biggest>0)&&((a%biggest != 0)||(b%biggest != 0))) biggest--;
	return biggest*sign;
}

struct fraction {
	int nominator;
	int denominator;
	bool is_correct() {
		return ((denominator!=0)&&(nominator<denominator))?true:false;
	}
	void shorten() {
		int divider = gcd(nominator, denominator);
		nominator /= divider;
		denominator /= divider;
	}
};

int main(int argc, char **argv) {
	if (argc>=2) {
		int n = atoi(argv[1]);
		if (n>0) {
			fraction *fractions = new fraction[n];
			for (int i = 0; i < n; i++) {
				do {
					fractions[i].nominator = rand()%20-10;
					fractions[i].denominator = rand()%20-10;	
					fractions[i].shorten();	
				} while(!fractions[i].is_correct());
			}
			for (int i = 0; i < n; assert(fractions[i++].is_correct()))
				printf("[%i] %2i / %2i\n", 
					i, 
					fractions[i].nominator, 
					fractions[i].denominator);
			delete[] fractions;
		} else printf("Błąd: podano niepoprawną długość tablicy");
	} else printf("Błąd: zbyt krótka lista argumentów");
}