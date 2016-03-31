#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
/* aby program rozpatrywał liczby jako poprawne ułamki dodałem funkcję "moduł" zwracającą
wartość bezwzględną argumentu. */

int gcd (int a, int b)
{
	int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int modul(int a) //funkcja dodatkowa do skracania ułamków.
{
	if (a<0) return -a;
	else return a;
}


struct fraction
{
	int nominator,denominator;
	bool is_correct()
	{
		return((denominator&&modul(nominator)<denominator)? true : false); 
		/*warunek MODUŁ dodałem aby program
		 "poprawnie" rozpatrywał te liczby jako ułamek i nie akceptował np. -9/2 */
	}
	void shorten()
	{	
			int a= gcd(modul(nominator),modul(denominator)); //MODUŁ aby algorytm euklidesa działał poprawnie
			nominator/=a;
			denominator/=a;
	};
};

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n=atoi(argv[1]);
	fraction *fractions =new fraction[n];
	
	for(int i=0; i<n; i++)
	{
		do{
		fractions[i].nominator=(rand()%19-9);
		fractions[i].denominator=(rand()%19-9);
		
		}while((fractions[i].is_correct())==0);	
		fractions[i].shorten();
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
	{printf("[%i] %2i / %2i\n", 
		i, 
		fractions[i].nominator, 
		fractions[i].denominator);
	}
}