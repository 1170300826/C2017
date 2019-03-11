#include <stdio.h>
#include <string.h>
//判断是否连续得分以及返回增分值
int ISmiddle(int a1,int a0,int flag)
{
    int addscore = -1;
	if(a1==2)
        if(flag == 1)
			addscore = a0 + 2;
		else
		    addscore = 2;
	else if(a1 == 1)
		addscore = 1;
	else if(a1 == 0)
		addscore = -1;
	return addscore;
}
int main()
{
	int a[10],i;
	int score = 0,get_score = 0,flag = 0;
	int addscore;
	for(i=0;i<10;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<10;i++)
	{
	    addscore = ISmiddle(a[i],get_score,flag);
		if( addscore == -1)
			break;
		else if(addscore >= 1)
		    score  += addscore;
			if(addscore >= 2)
			   flag = 1;
            else
                flag = 0;
            get_score = addscore;
	}
	printf("%d\n",score);
}
