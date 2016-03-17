#include <stdio.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);

struct fraction
{
	int nominator, denominator;
	bool is_correct(){ return (denominator!=0 and nominator>denominator) ? TRUE : FALSE}

};

int main(int argc, char **argv)
{
	int n=atoi(arv[1]);
	fraction *fractions=new fraction[n];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		
		do{
			fraction[i]=rand%19-9;
		}while(fraction::is_correct());
	}
	


	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
}