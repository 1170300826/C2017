#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
int fun_Play();
int fun_Esc();
void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
int main()
{
    int i,j,k;
    int AllCounter,RightCounter,WrongCounter;
    AllCounter=RightCounter=WrongCounter=0;
    k=fun_Esc();
    system("cls");
    char kw[]="QWERTYUIOP[]";
    char ke[]="ASDFGHJKL;'";
    char kr[]="ZXCVBNM,./";
    system("cls");
    gotoxy(18,1);
    printf("%s\n",kw);
    gotoxy(20,3);
    printf("%s\n",ke);
    gotoxy(22,5);
    printf("%s\n",kr);
    gotoxy(11,25);
    for(i=0;i<60;i++)
    {
        printf("=");
    }
    gotoxy(0,1);
    printf("AllCh:%ld\nRight:%ld\nWrong:%ld",AllCounter,RightCounter,WrongCounter);
    gotoxy(10,6);
    printf("游戏规则是输入y表示进入游戏，屏幕掉落字母，输入字母加空格键若输入正确，字母变'*'");
    gotoxy(50,1);
    printf("Press Esc to exit");
    gotoxy(50,2);
    printf("Enter to pause");
    gotoxy(26,12);
    printf("*************************");
    gotoxy(26,13);
    printf("*Press any key to start!*");
    gotoxy(26,14);
    printf("*************************");


    gotoxy(51,13);
    if(getch()==27)
    {
        if(k==1)
        {
            system("cls");
            exit(0);
        }
    }
    gotoxy(23,12);
    printf(" ");
    gotoxy(23,13);
    printf(" ");
    gotoxy(23,14);
    printf(" ");
    while(1)
    {
        fun_Play();
    }
}
int fun_Play()/*游戏界面设置*/
{
    int x,y,i,j;
    char kw[]= "QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
    long AllCounter,RightCounter,WrongCounter;
    AllCounter=RightCounter=WrongCounter=0;
    unsigned int Timer;
    char ch;
    char cur;
    srand((unsigned)time(NULL));
    gotoxy(26,12);
    printf("                           ");
    gotoxy(26,13);
    printf("                           ");
    gotoxy(26,14);
    printf("                           ");
    y = 6;
    Timer = 200;
    i = rand()%3;
    j = rand()%(9-i);
    ch = kw[i];
    x = 10*(i+j);/*位置*/
    while(y<=24)
    {
       if(kbhit())
           {
            cur = getch();/*用户键入字母*/
            if(cur == ch || cur == ch+32) /*大小写字母转换*/
            {
                ch = '*';

                /*Timer = 200;*/
            }
            else if(cur == 27)
            {
                if(fun_Esc()==1)/*询问用户是否确认退出*/

                    system("cls");
                    exit(0);

            }
            else if( cur == '\r' )
            {
                gotoxy(x,y-1);
                printf(" ");
                /*gotoxy(26,12);
                printf("***************");
                gotoxy(26,13);
                printf("*Press any key to start!*");
                gotoxy(26,14);
                 printf("**********");*/
                 getch();
                 gotoxy(28,13);
                 printf(" ");
            }
            else
            {
                    WrongCounter++;
            }
            if(ch == '*')
          {
            RightCounter++;
          }
        AllCounter++;
        }
        if(y>6)
        {
            gotoxy(x,y-1);
            printf(" ");
        }

            gotoxy(x,y);
            printf("%c",ch);/*替换正确的打印字母*/
            gotoxy(0,1);
            printf("AllCh:%ld\nRight:%ld\nWrong:%ld",AllCounter,RightCounter,WrongCounter);
            Sleep(Timer);
            y++;

}
}
int fun_Esc()/*对退出游戏的判断*/
{
    char key;
    gotoxy(26,12);
    printf("**********");
    gotoxy(26,13);
    printf("*Are you sure to exit?(Y/N)*");
    gotoxy(26,14);
    printf("**********");
    gotoxy(54,13);
    scanf(" %c",&key);
    if(key == 'Y'||key == 'y')
        {
            return 1;
        }
        if(key == 'N'||key == 'n')
        {
            gotoxy(24,12);
            printf(" ");
            gotoxy(24,13);
            printf(" ");
            gotoxy(24,14);
            printf(" ");
            return 0;
        }
}
