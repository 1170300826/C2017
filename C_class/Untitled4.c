#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

int main() {
    int x,y;
    gotoxy(2,2);
    printf("hello,world!");
    system("pause");
    return 0;
}
