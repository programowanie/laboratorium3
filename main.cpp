#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;

	bool is_correct();
	void shorten();
};

int main(int argc, char **argv)
{
	fraction *fractions;

	if (argc == 2)
	{
		int n = atoi(argv[1]);
		fractions = new fraction [n];

		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
		    do
            {
                fractions[i].nominator = (rand() % 19) - 9;
                fractions[i].denominator = (rand() % 19) - 9;
            } while (!fractions[i].is_correct());

            fractions[i].shorten();
		}

		for (int i = 0; i < n; assert(fractions[i++].is_correct()))
			printf("[%i] %2i / %2i\n",
				i,
				fractions[i].nominator,
				fractions[i].denominator);

        delete [] fractions;
	}

	fractions = NULL;
}

int gcd(int a, int b)
{
    int c;

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

bool fraction::is_correct()
{
    return ((denominator != 0 && abs(nominator) < abs(denominator)) ? true : false);
}

void fraction::shorten()
{
    int divider = gcd(nominator, denominator);

    nominator /= divider;
    denominator /= divider;
}
