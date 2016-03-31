#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
int gcd (int a, int b)
{
    if(a == 0 || b == 0)
        return(1);
    if(a < 0)
        a = a * (-1);
    if(b < 0)
        b = b * (-1);
    int pom;
    while(a-b != 0)
    {
        pom = a;
        if(a<b)
        {
            a = b;
            b = pom;
        }
        a = a - b;
    }
    return (a);
}
int bez (int a)
{
    if(a > 0)
        return a;
    return (a * (-1));
}
struct fraction
{
    int licznik;
    int mianownik;
    bool is_correct()
    {
        return (mianownik != 0 && bez(licznik) < bez(mianownik) ? 1:NULL);
    }
    void shorten()
    {
        int p = gcd(licznik,mianownik);
        licznik = licznik / p;
        mianownik = mianownik / p;
    }
};

int main(int argc, char **argv)
{
	fraction *fractions;
    int n = atoi(argv[1]);
    fractions = new fraction[n];
    srand(time(NULL));
    for(int i = 0;i < n;i++)
    {
        do
        {
            fractions[i].licznik = rand()%19 - 9;
            fractions[i].mianownik = rand()%19 - 9;
        }
        while(fractions[i].is_correct() != 1);
        fractions[i].shorten();
    }
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n",
			i,
			fractions[i].licznik,
			fractions[i].mianownik);
}
