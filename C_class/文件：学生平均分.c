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
main()
{
  int n,i,j,sum=0;
  STU stu[N];
  FILE *fp;
  printf("请输入学生人数：\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      printf("请输入学生信息\n");
       scanf("%ld",&stu[i].id);
       scanf("%s",stu[i].studentName);
       for(j=0;j<4;j++)
       {

           scanf(" %d",&stu[i].score[j]);
            sum+=stu[i].score[j];
       }
       stu[i].aver = sum/4.0;
       printf("你好\n");

   }
    if((fp = fopen("D:\\score.txt","w") == NULL))
     {
         printf("error\n");
         exit(0);
     }
     for(i=0;i<n;i++)
        {
            printf("%d\t%d\n",n,m);
            printf("%10ld%8s",stu[i].id,stu[i].studentName);
            for(j=0;j<4;j++)
            {
                fprintf("%5d",stu[i].score[j]);
            }
            printf("&%6.1f\n",stu[i].aver)

        }

        return 0;
}
