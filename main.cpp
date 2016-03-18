#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b); //Wylicza największy wspólny dzielnik dwóch liczb

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
		int nwd = gcd(nominator,denominator);
		nominator = nominator/nwd;
		denominator = denominator/nwd;
	}	
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n;

	if(argc > 1) //Upewnijmy się, że mamy odpowiedni argument
		n = atoi(argv[1]); //Konwertujemy argument na odpowiedniego inta
	else //Dajmy feedback, jeśli brakuje argumentu
	{
		printf("Brak odpowiedniego argumentu!\n");
		return -1;
	}

	//Tworzymy i wypełniamy ułamki w ilości n
	fractions = new fraction[n]; 
	for(int i=0;i<n;i++)
		{
			do
			{
				fractions[i].nominator = rand()% 19 - 9;
				fractions[i].denominator = rand()% 19 - 9;
			} while (!fractions[i].is_correct()); //W ten sposób wszystkie ułamki będą spełniały warunki

			fractions[i].shorten(); //Skracamy ułamki
		} 


	for (int i=0;i<n;assert(fractions[i++].is_correct())) //Wypisujemy ułamki z odpowiednią składnią
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

}

int gcd(int a, int b)
{
	int pom;
 
    while(b!=0)
    {
    	pom = b;
    	b = a%b;
    	a = pom;  
    }

	return a;
}