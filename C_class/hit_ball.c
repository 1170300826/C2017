#include <stdio.h>
#define N 100
int IS_end(int a[][3])//判断游戏是否结束
{
    int i,j;
    int flag = 0;
    for (j=0;j<3;j++)
    {
       if(a[j][0] == a[j][1]&&a[j][i] ==a[j][2]  )
       {
         if(a[j][0] == 1)
            flag = 1;
            return 1;
         else if(a[j][0] == 2))
            flag = 1;
            return 2;
         break;
       }
    }
     for(i=0;i<3;i++)
    {
       if(a[0][i] == a[1][i]&&a[1][i] ==a[2][i]  )
       {
          if(a[0][i] == 1)
             flag = 1;
            return 1;
         else if(a[0][i] == 2))
             flag = 1;
            return 2;
         break;
       }
    }
    if(a[0][0] == a[1][1]&&a[1][1] ==a[2][2])
    {
        if(a[0][0] == 1)
            return 1;
         else if(a[0][0] == 2))
            return 2;
    }
    else if(a[0][2] == a[1][1]&&a[1][1] ==a[2][0])
    {
        if(a[0][2] == 1)
            return 1;
         else if(a[0][2] == 2))
            return 2;
    }
    else
    {
        if(flag == 0)
        {
            return 0;
        }
    }
}
int best_way()
{

}
int Score() //根据空格计算得分
{

}
int main()
{
   int a[3][3];
   int i,j,k,a,num;
   scanf("%d",&num);
   for(k=0;k<num;k++)
   {
       for(i=0;i<3;i++)
        for(j=0;j<3;j++)
         {
           scanf(" %d",&a[i][j]);
         }
       do
       {

       }while(IS_end(a[3][3])== 2 || 1);
       a = IS_end(a[3][3]);
       if( a== 2 )//Bob获胜
       {
           score = Score();
           printf("%d\n",&score);
       }
       else if(a)== 1)//Alice获胜
       {
           score = Score();
            printf("%d\n",&score);
       }
       else if(a== 0)//平局
       {
           printf("%d\n",a);
       }
   }
}
