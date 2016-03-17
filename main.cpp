#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//int gcd (int a, int b);

struct fraction {
int nominator;
int denominator;
bool is_correct(){
denominator  && nominator<denominator ? true:false ;
}
};


int main(int argc, char **argv)
{
	fraction *fractions = new fraction[atoi(argv[1])];
	for(int i=0;i<atoi(argv[1]);i++){
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;
	}
	
	for (int i = 0; i < atoi(argv[1]); assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);
	
delete []fractions ;
}