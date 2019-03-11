#include <stdio.h>//定义四个方向函数和地图函数
#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>
#define L 6
#define R 11
char map[L][R]=
{
    "**********",//0
    "***     **",//1
    "***     **",//2
    "**AX  * **",//3
    "***  **   ",//4
    "*****    *",//5

};
char dirction();
void showmap();
void moveup();
void movedown();
void moveleft();
void moveright();//定义全局变量int要在函数之后
int cpl=3;
int cpr=2;
int cbl=3;
int cbr=3;
int main()
{
    char dir;
    int flag = 1;
    while(flag==1)
        {
            showmap();
            dir = dirction();
        switch(dir)
    {
    case 'w':
        moveup();
        break;
    case 's':
        movedown();
    break;
    case 'a':
        moveleft();//忘记加break
        break;
    case 'd':
        moveright();
        break;
    case 'q':
        printf("low^_^!\n");
        flag = 0;
        break;
    }
    showmap();
    if(cbl== 4&&cbr== 9)
    {
        printf("high!\n");
        flag = 0;
    }
    }
}
void showmap()
{
    int i;
    for(i = 0;i < L; i++){
        printf("%s\n",map[i]);
    }
    printf("\n\n\n\n\n");
    printf("W:move up,A:move left,S:move down,D:move right");
    printf("\n\n\n\n\n");
}
void moveup()
{
   int npl,npr,nbl,nbr,i;
    npl= cpl-1;
    npr= cpr;
    nbl= cbl-1;
    nbr= cbr;
    if(map[npl][npr]==' ')
    {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
         cpl=npl;
         cpr=npr;
    }
    if(map[npl][npr]== '*')
    {

    }
    if(map[npl][npr] == 'X')
    {
        if(map[nbl][nbr] == ' ')
        {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
        map[nbl][nbr]='X';
        cpl=npl;
        cpr=npr;
        cbl=nbl;
        cbr=nbr;
        }
    }
}
void moveleft()
{
    int npl,npr,nbl,nbr,i;
    npl= cpl;
    npr= cpr-1;//向左移动，横坐标减去一，即列数减去一
    nbl= cbl;
    nbr= cbr-1;
    if(map[npl][npr]==' ')
    {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
         cpl=npl;
         cpr=npr;
    }
    if(map[npl][npr]== '*')
    {

    }
    if(map[npl][npr] == 'X')
    {
        if(map[nbl][nbr] == ' ')
        {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
        map[nbl][nbr]='X';
        cpl=npl;
        cpr=npr;
        cbl=nbl;
        cbr=nbr;
        }
    }
}
void movedown()
{
    int npl,npr,nbl,nbr,i;
    npl= cpl+1;
    npr= cpr;
    nbl= cbl+1;
    nbr= cbr;
    if(map[npl][npr]==' ')
    {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
         cpl=npl;
         cpr=npr;
    }
    if(map[npl][npr]== '*')
    {

    }
    if(map[npl][npr] == 'X')
    {
        if(map[nbl][nbr] == ' ')
        {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
        map[nbl][nbr]='X';
        cpl=npl;
        cpr=npr;
        cbl=nbl;
        cbr=nbr;
        }
}}
void moveright()
{
   int npl,npr,nbl,nbr,i;
    npl= cpl;
    npr= cpr+1;
    nbl= cbl;
    nbr= cbr+1;
    if(map[npl][npr]==' ')
    {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
         cpl=npl;
         cpr=npr;
    }
    if(map[npl][npr]== '*')
    {

    }
    if(map[npl][npr] == 'X')
    {
        if(map[nbl][nbr] == ' ')
        {
        map[cpl][cpr]= ' ';
        map[npl][npr]= 'A';
        map[nbl][nbr]='X';
        cpl=npl;
        cpr=npr;
        cbl=nbl;
        cbr=nbr;
        }
    }
}
char dirction()
{
    rewind(stdin);
    char ch;
    ch =getch();
    return ch;
}
