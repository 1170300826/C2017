#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
void before_game();
void start_game(char *ch,int n);
void creat_word(int n);
/*
��Ϸ��ʼǰ��ʾ
*/
void before_game()
{
    printf("****************************************\n");
    printf("*����������޷��˳������������*��ʾ!*\n");
    printf("*���������ʼ���ԣ���������ĸ��ʼ��ʱ! *\n");
    printf("****************************************\n");
    creat_word(30);
}
/*
�������Ӣ����ĸ�ַ���
*/
void creat_word(int n)
{
    int num = n + 1;//��һ��\0�����ַ�
    size_t i;
    char *words = (char*)malloc(num);
    memset(words, 0, num);
    srand((unsigned int)time(NULL));//�������������
    for ( i = 0; i < n; i++)
    {
        char c = 'a' + rand() % 26;//���������ĸ
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
��ʼ��Ϸ
�ַ����²��ܻ��ˣ������*�滻
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
        printf("����ʱ��:%d��\n", end_time - start_time);
        printf("׼ȷ��Ϊ:%.2f%%\n", count*1.0 / n * 100);
        printf("�˳��밴Esc�������밴�����\n");
        str = getch();
        if (str == 27)//Esc��ASCIIΪ27 ���˳���Ϸ
        {
            break;
        }
        system("cls");
        before_game();//���¿�ʼ��Ϸ
        break;
    }
}

int main()
{
    before_game();
    return 0;
}
