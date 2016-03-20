#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int gcd (int b, int a);

struct fraction
{
	int nominator, denominator;
	bool is_correct(){ 
		return (denominator!=0 and abs(nominator)<abs(denominator) ) ? true : false;
	}
	void shorten();
	


};


int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	fraction *fractions=new fraction[n];
	srand(time(NULL));
	printf("N;= %d",n);
	for(int i=0;i<n;i++){
		
		do{
			fractions[i].nominator=rand()%19-9;
			fractions[i].denominator=rand()%19-9;
		}while(!fractions[i].is_correct());
	}
	printf("\n");
	for (int i = 0; i < n; assert(fractions[i++].is_correct())){
		printf("[%2d]  %2d / %2d ", i+1, fractions[i].nominator, fractions[i].denominator);
		
		fractions[i].shorten();
		if(fractions[i].nominator)
			printf("czyli: %2d / %2d\n", fractions[i].nominator, fractions[i].denominator);
		else printf("czyli:  0\n");
	}


}
int gcd(int b, int a)
{
	int p;
	if(b!=0){
	do{
		p=a%b;
		a=b;
		b=p;
		
	}while(b != 0);
	}
	return a;
}
void fraction::shorten()
{
	int gc;
	gc=gcd(nominator,denominator);
	if(gc!=0){
		nominator/=gc;
		denominator/=gc;
	}
	if(nominator>0 and denominator<0) {
		nominator/=-1;
		denominator/=-1;	
	}
}
