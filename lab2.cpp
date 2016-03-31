#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cassert>

struct fraction
{
	int licznik, mianownik;

	bool is_correct (int licznik, int mianownik)
	{
		bool kappa;
		(mianownik == 0) ? (kappa = false) : (licznik > mianownik) ? (kappa = false) : (kappa = true);
		return kappa;
	}

	int gcd (const int licznik, const int mianownik)
	{
		int a = licznik, b = mianownik;
		if (a != 0)
		{
			if (a < 0) a = -a;
			if (b < 0) b = -b;

			while (a != b)
			{
				if (a < b) b = b - a;
				else a = a - b;
			}
			return a;
		}
		else return 1;
	}
	void shorten (int licznik, int mianownik)
	{
		std::cout << "Kontrolne wyswietlenie skroconego ulamka: " << licznik/gcd(licznik, mianownik) << "/" << mianownik/gcd(licznik, mianownik) << "\n";
	}
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = atoi (argv[1]);
	fraction *string;
	string = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		string[i].licznik = rand() % 19 - 9;
		do
		{
			string[i].mianownik = rand() % 19 - 9;
		} while (!string[i].is_correct(string[i].licznik, string[i].mianownik));
		std::cout << "Kontrolne wyswietlenie ulamka: " << string[i].licznik << "/" << string[i].mianownik << "\n";
		assert (string[i].is_correct(string[i].licznik, string[i].mianownik));
		string[i].shorten(string[i].licznik, string[i].mianownik);
	}
	delete[] string;
	return 0;
}
