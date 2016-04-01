#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <time.h>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);      
}

struct fraction { 
	int num;    
	int denom;
	bool is_correct(){
		return denom!=0 && num<denom ? true : false;
	}

	void shorten(){
		int g=gcd(abs(num), abs(denom)); 
		num/=g;
		denom/=g;
	}

	
};


int main(int argc, char **argv)
{
	srand(time(NULL));
	fraction *fractions;
	int n = atoi(argv[1]);
	fractions = new fraction[n];

	for(int i=0; i<n;i++){
		do{
			fractions[i].num = rand()% 19 - 9;
			fractions[i].denom = rand()% 19 - 9;    
		}
		while(!fractions[i].is_correct());
	}

	for (int i = 0; i < n; assert(fractions[i++].is_correct())){
		fractions[i].shorten();
		printf("[%i] %2i / %2i \n", 
			i, 
			fractions[i].num, 
			fractions[i].denom);
	}

	delete fractions;
}
