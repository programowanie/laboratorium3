#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//int gcd (int a, int b);

struct fraction
{
int licznik;
int mianownik;

bool is_correct()
    {
    int prawda_czy_falsz;
    prawda_czy_falsz=(licznik<mianownik && mianownik!=0) ? 1:0;

    return prawda_czy_falsz;
    }
};

int main(int argc, char **argv)
{

    int n;

	 if (argc >= 2)
  {
    n = atoi(argv[1]);
  }
  else
  {
    cout << "Podaj liczbe calkowita n: ";
    cin >> n;
  }

    fraction *fractions = new fraction[n];
    srand( time( NULL ) );

    for(int i=0; i<n; i++)
    {
    fractions[i].licznik= rand()%19 - 9;
    fractions[i].mianownik= rand()%19 - 9;
    }
	/*
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n",
			i,
			fractions[i].nominator,
			fractions[i].denominator);
	*/

	delete []fractions;
}
