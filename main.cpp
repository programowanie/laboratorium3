#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int gcd (int a, int b) {
	int c;
	while (b != 0) {
		c = a%b;
		a = b;
		b = c;
	}
	return abs(a);
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
	if (argc==2) {
		int n = atoi(argv[1]);
		if (n>0) {
			srand(time(NULL));
			fraction *fractions = new fraction[n];
			for (int i = 0; i < n; i++) {
				do {
					fractions[i].nominator = rand()%20-10;
					fractions[i].denominator = rand()%20-10;
				} while(!fractions[i].is_correct());
				fractions[i].shorten();	
			}
			for (int i = 0; i < n; assert(fractions[i++].is_correct()))
				printf("[%i] %2i / %2i\n", 
					i, 
					fractions[i].nominator, 
					fractions[i].denominator);
			delete[] fractions;
		} else printf("Błąd: podano niepoprawną długość tablicy");
	} else printf("Błąd: błędna długość listy argumentów");
}