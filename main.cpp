#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <cmath> //uzycie biblioteki wyjasnione dalej

int gcd (int a, int b)
{
	int temp;
	do
	{
		temp=a%b;
		a=b;
		b=temp;
	} while (temp!=0);
	if (a<0) a*=-1;
	return a;
};

struct fraction
{
	int nominator, denominator;
	bool is_correct()
	{
		/* wykorzystuje funkcje abs() z cmath, aby nie doszlo do sytuacji,
		w ktorej na przyklad ulamek "-7/3" jest uznaany za prawidlowy,
		bo -7<3 (w tym przypadku jest to bzdura, bo ulamek bedzie ujemny,
		ale bedzie mial czesc calkowita [-2,3333...]) */
		return (denominator&&(abs(nominator)<abs(denominator)))?1:0;
		/* w sumie przydaloby sie tez, zeby licznik nie byl zerem, ale nie bylo to
		wyszczegolnione w tresci zadania, wiec nie implementowalem tego pomyslu :P */
	}
	void shorten()
	{
		int divisor = gcd(nominator,denominator);
		nominator /= divisor;
		denominator /= divisor;
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
			fractions[i].nominator = rand()%19-9;
			fractions[i].denominator = rand()%19-9;
		} while ((fractions[i].is_correct()) == 0);
		fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}