#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct fraction{
    bool is_correct();
    void shorten();
    int nominator;
    int denominator;
};

int gcd(int a, int b);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    fraction *fractions;
    int i_m(0);
    while(argc > 1 && ++i_m < argc)
    {
        int n = atoi(argv[i_m]);
        fractions = new fraction[n];
        for(int i(0); i < n; i++)
        {
            do{
                fractions[i].nominator   = rand() % 19 - 9;
                fractions[i].denominator = rand() % 19 - 9;
            }   while(!fractions[i].is_correct());
            fractions[i].shorten();
        }

        for(int i(0); i < n; i++)
            assert(fractions[i].is_correct());

        for (int i(0); i < n; assert(fractions[i++].is_correct()))
            printf("[%i] %2i / %2i\n",
                i,
                fractions[i].nominator,
                fractions[i].denominator);
    }
    delete[] fractions;
    return 0;
}

bool fraction::is_correct(){
    return (denominator == 0) ? false :
        ((abs(nominator) > abs(denominator)) ? false : true);
};

void fraction::shorten(){
    int t = gcd(nominator, denominator);
    if((nominator < 0 && denominator < 0) || (nominator > 0 && denominator < 0))
    {
        nominator   *= -1;
        denominator *= -1;
    }
    nominator   /= t;
    denominator /= t;
    return;
}

int gcd(int a, int b){
    int tmp;
    while(b != 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
