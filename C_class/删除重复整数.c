#include <stdio.h>
int deletemore(int A[],int n)
{
    int i,j,k=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(A[j]==A[i])
                break;
        }
        if(j>k&& ++k!=i)
        {
            A[k]=A[i];
        }
    }
}
