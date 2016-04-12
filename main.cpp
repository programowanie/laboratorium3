#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int gcd (int a, int b);

struct fraction
{
	int nominator;
	int denominator;
	
	bool is_correct()
	{
		bool z =( (abs(denominator)>abs(nominator) && denominator!=0) ?  true: false);
		
		return z;
	}

	void shroten()
	{
		int NWD;
		NWD = gcd (nominator,denominator);
		
		if(nominator!=0)	
		{
	  		    
			nominator=nominator/NWD;
			denominator=denominator/NWD;
		
		}
	}

};

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	
	fraction *fractions = new fraction[n];
	
	srand (time(NULL));

	
	for(int i=0; i<n; i++)
	{

		do
		{
			fractions[i].nominator = ((rand()%19)+(-9)); 
			fractions[i].denominator = ((rand()%19)+(-9));
		}while(fractions[i].is_correct()==0);
		
				
				fractions[i].shroten();	
	}
	printf("\n");	
	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n", 
			i+1, 
			fractions[i].nominator, 
			fractions[i].denominator);
	delete[] fractions;
	
	return 0;
}

int gcd (int a, int b)
{
	if(a!=0 && b!=0)
	{
		if (a<0)	
		{
			a=a*(-1);
		}
		if(b<0)
		{
			b=b*(-1);	
        }		
		while(a!=b)          
		{
			if (a<b)
			{
				b=b-a;	
			} 
			else 
			{
				a=a-b; 
			}              
    	}
	}
    return a; 
}