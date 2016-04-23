#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

using namespace std;

struct fraction
{
  int nominator;
  int denominator;
  bool is_correct()
  {
      bool value=true;
      (abs(nominator)>abs(denominator)) ? (value=false) : ((denominator==0)?(value=false):(value=true));
      return value;
  }
  void gcd()
  {
      int lap;
      do
      {
        lap=0;
        for (int i=2;i<10;i++)
        {
        //printf("%d \n",lap);
        if(denominator%i==0 && nominator%i==0) {denominator=denominator/i; nominator=nominator/i; break;} else lap++;
        }
      } while(lap!=8);
      if(denominator<0 && nominator<0) {nominator=abs(nominator); denominator=abs(denominator);}
      if(denominator<0) {denominator=abs(denominator); nominator=nominator*(-1);}
  }
};




int main(int argc, char** argv)
{
    srand(time(NULL));
    fraction *fractions;
    int i;
    int n=atoi(argv[1]);
    fractions=new fraction[n];
    for(i=0;i<n;i++)
    {
        do
        {
        fractions[i].nominator = rand()%19-9;
		fractions[i].denominator = rand()%19-9;
        } while ((fractions[i].is_correct())==false);
    }

    for(i=0;i<n;i++)
    {
        assert(fractions[i].is_correct());
        printf("PRZED %d / %d \n",fractions[i].nominator,fractions[i].denominator);
        fractions[i].gcd();
        printf("PO %d / %d \n\n",fractions[i].nominator,fractions[i].denominator);
    }

    return 0;
}


