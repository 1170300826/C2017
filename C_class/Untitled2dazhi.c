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

void Play()//������Ϸ ������������ĸ���Ϸ����£���Ļ��x����Ϊ����0-640���Զ���yΪһ���ԼӵĹ���
{

    cleardevice();//����


    char TarLetter; //Ŀ����ĸ
    char KeyLetter;
    int LetterX;
    int LetterY;

    int speed=1;
    int level=1;  //�����Ѷ�
    int score = 0;

    while (true)
    {
        setcolor(WHITE);
        setbkcolor(BLACK);//�������ѱ�����Ϊ��Ӧ��ɫ
        setbkmode(TRANSPARENT);//������ʽ ����TRANSPARENTΪ͸��
        //putimage(0, 0, 640, 480, &backimg, 0, 0, SRCCOPY);
        TarLetter = rand() % 26 + 65;//������ִ�д��ĸ  26����ĸ�����ȡ A ascll 65
        LetterX = rand() % 620;//���ڵ��趨��СΪ640����ֹ��ĸ�ܳ���Χ


        for (LetterY = 0; LetterY < 480; LetterY+=speed)//ͨ��letterY++�������ٶ�
        {
            cleardevice();//����  ����������һ����������Ϊѭ��һֱ���µ�
            outtextxy(500, 440, L"�˳��밴�س�");
            setbkmode(TRANSPARENT);//������ʽ ����TRANSPARENTΪ͸��
            //putimage(0, 0, 640, 480, &backimg, 0, 0, SRCCOPY);
            settextstyle(20, 0,L"����");
            outtextxy(LetterX, LetterY, TarLetter);//���ϰ�λ�����Ŀ����ĸ
            Sleep(20);//�����ʱ��һֱ��������������ֹ��ĸ����˸
            if (kbhit())//�ж��а����������ж�
            {
                KeyLetter = getch();//���հ�������
                if (KeyLetter == '\n'|| KeyLetter == '\r')//����ǻس����˳�ϵͳ
                {
                    char s[3];// = (char)score;
                    s[0]=score/10;
                    s[1] = score % 10;
                    settextstyle(30, 0, L"����");
                    outtextxy(220, 150, L"�÷�Ϊ ");
                    outtextxy(380, 150, s[0]);
                    outtextxy(385, 150, s[1]);
                    outtextxy(220, 200, L"�����˳���Ϸ");
                    Sleep(600);
                    exit(0);
                }
                else if(KeyLetter == TarLetter)
                {

                    putimage(LetterX, LetterY, 271, 81,&bamime,0,0,SRCCOPY);
                    Sleep(30);//�ṩͼƬ����ʱ��

                    score++;//������1��
                    level++;
                    if (level == 10) //ÿ����ʮ���� �ӿ���Ϸ�ٶ�
                    {
                        level = 0;
                        speed++;
                    }

                    break;//�˳�ѭ�� �����������ĸ
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

    setcolor(RED);//������ɫ
    setbkmode(TRANSPARENT);//������ʽ ����TRANSPARENTΪ͸��
    settextstyle(60, 0, L"���Ĳ���");//�����ʽ
    outtextxy(140, 50, L"������ϰϵͳ");//��ָ�������ӡ����

    setcolor(BLUE);
    settextstyle(20, 0, L"����");
    outtextxy(100, 200, L"��ѧ����������");
    outtextxy(100, 250, L"������ϰϵͳ");
    outtextxy(100, 300, L"�汾1.0");
    outtextxy(100, 350, L"�˳��밴�س�");

    int colorR = 255, colorG = 0;
    int speed = 5;
    while (!kbhit())   //kbhit ��ʾ���������
    {
        setcolor(RGB(colorR, colorG, 0));//RGB(RED, GREEN, BLUE)��ɫ���� ����3����
        outtextxy(260, 430, L"���ո����ʼ");
        colorR += speed;
        colorG -= speed;
        if (colorG > 255|| colorG < 0)
        {
            speed = -speed;//����ɫ
        }
        Sleep(20);//����������˸���ٶ�
    }

}

int main()
{
    SetConsoleTitle(L"������Ϸ��������Lee");
    srand((unsigned int)time(NULL));
    initgraph(640, 480);
    loadimage(&state, L"state", 640, 480);
    loadimage(&bamime, L"boom.jpg",271, 81);
    Welcome();

    Play();
    getchar();

    return 0;
}

