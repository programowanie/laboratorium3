#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

struct fraction
{
    int x,y;
    bool iscorrect();
};

bool fraction::iscorrect()
{
    return((y!=0)&&(abs(x)<abs(y)))?1:0 ;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    fraction *fract = new fraction [n];
    srand (time(NULL));
    for(int i=0;i<n;assert(fract[i++].iscorrect()))
    {
        do
        {
            fract[i].x=rand()%19-9;
            fract[i].y=rand()%19-9;

        }while(fract[i].iscorrect()==0);
                    cout<<fract[i].x<<endl<<fract[i].y<<endl;
    }
    delete [] fract;

}
