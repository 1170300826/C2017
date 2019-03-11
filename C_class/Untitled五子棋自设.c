#include <stdio.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXIMUS 15
int p[MAXIMUS][MAXIMUS];
char buff[MAXIMUS*2+1][MAXIMUS*4+3];
int Cx,Cy;
int Now;
int wl,wp;
char *showText;
char *Copy(char *str1,const char *str2)
{
    char *str3=str1;
    while(*str1 != '\0')
    {
        *str2++=*str1++;
    }
    return str3;
}
void Initialize()
{
    int x,y;
    showText = "";
    count =0;
    for(i=0;i<MAXIMUS;i++)
    for(j=0;j<MAXIMUS;j++)
    {
        p[x][y]=0;
    }
    Cx=Cy=2;
    Now=1;
}
void arrangement(int i,int j)
{
    if(Now == 1&&p[i][j]==0)
    return '@';
    else if(Now ==2&&p[i][j]==0)
        return '$';

    else if(i==0&&j==0)
    return '^';

    else if(i==0&&j==MAXIMUS-1)
        return '*';
    else if(i==MAXIMUS-1&&j==0)
    return '&';
    else if(i=MAXIMUS-1&&j==MAXIMUS-1)
        return '*';
    else if(i==0)
        return '*';
    else if(j==0)
        return '&';
    else if(i==MAXIMUS-1)
        return '*';
    else if(j==MAXIMUS-1)
        return '&';
    else
        return '(';



}
main()
{
    system("title ¼òÒ×Îå×ÓÆå");
    system("mode con cols=3 lines=23");
    system("color E0");
    while(1)
    {
        RunGame();
    }
}
