#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
void before_game();
void start_game(char *ch,int n);
void creat_word(int n);
/*
游戏开始前提示
*/
void before_game()
{
    printf("****************************************\n");
    printf("*输入过程中无法退出，输入出错则按*表示!*\n");
    printf("*按任意键开始测试，按下首字母开始计时! *\n");
    printf("****************************************\n");
    creat_word(30);
}
/*
生成随机英文字母字符串
*/
void creat_word(int n)
{
    int num = n + 1;//多一个\0结束字符
    size_t i;
    char *words = (char*)malloc(num);
    memset(words, 0, num);
    srand((unsigned int)time(NULL));//设置随机数种子
    for ( i = 0; i < n; i++)
    {
        char c = 'a' + rand() % 26;//生成随机字母
        words[i] = c;
    }
    char str = getch();
    if(str)
    {
        system("cls");
    }
    puts(words);
    start_game(words,n);
    free(words);
}
/*
开始游戏
字符按下不能回退，打错用*替换
*/
void start_game(char *ch,int n)
{
    time_t start_time = 0;
    time_t end_time = 0;
    size_t i;
    while (1)
    {
        char str;
        int count = 0;
        for ( i = 0; i < n; i++)
        {
            str = getch();

            if (str == ch[i])
            {
                count++;
                printf("%c", str);
            }
            else
            {
                printf("*");
            }
            if (i == 0)
                start_time = time(NULL);
            if (i == n-1)
                end_time = time(NULL);

        }
        printf("\n");
        printf("打字时间:%d秒\n", end_time - start_time);
        printf("准确率为:%.2f%%\n", count*1.0 / n * 100);
        printf("退出请按Esc，继续请按任意键\n");
        str = getch();
        if (str == 27)//Esc的ASCII为27 ，退出游戏
        {
            break;
        }
        system("cls");
        before_game();//重新开始游戏
        break;
    }
}

int main()
{
    before_game();
    return 0;
}
