#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int gcd (int a, int b)
{	
	int i;
	for(i=9; i>0; i--)
	{	

		if(abs(a)%i==0 && abs(b)%i==0)
		{	
			return i;
			break;
		}
	
	}	
};

struct fraction
{
	int licznik;
	int mianownik;
	bool is_correct();
	void shorten();
};

bool fraction::is_correct()
{	
	bool a;
	mianownik!=0 ? a=true : a=false;
	a == true ? (abs(mianownik)>=abs(licznik) ? a=true : a=false ): a=false;
	return a;

};

void fraction::shorten()
{	
	if (licznik!=0)
		{
			int i = gcd(licznik, mianownik);
			licznik = licznik/i;
			mianownik = mianownik/i;
		}
};


int main(int argc, char **argv)
{
	srand (time(NULL));
	int n = atoi(argv[1]);
	fraction fractions[n];
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		{	
			do {
			fractions[i].licznik = rand() % 19 +1 -10;
			fractions[i].mianownik = rand() % 19 +1 -10;
			}
			while(fractions[i].is_correct() == false);
			printf("[%i] %2i / %2i %i \n", 
			i, 
			fractions[i].licznik,
			fractions[i].mianownik,
			fractions[i].is_correct()
			);
		};
	cout << "Czy chcesz skrocic wszystkie ulamki? y/n";
	char m;
	cin >> m;
	if(m=='y')
		for(int i=0; i<n; i++)
			{
			fractions[i].shorten();
			printf("[%i] %2i / %2i \n", 
				i, 
				fractions[i].licznik,
				fractions[i].mianownik
				);

			}
}

