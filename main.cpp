// Na dole w komentarzu istotne informacje. 

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cmath>

#include <stdlib.h> //[S]Rand

int gcd (int a, int b) {
	int c;
	while(b!=0) {
		c = a%b;
		a = b;
		b = c;
	}
	return abs(a); // dzielnik via euklides, patrz adnotacja.
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
			//printf("Licznik: %d Mianownik: %d\n", frs[i].nominator, frs[i].denominator); patrz adnotacja
			frs[i].shorten(frs[i].nominator, frs[i].denominator);
			//printf("Licznik: %d Mianownik: %d\n", frs[i].nominator, frs[i].denominator); patrz adnotacja
		}
		while(!(frs[i].is_correct(frs[i].nominator, frs[i].denominator)));
		printf("%d/%d\n", frs[i].nominator, frs[i].denominator); // patrz adnotacja
	}
	for (int i = 0; i < n; assert(frs[i++].is_correct(frs[i].nominator, frs[i].denominator))) {
		printf("[%i] %2i / %2i\n", 
			i+1, 
			frs[i].nominator, 
			frs[i].denominator);
	}
}

/*	BARDZO WAZNE: w linii 17 zwracany jest MODUL z dzielnika. Wykorzystano funkcje cmath.
*	Bez tego program rowniez przechodzi testy i sie normalnie uruchamia, ale zawiera pewien blad (zakladajac powyzsza implementacje).
*	Powoduje go algorytm Euklidesa (raczej nie moj sposob skracania ulamkow, w koncu i tak trzeba by bylo dzielic przez NWD), gdy pierwszy argument jest liczbą ujemna.
*	Wersja z odejmowaniem nie uruchamia sie w ogole, a z operacjami modulo zwraca dzielnik ujemny.
*	W funkcji shorten po prostu dzielimy licznik i mianownik przez otrzymany wspolny dzielnik. Ale co, gdy jest on ujemny?
*	Z wejsciowych danych: -3/6 (poprawny ulamek) zrobi 1/-2 (niespelniajacy zalozen is_correct) i bedzie losowal kolejne liczby...
*	...mimo tego, ze na wejsciu byly dobre dane. W koncu wylosowane zostana liczby spelniajace test i bedzie to niezauwazone.
*	Trzeba wiec dzielic przez modul z NWD - mozna to zrobic w funkcji shorten, mozna w funkcji gcd.
*
*	Przepraszam, ze sie rozpisalem, ale swiadomosc, ze cos nie do konca jest dobrze, ale olac to bo przechodzi testy, srednio mnie satysfakcjonuje :)
*/
