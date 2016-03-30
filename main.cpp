#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>
int gcd (int a, int b);

struct fraction
{

	int nominator, denominator;

	bool is_correct()
	{
	return (denominator!=0 && abs(nominator)<abs(denominator)? true : false);//wartosc bezwzgledna, by pozbyc sie przypadku gdy mamy np. -9/-1
	}
	
	void shorten()
	{
	int GCD=gcd(nominator,denominator);
	nominator=nominator/GCD;
	denominator=denominator/GCD;
	//kosmetyka
	if (denominator<0)
	{
	nominator*=(-1);
	denominator*=(-1);
	}

	}

};

int main(int argc, char **argv)
{
int n;
n=atoi(argv[1]);
fraction *fractions= new fraction[n];
srand(time(NULL));
	for (int i=0;i<n;i++)
	{
		do
		{
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;
		}
		while (fractions[i].is_correct()==false);
	//assert(fractions[i].is_correct());
	}
	//przed skracaniem
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	printf("\n");
	//po skroceniu i kosmetyce
		for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		{	fractions[i].shorten();
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	}
	
}

int gcd (int a, int b)
{
    int c;
 
  while(b!=0)
    {
    c = b;
    b = a%b;
    a = c;  
    }
 
    return a;
}