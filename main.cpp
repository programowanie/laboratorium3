#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int gcd(int a, int b);				// szukanie najwiekszego wspolnego dzielnika

struct fraction
{
	int nominator, denominator;

	bool is_correct()				// sprawdzanie poprawnosci ulamka
	{
		return denominator != 0 ?
			(abs(nominator) < abs(denominator) ? true : false) : false;
	}
	void shorten()					// skracanie ulamkow
	{
		int NWD = gcd(denominator, nominator);
		NWD != 1 ? (nominator /= NWD, denominator /= NWD) : NWD;
		denominator < 0 ? (nominator = -nominator, denominator = abs(denominator)) : denominator;
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi(argv[1]);
	fraction *fractions = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
			fractions[i].nominator = (rand() % 19) + (-9);
			fractions[i].denominator = (rand() % 19) + (-9);
		} while (!fractions[i].is_correct());

		assert(fractions[i].is_correct());
		fractions[i].shorten();
		fractions[i].nominator == 0 ?
			printf("0\n")
			:
			printf("%d/%d\n", fractions[i].nominator, fractions[i].denominator);
	}
	delete[]fractions;

}

int gcd(int a, int b)
{
	// algorytm Euklidesa wykorzystujacy metode modulo
	int c;
	while (b != 0) {
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}
