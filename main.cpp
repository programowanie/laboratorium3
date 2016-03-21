#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

struct fraction;
int gcd (int a, int b);  //szuka najwiekszego wspolnego dzielnika, algorytm Euklidesa
fraction* createFraction(int n); //alokuje i wypelnia tablice ulamkow
void drawFraction (fraction* fractions, int n);  //wypisuje ulamki
void storageFree(fraction* fractions); //zwalnia pamiec
void fErr1(); //gdy nie znaleziono argumentow

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		bool ic;
		int abs_denom, abs_nom;  //wartosci bezwzgledne

		denominator<0?abs_denom=-denominator:abs_denom=denominator;
		nominator<0?abs_nom=-nominator:abs_nom=nominator;

		abs_denom!=0?abs_nom<abs_denom?ic=1:ic=0:ic=0;
		return ic;
	};

	void shorten()
	{
		int divider=gcd(nominator, denominator);
		nominator=nominator/divider;
		denominator=denominator/divider;
	}

	void sign_corrector()  //funkcja ta wyciaga minus przed caly ulamek lub usuwa go gdy obie czesci ulamka sa ujemne
	{
		if (nominator>=0 && denominator<0) {nominator+=-1; denominator*=-1;}
		if (nominator<0 && denominator<0) {nominator*=-1; denominator*=-1;}
	}
};

int main(int argc, char **argv)
{
	fraction *fractions;
	int n;

	if (argc==1) fErr1();

	srand(time(0));
	if (argc==2)
	{
		n=atoi(argv[1]);

		fractions=createFraction(n);

		drawFraction(fractions, n);
	
		for (int i=0; i<n; gcd(fractions[i].nominator, fractions[i++].denominator));
	}
}

int gcd (int a, int b)
{
	int mod;  //reszta z dzielenia

	do
	{
		mod=a%b;
		a=b;
		b=mod;
	}
	while (mod!=0);

	if (a<0) a*=-1;
	return a;
}

fraction* createFraction(int n)
{

	fraction* fractions=new fraction [n];

	for(int i=0; i<n; i++)
	{
		do
		{
			fractions[i].nominator=-9+rand()%19;
			fractions[i].denominator=-9+rand()%19;
		}
		while (fractions[i].is_correct()==0);
	};

	return fractions;

}

void drawFraction (fraction *fractions, int n)
{
	printf("\n");
	for (int i=0; i<n; assert(fractions[i++].is_correct()))
		{
			fractions[i].sign_corrector();
			printf("[%i] %2i / %i             nwd:%2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator,
			gcd(fractions[i].nominator,fractions[i].denominator));
		}
	printf("\nPo skroceniu: \n\n");
	for (int i=0; i<n; i++)
	{
		fractions[i].shorten();
		printf("[%i] %2i / %i \n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}	
	storageFree(fractions);


}

void storageFree(fraction* fractions)
{
	delete[] fractions;
}

void fErr1()
{
	printf("ERROR: Nie podano argumentow do programu!\n");
}