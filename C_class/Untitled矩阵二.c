#include <stdio.h>
#include <limits.h>
#define del _I32_MIN
int Fact(int n)
{
    if(n<=0)
    {
        return 1;
    }
    else
    return n*Fact(n-1);
}
main ()
{
    int j;
    j=Fact(9);
   printf("%d\n",j);
}
void Remove(int a[],int n)
{
    int i,j,k=0;
    int b[n];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] == a[j])
            {

                        a[j]=del;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i] != del)
        {
            if(i!=k)
            {a[k] = a[i];
            k++;}

        }
    }
    n=k;
}
