#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	bool is_correct() //Funkcja zwraca true jeśli licznik, mianownik są prawidłowe
	{
		return (denominator != 0 && abs(nominator) < abs(denominator) ? true : false);
	}
	void shorten()
	{
	nominator = nominator/gcd(nominator,denominator);
	denominator = denominator/gcd(nominator,denominator);
	}	
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n;

	if(argc > 1) //Upewnijmy się, że mamy odpowiedni argument
		n = atoi(argv[1]); //Konwertujemy argument na odpowiedniego inta

	fractions = new fraction[n];
	for(int i=0;i<n;i++)
		{
			do
			{
				fractions[i].nominator = rand()% 19 - 9;
				fractions[i].denominator = rand()% 19 - 9;
			} while (!fractions[i].is_correct());

			shorten(fractions[i].nominator, fractions[i].denominator);
		} 


	for (int i=0;i<n;assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

}

int gcd(int a, int b)
{
	do
	{
		if(a>b)
			a -= b;
		else
			b -= a;
	} while(a != b);

	return a;
}