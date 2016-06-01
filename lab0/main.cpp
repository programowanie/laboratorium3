#include <iostream>
#include <cstdlib>
using namespace std;
int main (int argc,char *argv[])
{
    unsigned long long k=atoi(argv[1]);
    if(*argv[2]==102)
    {
        int *t=new int[k];
        t[0]=1, t[1]=1;
        for(int i=2;i<k;i++)
            t[i]=t[i-1]+t[i-2];
            cout<<k<<" wyraz ciagu fib wynosi : " << t[k-1];
        delete [] t;
    }
        else
            cout<<k<<" wyraz ciagu 3n dla n>0 wynosi : " << 3*k;


    return 0;
}
