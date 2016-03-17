#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>

int gcd (int a, int b);

struct fraction {
int nominator;
int denominator;
fraction shorten(){
	fraction s;
	if(nominator==0){
		s.nominator=nominator;
		s.denominator=1;
	}
	
	
	else{
		s.nominator=nominator/gcd(nominator,denominator);
		s.denominator=denominator/gcd(nominator,denominator);
	}
	
return s;	
}
bool is_correct(){
return denominator && abs(nominator)<=abs(denominator) ? true:false;
}
};


int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions = new fraction[atoi(argv[1])];
	for(int i=0;i<atoi(argv[1]);i++){
		fractions[i].nominator=rand()%19-9;
		fractions[i].denominator=rand()%19-9;
		do{
			/*if(fractions[i].is_correct()==false)*/
				fractions[i].nominator=rand()%19-9;
				fractions[i].denominator=rand()%19-9;
		}while(fractions[i].is_correct()==false); 
	}
	
	for (int i = 0; i < atoi(argv[1]);assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i, 
			fractions[i].nominator, 
			fractions[i].denominator);

delete []fractions ;
}

int gcd(int a, int b){
	  if(b!=0)
      return gcd(b,a%b);
 
    return a;
}