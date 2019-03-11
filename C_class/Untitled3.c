#include <stdio.h>
#include <stdlib.h>
#define N 30
typedef struct student
{
    long id;
    char studentName[10];
    int score[4];
    float aver;
}STU;
void input(STU stu[],int n,int m)
{
    int i,j,sum;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&stu[i].id);
        scanf("%s",stu[i].studentName);
        for(j=0;j<m;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }

    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum+=stu[i].score[j];
        }
        stu[i].aver=(float)sum/m;
    }
}
void InputtoFile(STU stu[],int n)
{
    int i,j;
    FILE *fp;
    if((fp = fopen("D:\\student.txt","w")) == NULL)
    {
        printf("error\n");
        exit(0);
    }
    fwrite(stu,sizeof(STU),n,fp);
            fclose(fp);
}
int ReadtoFile1(STU stu[])
{
    int i,j;
    FILE *fp;
    if((fp = fopen("D:\\student.txt","r")) == NULL)
    {
        printf("error!\n");
        exit(0);
    }
     for(i =0;!feof(fp);i++)
     fread(&stu[i],sizeof(STU),1,fp);

      fclose(fp);
      printf("Total students is %d.\n",i-1);
      return i-1;
}
void PrintScore(STU stu[],int n,int m)
{

      int i,j;
      printf("%d\t%d\n",n,m);
      for(i=0;i<n;i++)
      {
       printf("%10ld",stu[i].id);
       printf("%8s",stu[i].studentName);
       for(j=0;j<4;j++)
       {

           printf(" %5d",stu[i].score[j]);

       }
       printf("%6.1f\n",stu[i].aver);
      }
}
main()
{
  int n,m,j,sum=0;
  n=2;
  m=4;
  STU stu[N];
  input(stu,n,m);
  InputtoFile(stu,2);
  n = ReadtoFile1(stu);
  PrintScore(stu,n,4);
  return 0;
}

