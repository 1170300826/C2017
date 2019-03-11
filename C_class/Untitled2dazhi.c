#include <stdio.h>
#include <graphics.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

IMAGE backimg;
IMAGE bamime;
IMAGE state;

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void Play()//进入游戏 ————有字母从上方落下，字幕的x坐标为坐标0-640（自定）y为一个自加的过程
{

    cleardevice();//清屏


    char TarLetter; //目标字母
    char KeyLetter;
    int LetterX;
    int LetterY;

    int speed=1;
    int level=1;  //定义难度
    int score = 0;

    while (true)
    {
        setcolor(WHITE);
        setbkcolor(BLACK);//清屏并把背景变为相应颜色
        setbkmode(TRANSPARENT);//背景格式 这里TRANSPARENT为透明
        //putimage(0, 0, 640, 480, &backimg, 0, 0, SRCCOPY);
        TarLetter = rand() % 26 + 65;//随机出现大写字母  26个字母中随机取 A ascll 65
        LetterX = rand() % 620;//现在的设定大小为640，防止字母跑出范围


        for (LetterY = 0; LetterY < 480; LetterY+=speed)//通过letterY++来控制速度
        {
            cleardevice();//清屏  否则看起来是一个线条，因为循环一直往下掉
            outtextxy(500, 440, L"退出请按回车");
            setbkmode(TRANSPARENT);//背景格式 这里TRANSPARENT为透明
            //putimage(0, 0, 640, 480, &backimg, 0, 0, SRCCOPY);
            settextstyle(20, 0,L"宋体");
            outtextxy(LetterX, LetterY, TarLetter);//不断按位置输出目标字母
            Sleep(20);//下落的时候一直清屏会闪动，防止字母的闪烁
            if (kbhit())//判断有按键按下则判断
            {
                KeyLetter = getch();//接收按盘输入
                if (KeyLetter == '\n'|| KeyLetter == '\r')//如果是回车就退出系统
                {
                    char s[3];// = (char)score;
                    s[0]=score/10;
                    s[1] = score % 10;
                    settextstyle(30, 0, L"黑体");
                    outtextxy(220, 150, L"得分为 ");
                    outtextxy(380, 150, s[0]);
                    outtextxy(385, 150, s[1]);
                    outtextxy(220, 200, L"即将退出游戏");
                    Sleep(600);
                    exit(0);
                }
                else if(KeyLetter == TarLetter)
                {

                    putimage(LetterX, LetterY, 271, 81,&bamime,0,0,SRCCOPY);
                    Sleep(30);//提供图片播放时间

                    score++;//分数加1；
                    level++;
                    if (level == 10) //每输入十个就 加快游戏速度
                    {
                        level = 0;
                        speed++;
                    }

                    break;//退出循环 再随机生成字母
                }
            }
        }
    }
    getch();
}

void Welcome()
{
    loadimage(&backimg, L"state.jpg", 640, 480);
    putimage(0, 0, 640, 480, &backimg, 0, 0, SRCCOPY);
    PlaySound(L"Maroon 5 - One More Night.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    setcolor(RED);//字体颜色
    setbkmode(TRANSPARENT);//背景格式 这里TRANSPARENT为透明
    settextstyle(60, 0, L"华文彩云");//字体格式
    outtextxy(140, 50, L"打字练习系统");//在指定坐标打印文字

    setcolor(BLUE);
    settextstyle(20, 0, L"宋体");
    outtextxy(100, 200, L"自学界面程序设计");
    outtextxy(100, 250, L"打字练习系统");
    outtextxy(100, 300, L"版本1.0");
    outtextxy(100, 350, L"退出请按回车");

    int colorR = 255, colorG = 0;
    int speed = 5;
    while (!kbhit())   //kbhit 表示接收任意键
    {
        setcolor(RGB(colorR, colorG, 0));//RGB(RED, GREEN, BLUE)颜色控制 设置3个数
        outtextxy(260, 430, L"按空格键开始");
        colorR += speed;
        colorG -= speed;
        if (colorG > 255|| colorG < 0)
        {
            speed = -speed;//当变色
        }
        Sleep(20);//控制字体闪烁的速度
    }

}

int main()
{
    SetConsoleTitle(L"打字游戏————Lee");
    srand((unsigned int)time(NULL));
    initgraph(640, 480);
    loadimage(&state, L"state", 640, 480);
    loadimage(&bamime, L"boom.jpg",271, 81);
    Welcome();

    Play();
    getchar();

    return 0;
}

