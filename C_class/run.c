#include <stdio.h>
#include <string.h>
int IS_win(int a[][3])//�ж��Ƿ��ʤ
{
    if(a[0][0] == a[0][1]&&a[if(a[0][2] == 1)
          return 1;//Aliceʤ��
        else:
            return 2;//Bobʤ��
    else if(a[1][0] == a[1][1]&&a[1][1]==a[1][2])
        if(a[0][2] == 1)
          return 1;//Aliceʤ��
        else:
            return 2;//Bobʤ��
    else if(a[2][0] == a[2][1]&&a[2][1]==a[2][2])
        if(a[0][2] == 1)
          return 1;//Aliceʤ��
        else:
            return 2;//Bobʤ��
    else if(a[0][0] == a[1][1]&&a[1][1]==a[2][2])
        if(a[0][2] == 1)
          return 1;//Aliceʤ��
        else:
            return 2;//Bobʤ��
    else if(a[0][2] == a[1][1]&&a[1][1]==a[2][0])
        if(a[0][2] == 1)
          return 1;//Aliceʤ��
        else:
            return 2;//Bobʤ��
    else:
        return 0;

}
int Caculate_score()//�������
{

}
int main()
{
	int T,i;
	i = 0;
	scanf("%d",&T);
	do{
       for(j=0;j<3;j++)
            {
              scanf(" %d",&a[i][j]);
            }
       i++;
       score[i] = Caculate_score();
    }while(IS_win(a[i][3]));//ֱ��������ֻ�ʤ��
    for(i=0;i<3;i++)
    {
        printf("%d/n",score[i]);
    }

}
