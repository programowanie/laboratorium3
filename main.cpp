/*Weronika Borek, 226327, program generuje losowe ułamki, wybiera spośród nich wskazaną przez 
użytkownika ilość ułamków prawidłowych, skraca je, jeśli jest taka możliwość, oraz wyświetla 
w wierszu poleceń. Przykład wywołania:
./a.out 10 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

int gcd (int a, int b);

/*Struktura zawierająca licznik oraz mianownik. Zawiera też prototypy funkcji is_correct oraz shorten.*/
struct fraction 
{
	int numerator;
	int denominator;
	bool is_correct();
	void shorten ();
}; 

/*Funkcja zawiera kontrolę błędów oraz funkcję generującą tablicę losowych ułamków za pomocą stuktury fraction. 
Kontroluje poprawność za pomocą funkcji assert. Następnie wyświetla ułamki w wierszu poleceń.*/
int main (int argc, char *argv[])
{
	if (argc!=2)
	{
		printf ("Nieprawidłowa ilosc argumentów wiersza poleceń.\n");
		return 0;
	}
	int how_many=atoi(argv[1]);
	fraction *fractions=(fraction*)malloc(how_many*(sizeof(fraction)));
	srand (time(NULL));
	int n=0;
	do 
	{
		fractions[n].numerator=rand()%19-9;
		fractions[n].denominator=rand()%19-9; 
		if (fractions[n].is_correct())
		{
			fractions[n].shorten();
			n++;
		}
	}
	while (n<how_many);
	for (n=0; n<how_many; assert(fractions[n++].is_correct()))
		printf ("[%d] %d/%d \n", n, fractions[n].numerator, fractions[n].denominator);
	free (fractions);
	return 0;
}

/*Funkcja służy do wynajdowania największego wspólnego dzielnika dwóch liczb całkowitych.*/
int gcd (int a, int b)
{
	int d;
	for (int c=1; c<=abs(a) && c<=abs(b); c++)
		if (a%c==0 && b%c==0)
			d=c;
	return d;
}

/*Funkcja służy do wybierania spośród wygenerowanych ułamków jedynie ułamków prawidłowych.*/
bool fraction::is_correct()
{
	bool correct;
	correct=(denominator!=0 && numerator!=0 && abs(numerator)<abs(denominator))?true:false;
	return correct;
}

/*Funkcja służy do skracania wygenerowanych ułamków.*/
void fraction::shorten()
{
	int d=gcd(numerator, denominator);
	numerator=numerator/d;
	denominator=denominator/d;
}
