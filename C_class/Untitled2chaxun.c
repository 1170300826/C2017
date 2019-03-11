#include <stdio.h>
#include <stdlib.h>
#define N 30
typedef struct student
{
    long id;
    char studentName[N];
    int score[4];
    float aver;
}STU;
void SearchinFile(char fileName[],long k);
main ()
{
    long k;
    char ch;
    FILE *fp;
    printf("请输入要查询的记录数：");
    scanf("%ld",&k);
    SearchinFile("D:\\student.txt",k);
    return 0;
}
void SearchinFile(char fileName[],long k)
{
    int i;
    FILE *fp;
    STU stu;
    if((fp = fopen("D:\\student.txt","r")) ==NULL)
    {
        printf("Error!\n");
        exit(0);
    }
    printf("record number =%d\n",ftell(fp)/sizeof(STU)+1);
    fseek(fp,(k-1)*sizeof(STU),SEEK_SET);
    fread(&stu,sizeof(STU),1,fp);
    printf("%10ld%8s",stu.id,stu.studentName);
    for(i=0;i<4;i++)
    {printf("%4d",stu.score[i]);}
    printf("%6.1f\n",stu.aver);
    printf("record number =%d\n",ftell(fp)/sizeof(STU)+1);
    fclose(fp);
}



