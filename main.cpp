#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


struct fraction
{
	int nominator,denominator;
	bool is_correct();
	int gcd(int a,int b);
	void shorten();
};

bool fraction::is_correct()
{
	return (denominator!=0 && abs(nominator)<abs(denominator))?true:false;
}

int fraction::gcd(int a, int b)
{
	if(a==0 || b==0) return 0;
	else
	{
		while(a!=b)
		{
      		if(a>b)
           		a-=b;
        	else
           		b-=a;
   		}
    	return a;
	}
}

void fraction::shorten()
{
	int x=gcd(abs(nominator),abs(denominator));
	if(x!=0)
	{
		nominator/=x;
		denominator/=x;
	}
	if(nominator<0 && denominator<0) //jeśli licznik i mianownik są ujemne to skracam minusy
	{
		nominator=abs(nominator);
		denominator=abs(denominator);
	}
	if(nominator>=0 && denominator<0) //jeśli tylko mianownik jest ujemny to wyciągam minus przed ułamek
	{
		nominator*=-1;
		denominator=abs(denominator);
	}
}

int main(int argc, char **argv)
{
	fraction *fractions;
	int n=atoi(argv[1]);
	fractions = new fraction[n];
	srand(time(NULL));
	for (int i = 0; i < n;i++)
	{	
		do
		{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}while(!fractions[i].is_correct());
	}
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))	
		printf("[%d] %2d / %2d\n", 
			i, fractions[i].nominator, fractions[i].denominator);
	
	printf("Skracanie ułamków...\n");
	for (int i = 0; i < n; ++i)
	{
		fractions[i].shorten();
	}
	for (int i = 0; i < n;i++)
		if(fractions[i].nominator!=0) 
		printf("[%d] %2d / %d\n", 
			i, fractions[i].nominator, fractions[i].denominator);
		else printf("[%d] %4d\n", i, 0); //jeśli w ułamku jest 0 to wartość ułamka wynosi 0
	delete [] fractions;
	
}