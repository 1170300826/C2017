#include <stdio.h>
#include <math.h>
#define N 40
#define initSize 100
typedef int DataType;
typedef struct {
     DataType *data;
     int maxSize,n;
}SeqList;
void initList(SeqList& L)
{
    L.data = new DataType[initSize];
    if(!L.data)
    {
        printf("´æ´¢·ÖÅä´íÎó£¡\n");
        exit(0);
    }
    L.maxSize = initSize;
    L.n = 0;
}
void clearList(SeqList& L)
{
    L.n =0;
}
void Length(SeqList& L)
{
    return L.n;
}
int isEmpty(SeqList& L)
{
    return(L.n == 0)?1:0;
}
int Search(SeqList& L,DataType x)
{
    for(i=1;i<=L.n;i++)
    {
        if(L.data[i-1] == x)
        {
            return i;
        }
    }
}
int Locate(SeqList& L,int i)
{
    if(i>=1&&i<=L.n)
        return i;
    else return 0;
}
void copy(SeqList& L1,SeqList& L2)
{
    int i;
    L1.maxSize = L2.maxSize;
    L1.n = L2.n;
    if(!L1.data){
        L1.data = new DataType[L1.maxSize];
        if(!L1.data)
        {
            printf("存储错误！\n");
            exit(1);
        }
    }
    for(i=1;i<=n;i++)
    {
        L1.data[i-1]=L2.data[i-1];
    }
}
int Insert(SeqList& L1,int i,DataType& x)
{
    int j,m;
    if(1<=i &&  i<=n)
    {

    for(j=i;j<=n+1;j++)
    {
        L1.data[j] = L1.data[j-1];
    }
    L1.data[i-1] = x;
    }


    if(L.n == L.maxSize)
        return 0;
    else
    return 0;
}
int Remove(SeqList& L1,int i,DataType& x)
{
    int j;
    if(!L.n)
        return 0;
    if(i<=n&&i>=1)
    {
        for(j=i;j<=n;j++)
    {
         L1.data[j-1] = L1.data[j];
    }
    }
    else
        return 0;
}
typedef int DataType;
typedef struct node
{
    DataType data;
    struct node* link;
}LinkNode,*LinkList;
int main()
{
    int i,j,n;
    int a[N];
    n = 6;
    a[0]=0;
    a[1]=1;
    for(i=2;i<=n;i++)
    {
        a[n] = a[0] + a[1];
        a[0] = a[1];
        a[i] = a[n];
    }
    printf("%d\n",a[n]);
}


